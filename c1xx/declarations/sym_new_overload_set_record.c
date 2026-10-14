c1_overload_set * __cdecl sym_new_overload_set_record(c1_keyed_list *list,fe_name *name,int arena)

{
  c1_u8 *pcVar1;
  c1_u32 cVar2;
  c1_overload_set *pcVar3;
  uint uVar4;
  c1_arena *a;
  c1_overload_set *pcVar5;
  uint *rec_words;
  
  if (arena == 0) {
    rec_words = g_symbol_free_lists[g_symbol_size_class_table[0x12]];
    if (rec_words != (uint *)0x0) {
      g_symbol_free_lists[g_symbol_size_class_table[0x12]] = (uint *)rec_words[1];
      pcVar3 = (c1_overload_set *)(rec_words + -2);
      *rec_words = 0;
      rec_words[1] = 0;
      cVar2 = g_symbol_size_table[0x12];
      pcVar5 = pcVar3;
      for (uVar4 = g_symbol_size_table[0x12] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        pcVar5->kind = '\0';
        pcVar5->flags1 = '\0';
        pcVar5->flags2 = '\0';
        pcVar5->flags3 = '\0';
        pcVar5 = (c1_overload_set *)pcVar5->pad04;
      }
      for (uVar4 = cVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        pcVar5->kind = '\0';
        pcVar5 = (c1_overload_set *)&pcVar5->flags1;
      }
      *rec_words = (uint)name;
      pcVar3->kind = pcVar3->kind & 0xf2 | 0x12;
      if (pcVar3 != (c1_overload_set *)0x0) goto LAB_1047249f;
    }
  }
  a = g_arenas + arena;
  uVar4 = g_symbol_size_table[0x12] + 3;
  pcVar3 = (c1_overload_set *)a->cur;
  pcVar1 = g_arenas[arena].end;
  a->cur = pcVar3->pad04 + ((uVar4 & 0xfffffffc) - 4);
  if (pcVar1 < pcVar3->pad04 + ((uVar4 & 0xfffffffc) - 4)) {
    arena_grow(a);
  }
  if (pcVar3 != (c1_overload_set *)0x0) {
    pcVar3->kind = pcVar3->kind & 0xf2 | 0x12;
    if (&pcVar3->name != (fe_name **)0x0) {
      pcVar3->next = (void *)0x0;
      pcVar3->name = name;
    }
    pcVar3->list = list;
    pcVar3->flags1 = pcVar3->flags1 | 8;
    return pcVar3;
  }
  pcVar3 = (c1_overload_set *)0x0;
LAB_1047249f:
  pcVar3->list = list;
  pcVar3->flags1 = pcVar3->flags1 | 8;
  return pcVar3;
}

