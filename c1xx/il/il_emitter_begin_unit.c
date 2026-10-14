void __cdecl il_emitter_begin_unit(void)

{
  uint uVar1;
  int iVar2;
  uint *src;
  c1xx_browse_record *pcVar3;
  c1xx_browse_record local_18;
  
  src = g_browse_record_zero;
  pcVar3 = &local_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *src;
    pcVar3->kind = (char)uVar1;
    pcVar3->flags = (char)(uVar1 >> 8);
    pcVar3->type = (char)(uVar1 >> 0x10);
    pcVar3->pad03 = (char)(uVar1 >> 0x18);
    src = src + 1;
    pcVar3 = (c1xx_browse_record *)&pcVar3->line;
  }
  if (g_browse_suspended == 0) {
    (*g_il_emitter->vtbl->flush)();
    local_18.kind = '\x0e';
    browse_record_type(&local_18);
    g_browse_suspended = 1;
  }
  return;
}

