void __thiscall il_emitter_browse_pch_mark(c1_il_emitter_browse *emitter)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  c1_browse_record *pcVar4;
  c1_browse_record local_18;
  
  puVar3 = g_browse_record_zero;
  pcVar4 = &local_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *puVar3;
    pcVar4->kind = (char)uVar1;
    pcVar4->sub_kind = (char)(uVar1 >> 8);
    pcVar4->pad02 = (short)(uVar1 >> 0x10);
    puVar3 = puVar3 + 1;
    pcVar4 = (c1_browse_record *)&pcVar4->line;
  }
  local_18.kind = '\x10';
  browse_record_type(&local_18);
  g_browse_pch_mark_written = '\x01';
  return;
}

