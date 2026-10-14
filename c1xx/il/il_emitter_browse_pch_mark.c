void __cdecl il_emitter_browse_pch_mark(void)

{
  uint uVar1;
  int iVar2;
  uint *src;
  c1xx_browse_record *pcVar3;
  c1xx_browse_record cStack_18;
  
  src = g_browse_record_zero;
  pcVar3 = &cStack_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *src;
    pcVar3->kind = (char)uVar1;
    pcVar3->flags = (char)(uVar1 >> 8);
    pcVar3->type = (char)(uVar1 >> 0x10);
    pcVar3->pad03 = (char)(uVar1 >> 0x18);
    src = src + 1;
    pcVar3 = (c1xx_browse_record *)&pcVar3->line;
  }
  browse_flush_queue();
  cStack_18.kind = '\x10';
  browse_record_type(&cStack_18);
  g_browse_pch_marked = '\x01';
  return;
}

