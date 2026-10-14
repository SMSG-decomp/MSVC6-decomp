void __cdecl static_ctor_il_pending_init_buffer(void)

{
  g_il_pending_init.open = '\x01';
  g_il_pending_init.bytes.start = (c1_u8 *)0x0;
  g_il_pending_init.bytes.cur = (c1_u8 *)0x0;
  g_il_pending_init.bytes.size = 0;
  g_il_pending_init.bytes.on_move = (c1_il_buffer_move_fn)0x0;
  g_il_pending_init.bytes.move_ctx = (void *)0x0;
  g_il_pending_init.file = (FILE *)0x0;
  g_il_pending_init.unk120 = -1;
  g_il_pending_init.name[0] = '\0';
  return;
}

