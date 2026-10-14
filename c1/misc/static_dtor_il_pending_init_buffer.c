void __cdecl static_dtor_il_pending_init_buffer(void)

{
  if (g_il_pending_init.file != (FILE *)0x0) {
    fclose(g_il_pending_init.file);
  }
  if (g_il_pending_init.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_pending_init.ilstore_stream_name);
  }
  if (g_il_pending_init.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_pending_init.bytes.pbStart);
    g_il_pending_init.bytes.cbAlloc = 0;
  }
  return;
}

