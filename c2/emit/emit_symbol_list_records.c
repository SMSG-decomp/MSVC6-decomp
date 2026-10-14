void __fastcall emit_symbol_list_records(c2_list_cell *list)

{
  if (g_opt_object_path != (char *)0x0) {
    for (; list != (c2_list_cell *)0x0; list = list->next) {
      init_record_assign_offsets(*(c2_init **)((int)&((list->u04).sym)->u30 + 2));
    }
  }
  return;
}

