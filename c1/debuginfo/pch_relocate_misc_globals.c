void __cdecl pch_relocate_misc_globals(void)

{
  c1_pushed_macro **ppcVar1;
  char cVar2;
  
  pch_relocate_symbol_chain(g_builtin_label_1);
  pch_relocate_symbol_chain(g_builtin_label_10);
  pch_relocate_symbol_chain(g_default_data_segment);
  pch_relocate_symbol_chain(g_default_code_segment);
  pch_relocate_symbol_chain(PTR_1065d5c8);
  pch_relocate_warning_state();
  ppcVar1 = g_pushed_macros;
  if (g_pushed_macros != (c1_pushed_macro **)0x0) {
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)g_pushed_macros);
    if (cVar2 != '\0') {
      pch_relocate_list_1b6c((int)*ppcVar1);
    }
    return;
  }
  return;
}

