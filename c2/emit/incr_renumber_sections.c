void incr_renumber_sections(void)

{
  c2_incr_section_renumber *pcVar1;
  uint old_number;
  int new_number;
  c2_coff_order_cell *cell;
  int numbers_final;
  c2_coff_section_out *sec;
  
  pcVar1 = (*g_coff_alloc_fn)(g_coff_section_order->inserted << 3);
  numbers_final = g_coff_section_numbers_final;
  new_number = 1;
  g_incr_section_renumber_map = pcVar1;
  for (cell = g_coff_section_order->head; cell != (c2_coff_order_cell *)0x0; cell = cell->next) {
    sec = cell->sec;
    if (sec != (c2_coff_section_out *)0x0) {
      if (numbers_final == 0) {
        old_number = -(uint)sec->header_number - 2;
      }
      else {
        old_number = (uint)sec->header_number;
      }
      sec->header_number = (uint16_t)new_number;
      pcVar1[-3 - old_number].old_number = old_number;
      pcVar1[-3 - old_number].new_number = new_number;
      new_number = new_number + 1;
    }
  }
  return;
}

