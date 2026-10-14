uint32_t __fastcall coff_insert_comdat_section(c2_coff_section_out *sec)

{
  c2_coff_section_out *pcVar1;
  c2_coff_order_cell *cell;
  uint32_t uVar2;
  c2_coff_order_cell *free_cell;
  c2_coff_order_cell *prev;
  c2_coff_order *order;
  uint32_t key;
  
  order = g_coff_section_order;
  key = sec->symbol_index;
  if ((g_coff_incremental_update == 0) ||
     (prev = g_coff_section_order->head, prev == (c2_coff_order_cell *)0x0)) {
    cell = (*g_coff_alloc_fn)(8);
    order = g_coff_section_order;
    cell->sec = sec;
    prev = order->tail;
    if (prev != (c2_coff_order_cell *)0x0) goto LAB_10740b28;
    order->head = cell;
  }
  else {
    pcVar1 = g_coff_section_order->tail->sec;
    if ((pcVar1 == (c2_coff_section_out *)0x0) || (key <= pcVar1->symbol_index)) {
      if ((prev->sec == (c2_coff_section_out *)0x0) || (prev->sec->symbol_index <= key)) {
        free_cell = (c2_coff_order_cell *)
                    (~-(uint)(prev->sec != (c2_coff_section_out *)0x0) & (uint)prev);
        for (cell = prev->next; cell != (c2_coff_order_cell *)0x0; cell = cell->next) {
          if (cell->sec == (c2_coff_section_out *)0x0) {
            if (free_cell == (c2_coff_order_cell *)0x0) {
              free_cell = cell;
            }
          }
          else {
            if (key < cell->sec->symbol_index) break;
            free_cell = (c2_coff_order_cell *)0x0;
          }
          prev = prev->next;
        }
        if (free_cell == (c2_coff_order_cell *)0x0) {
          free_cell = (*g_coff_alloc_fn)(8);
          order = g_coff_section_order;
          free_cell->next = cell;
          free_cell->sec = sec;
          prev->next = free_cell;
        }
        else {
          free_cell->sec = sec;
        }
      }
      else {
        cell = (*g_coff_alloc_fn)(8);
        order = g_coff_section_order;
        cell->sec = sec;
        prev = order->head;
        order->head = cell;
        cell->next = prev;
      }
      goto LAB_10740b2d;
    }
    cell = (*g_coff_alloc_fn)(8);
    order = g_coff_section_order;
    cell->sec = sec;
    prev = order->tail;
LAB_10740b28:
    prev->next = cell;
  }
  order->tail = cell;
LAB_10740b2d:
  order->count = order->count + 1;
  uVar2 = order->inserted + 1;
  order->inserted = uVar2;
  return uVar2;
}

