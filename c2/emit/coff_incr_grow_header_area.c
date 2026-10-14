void __fastcall coff_incr_grow_header_area(int extra_bytes)

{
  c2_coff_section_out *pcVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  c2_coff_slot **slot_cursor;
  size_t _Size;
  uint uVar6;
  c2_coff_slot **aux_cursor;
  c2_coff_order_cell *cell;
  c2_coff_free_range *range;
  
  iVar3 = fseek(g_coff_object_file,g_coff_incr_data_start,0);
  if (iVar3 != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1570);
  }
  _Size = g_coff_data_end - g_coff_incr_data_start;
  pvVar4 = malloc(_Size);
  if (pvVar4 == (void *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x1577);
  }
  sVar5 = fread(pvVar4,1,_Size,g_coff_object_file);
  if (sVar5 != _Size) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x157a);
  }
  iVar3 = fseek(g_coff_object_file,g_coff_incr_data_start + extra_bytes,0);
  if (iVar3 != 0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x157d);
  }
  fwrite(pvVar4,1,_Size,g_coff_object_file);
  free(pvVar4);
  g_coff_data_end = g_coff_data_end + extra_bytes;
  slot_cursor = g_coff_symbol_slots;
  uVar2 = g_coff_symbol_slot_count;
  for (cell = g_coff_section_order->head; g_coff_symbol_slots = slot_cursor,
      g_coff_symbol_slot_count = uVar2, cell != (c2_coff_order_cell *)0x0; cell = cell->next) {
    pcVar1 = cell->sec;
    if ((pcVar1 != (c2_coff_section_out *)0x0) && (pcVar1->data_offset != 0)) {
      pcVar1->data_offset = pcVar1->data_offset + extra_bytes;
      if (pcVar1->reloc_offset != 0) {
        pcVar1->reloc_offset = pcVar1->reloc_offset + extra_bytes;
      }
      if (pcVar1->line_offset != 0) {
        pcVar1->line_offset = pcVar1->line_offset + extra_bytes;
      }
    }
    slot_cursor = g_coff_symbol_slots;
    uVar2 = g_coff_symbol_slot_count;
  }
  uVar6 = 0;
  range = g_coff_free_ranges;
  if (uVar2 != 0) {
    do {
      if ((((*slot_cursor)->kind == 3) &&
          (pvVar4 = (*slot_cursor)->payload, *(char *)((int)pvVar4 + 0x11) == '\x01')) &&
         ((*(byte *)((int)pvVar4 + 0xe) & 0x30) == 0x20)) {
        aux_cursor = slot_cursor + 1;
        slot_cursor = slot_cursor + 1;
        uVar6 = uVar6 + 1;
        iVar3 = *(int *)((int)(*aux_cursor)->payload + 8);
        if (iVar3 != 0) {
          *(int *)((int)(*aux_cursor)->payload + 8) = iVar3 + extra_bytes;
        }
      }
      uVar6 = uVar6 + 1;
      slot_cursor = slot_cursor + 1;
      range = g_coff_free_ranges;
    } while (uVar6 < uVar2);
  }
  for (; range != (c2_coff_free_range *)0x0; range = range->next) {
    range->start = range->start + extra_bytes;
  }
  return;
}

