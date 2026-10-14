void __fastcall emit_section_flush(void *list)

{
  (*g_hook_enter_section_state)();
  if (g_opt_bzalign == 0) {
    coff_check_large_section_alignment(g_referenced_symbol_list);
  }
  writer_flush_pending();
  asm_print_symbol_directives();
  emit_symbol_list_records(list);
  asm_print_data_items(list);
  (*g_hook_leave_section_state)();
  return;
}

