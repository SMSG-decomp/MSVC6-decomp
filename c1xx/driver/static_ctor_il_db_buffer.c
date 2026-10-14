void __cdecl static_ctor_il_db_buffer(void)

{
  g_il_db.open = '\x01';
  g_il_db.bytes.start = (c1_u8 *)0x0;
  g_il_db.bytes.cur = (c1_u8 *)0x0;
  g_il_db.bytes.size = 0;
  g_il_db.bytes.on_move = (c1_il_buffer_move_fn)0x0;
  g_il_db.bytes.move_ctx = (void *)0x0;
  g_il_db.file = (FILE *)0x0;
  g_il_db.unk120 = -1;
  g_il_db.name[0] = '\0';
  return;
}

