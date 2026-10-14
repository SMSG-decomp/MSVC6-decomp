void __cdecl pch_relocate_misc_globals(void)

{
  int *piVar1;
  char cVar2;
  
  pch_relocate_tree(g_tree_zero_constant);
  pch_relocate_counted_slot_array(&g_void_parameter_list_record->count);
  pch_relocate_symbol_chain(g_crt_initializer_segment);
  pch_relocate_symbol_chain(&g_builtin_label_1->kind);
  pch_relocate_symbol_chain(&g_builtin_label_10->kind);
  pch_relocate_symbol_chain(g_default_data_segment);
  pch_relocate_symbol_chain(g_default_code_segment);
  pch_relocate_symbol_chain(g_default_segment_3);
  pch_relocate_warning_state();
  piVar1 = g_push_macro_stack;
  if (g_push_macro_stack != (int *)0x0) {
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)g_push_macro_stack);
    if (cVar2 != '\0') {
      pch_relocate_list_1b6c(*piVar1);
    }
    return;
  }
  return;
}

