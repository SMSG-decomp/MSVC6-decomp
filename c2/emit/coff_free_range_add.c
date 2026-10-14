void __fastcall coff_free_range_add(uint32_t start,int size)

{
  int iVar1;
  int iVar2;
  c2_coff_free_range *next_range;
  c2_coff_free_range *new_range;
  c2_coff_free_range *prev;
  
  next_range = g_coff_free_ranges;
  if (g_coff_free_ranges == (c2_coff_free_range *)0x0) {
    g_coff_free_ranges = (*g_coff_alloc_fn)(0xc);
    g_coff_free_ranges->start = start;
    g_coff_free_ranges->size = size;
    return;
  }
  if (start < g_coff_free_ranges->start) {
    if (start + size != g_coff_free_ranges->start) {
      next_range = (*g_coff_alloc_fn)(0xc);
      next_range->size = size;
      next_range->start = start;
      next_range->next = g_coff_free_ranges;
      g_coff_free_ranges = next_range;
      return;
    }
    g_coff_free_ranges->start = start;
    next_range->size = next_range->size + size;
    return;
  }
  next_range = g_coff_free_ranges->next;
  prev = g_coff_free_ranges;
  do {
    if (next_range == (c2_coff_free_range *)0x0) {
LAB_10782af5:
      if (prev->start + prev->size != start) {
        next_range = (*g_coff_alloc_fn)(0xc);
        prev->next = next_range;
        next_range->size = size;
        next_range->start = start;
        next_range->next = (c2_coff_free_range *)0x0;
        return;
      }
      prev->size = prev->size + size;
      return;
    }
    if (start < next_range->start) {
      if (next_range != (c2_coff_free_range *)0x0) {
        iVar1 = prev->size;
        if (start + size != next_range->start) {
          if (prev->start + iVar1 != start) {
            new_range = (*g_coff_alloc_fn)(0xc);
            prev->next = new_range;
            new_range->next = next_range;
            new_range->size = size;
            new_range->start = start;
            return;
          }
          prev->size = iVar1 + size;
          return;
        }
        if (prev->start + iVar1 != start) {
          next_range->start = start;
          next_range->size = next_range->size + size;
          return;
        }
        iVar2 = next_range->size;
        prev->next = next_range->next;
        prev->size = iVar2 + iVar1 + size;
        return;
      }
      goto LAB_10782af5;
    }
    next_range = next_range->next;
    prev = prev->next;
  } while( true );
}

