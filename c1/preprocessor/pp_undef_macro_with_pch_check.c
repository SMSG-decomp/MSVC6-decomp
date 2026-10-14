void pp_undef_macro_with_pch_check(void)

{
  fe_macro *pfVar1;
  int iVar2;
  
  iVar2 = pch_record_entry(10,0,g_last_name->text);
  if (iVar2 == 2) {
    if (g_pch_directive_mode == 2) {
      return;
    }
  }
  else if (iVar2 == 1) {
    return;
  }
  if (g_last_name != g_name_defined) {
    pfVar1 = g_last_name->macro;
    if (pfVar1 != (fe_macro *)0x0) {
      if (pfVar1->def->kind < -3) {
        diag_warning(1,0x75,g_last_name,"#undef");
      }
      g_last_name->macro = (fe_macro *)0x0;
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->reference_macro)(pfVar1);
      }
    }
    return;
  }
  diag_warning(1,0x75,g_last_name,"#undef");
  return;
}

