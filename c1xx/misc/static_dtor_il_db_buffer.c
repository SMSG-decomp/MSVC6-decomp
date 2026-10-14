void __cdecl static_dtor_il_db_buffer(void)

{
  if (g_il_db.file != (FILE *)0x0) {
    fclose((FILE *)g_il_db.file);
  }
  if (g_il_db.ilstore_stream_name != (char *)0x0) {
    mem_free(g_il_db.ilstore_stream_name);
  }
  if (g_il_db.bytes.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(g_il_db.bytes.start);
    g_il_db.bytes.size = 0;
  }
  return;
}

