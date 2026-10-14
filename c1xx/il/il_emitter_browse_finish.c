void __fastcall il_emitter_browse_finish(c1xx_il_emitter_browse *il_emitter_browse)

{
  c1xx_idb_vtbl *pcVar1;
  long size;
  int iVar2;
  
  if ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) {
    (*g_il_emitter->vtbl->abort)();
  }
  (*g_il_emitter->vtbl->flush)();
  if (g_emitter_region_mode == 2) {
    browse_emit_records(il_emitter_browse);
  }
  else {
    pcVar1 = g_idb->vtbl;
    size = ftell((FILE *)g_browse_sbr_file);
    (*pcVar1->idb_browse_set_size)(g_idb,size);
  }
  file_write_or_fatal(g_browse_sbr_file);
  iVar2 = fclose_if_open(g_browse_sbr_file);
  if (iVar2 != 0) {
    diag_fatal_file_errno(0x52,0x154,g_opt_Fr_browse);
  }
  return;
}

