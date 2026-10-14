void __fastcall il_emitter_browse_open(c1xx_il_emitter_browse *il_emitter_browse)

{
  g_browse_sbr_file = (FILE *)fopen(il_emitter_browse->sbr_name,"w+b");
  if (g_browse_sbr_file == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x154,il_emitter_browse->sbr_name);
  }
  setvbuf((FILE *)g_browse_sbr_file,(char *)0x0,0,0x1000);
  (*g_idb->vtbl->idb_invalidate)(g_idb);
  (*g_idb->vtbl->idb_browse_truncate)(g_idb);
  browse_add_record(0,(int *)0x0);
  (*il_emitter_browse->vtbl->begin_module)(il_emitter_browse);
  if ((g_pch_automatic != '\0') || (g_opt_pch_types_in_pdb != '\0')) {
    (*il_emitter_browse->vtbl->flush)();
    g_browse_sbr_header_end = ftell((FILE *)g_browse_sbr_file);
  }
  g_browse_id_module_byte = 1;
  g_emitter_region_mode = 1;
  return;
}

