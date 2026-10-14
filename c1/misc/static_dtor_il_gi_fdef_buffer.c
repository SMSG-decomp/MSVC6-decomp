void __cdecl static_dtor_il_gi_fdef_buffer(void)

{
  if (g_il_gi_fdef.file != (FILE *)0x0) {
    fclose(g_il_gi_fdef.file);
  }
  if (g_il_gi_fdef.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_gi_fdef.ilstore_stream_name);
  }
  if (g_il_gi_fdef.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_gi_fdef.bytes.pbStart);
    g_il_gi_fdef.bytes.cbAlloc = 0;
  }
  return;
}

