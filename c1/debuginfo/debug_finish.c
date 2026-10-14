void __fastcall debug_finish(void)

{
  if (g_opt_Zi != '\0') {
    il_emit_debug_record(7);
  }
  if (g_debug_types_in_pdb != '\0') {
    pdb_session_close_types(&g_pdb);
  }
  mem_free(g_debug_record_buffer);
  g_cv_record_body = (ushort *)0x0;
  g_debug_record_buffer = (ushort *)0x0;
  return;
}

