void static_ctor_il_db_buffer(void)

{
  g_il_db.open = '\x01';
  g_il_db.bytes.pbStart = (PB)0x0;
  g_il_db.bytes.pbEnd = (PB)0x0;
  g_il_db.bytes.cbAlloc = 0;
  g_il_db.bytes.pfnMove = (_func_44 *)0x0;
  g_il_db.bytes.pfnMoveArg = (void *)0x0;
  g_il_db.file = (FILE *)0x0;
  g_il_db.unk120 = -1;
  g_il_db.name[0] = '\0';
  return;
}

