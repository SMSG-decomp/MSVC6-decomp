void __cdecl static_dtor_il_db_buffer(void)

{
  if (g_il_db.file != (FILE *)0x0) {
    fclose(g_il_db.file);
  }
  if (g_il_db.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_db.ilstore_stream_name);
  }
  if (g_il_db.bytes.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(g_il_db.bytes.pbStart);
    g_il_db.bytes.cbAlloc = 0;
  }
  return;
}

