void __fastcall asm_print_data_items(c2_list_cell *list)

{
  c2_init *rec;
  
  if (g_listing_on != 0) {
    for (; list != (c2_list_cell *)0x0; list = list->next) {
      rec = data_def_find_by_id(((list->u04).tuple)->switch_flags);
      asm_print_data_item(rec);
    }
  }
  return;
}

