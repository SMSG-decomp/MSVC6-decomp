void pp_undef_directive(void)

{
  fe_macro *pfVar1;
  
  (*g_idb->vtbl->idb_note_macro_change)(g_idb);
  if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
    pp_undef_macro_with_pch_check();
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

