void __cdecl static_dtor_il_in_buffer(void)

{
  if (g_il_in.file != (FILE *)0x0) {
    fclose(g_il_in.file);
  }
  if (g_il_in.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_in.ilstore_stream_name);
  }
  if (g_il_in.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_in.bytes.pbStart);
    g_il_in.bytes.cbAlloc = 0;
  }
  return;
}

