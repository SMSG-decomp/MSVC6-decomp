c1_symbol * __cdecl sym_take_free_record(byte kind,void *name,int arena)

{
  c1_symbol *pcVar1;
  uint uVar2;
  uint uVar3;
  c1_symbol *pcVar4;
  uint *rec_words;
  
  if (arena != 0) {
    return (c1_symbol *)0x0;
  }
  rec_words = g_symbol_free_lists[g_symbol_size_class_table[kind]];
  if (rec_words == (uint *)0x0) {
    return (c1_symbol *)0x0;
  }
  g_symbol_free_lists[g_symbol_size_class_table[kind]] = (uint *)rec_words[1];
  pcVar1 = (c1_symbol *)(rec_words + -2);
  *rec_words = 0;
  rec_words[1] = 0;
  uVar3 = g_symbol_size_table[kind];
  pcVar4 = pcVar1;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    pcVar4->kind = '\0';
    pcVar4->flags1 = '\0';
    pcVar4->flags2 = '\0';
    pcVar4->flags3 = '\0';
    pcVar4 = (c1_symbol *)&pcVar4->flags4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar4->kind = '\0';
    pcVar4 = (c1_symbol *)&pcVar4->flags1;
  }
  *rec_words = (uint)name;
  pcVar1->kind = (pcVar1->kind ^ kind) & 0x1f ^ pcVar1->kind;
  return pcVar1;
}

