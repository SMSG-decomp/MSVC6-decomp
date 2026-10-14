void __cdecl static_dtor_il_gi_buffer(void)

{
  if (g_il_gi_buffer.file != (FILE *)0x0) {
    fclose(g_il_gi_buffer.file);
  }
  if (g_il_gi_buffer.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_gi_buffer.ilstore_stream_name);
  }
  if (g_il_gi_buffer.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_gi_buffer.bytes.pbStart);
    g_il_gi_buffer.bytes.cbAlloc = 0;
  }
  return;
}

