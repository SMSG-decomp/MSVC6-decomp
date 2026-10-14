void __cdecl pp_undef_macro_with_pch_check(void)

{
  fe_macro *a;
  int iVar1;
  
  iVar1 = pch_record_entry(10,0,g_last_name->text);
  if (iVar1 == 2) {
    if (g_pch_directive_mode == 2) {
      return;
    }
  }
  else if (iVar1 == 1) {
    return;
  }
  if (g_last_name != g_name_defined) {
    a = g_last_name->macro;
    if (a != (fe_macro *)0x0) {
      if (a->def->kind < -3) {
        diag_warning(1,0x75,g_last_name,"#undef");
      }
      g_last_name->macro = (fe_macro *)0x0;
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->reference_macro)((int)a);
      }
    }
    return;
  }
  diag_warning(1,0x75,g_last_name,"#undef");
  return;
}

