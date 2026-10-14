void static_ctor_il_pending_init_buffer(void)

{
  g_il_pending_init.open = '\x01';
  g_il_pending_init.bytes.pbStart = (PB)0x0;
  g_il_pending_init.bytes.pbEnd = (PB)0x0;
  g_il_pending_init.bytes.cbAlloc = 0;
  g_il_pending_init.bytes.pfnMove = (_func_44 *)0x0;
  g_il_pending_init.bytes.pfnMoveArg = (void *)0x0;
  g_il_pending_init.file = (FILE *)0x0;
  g_il_pending_init.unk120 = -1;
  g_il_pending_init.name[0] = '\0';
  return;
}

