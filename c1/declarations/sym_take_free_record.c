c1_symbol * __cdecl sym_take_free_record(byte kind,void *name,int arena)

{
  c1_symbol *pcVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  c1_symbol *pcVar5;
  
  if (arena != 0) {
    return (c1_symbol *)0x0;
  }
  puVar2 = g_symbol_free_lists[g_symbol_size_class_table[kind]];
  if (puVar2 == (uint *)0x0) {
    return (c1_symbol *)0x0;
  }
  g_symbol_free_lists[g_symbol_size_class_table[kind]] = (uint *)puVar2[1];
  pcVar1 = (c1_symbol *)(puVar2 + -2);
  *puVar2 = 0;
  puVar2[1] = 0;
  uVar4 = g_symbol_size_table[kind];
  pcVar5 = pcVar1;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar5->kind = '\0';
    pcVar5->flags1 = '\0';
    pcVar5->flags2 = '\0';
    pcVar5->flags3 = '\0';
    pcVar5 = (c1_symbol *)&pcVar5->flags4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar5->kind = '\0';
    pcVar5 = (c1_symbol *)&pcVar5->flags1;
  }
  *puVar2 = (uint)name;
  pcVar1->kind = (pcVar1->kind ^ kind) & 0x1f ^ pcVar1->kind;
  return pcVar1;
}

