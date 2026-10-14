void __thiscall il_emitter_browse_pch_name(c1_il_emitter_browse *emitter,char *pch_name)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  c1_browse_record *pcVar4;
  c1_browse_record cStack_18;
  
  puVar3 = g_browse_record_zero;
  pcVar4 = &cStack_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *puVar3;
    pcVar4->kind = (char)uVar1;
    pcVar4->sub_kind = (char)(uVar1 >> 8);
    pcVar4->pad02 = (short)(uVar1 >> 0x10);
    puVar3 = puVar3 + 1;
    pcVar4 = (c1_browse_record *)&pcVar4->line;
  }
  cStack_18.kind = '\x0f';
  cStack_18.name = mem_xstrdup(pch_name);
  browse_record_type(&cStack_18);
  return;
}

