void __cdecl static_dtor_il_ex_buffer(void)

{
  if (g_il_ex.file != (FILE *)0x0) {
    fclose(g_il_ex.file);
  }
  if (g_il_ex.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_ex.ilstore_stream_name);
  }
  if (g_il_ex.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_ex.bytes.pbStart);
    g_il_ex.bytes.cbAlloc = 0;
  }
  return;
}

