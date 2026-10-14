void __fastcall coff_list_remove_value(c2_coff_section_out *sec)

{
  c2_coff_order_cell *cell;
  c2_coff_order *order;
  
  order = g_coff_section_order;
  for (cell = g_coff_section_order->head; (cell != (c2_coff_order_cell *)0x0 && (cell->sec != sec));
      cell = cell->next) {
  }
  cell->sec = (c2_coff_section_out *)0x0;
  order->count = order->count - 1;
  return;
}

