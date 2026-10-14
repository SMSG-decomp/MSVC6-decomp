c1_symbol * __thiscall
sym_record_reuse_tail
          (int size_class,void **free_cell,void *name,char ambiguous,int *result,int arena_index)

{
  c1_u8 *pcVar1;
  c1_u32 cVar2;
  c1_arena *a;
  uint uVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  
  pcVar4 = (c1_symbol *)(free_cell + -2);
  g_symbol_free_lists[size_class] = free_cell[1];
  *free_cell = (void *)0x0;
  free_cell[1] = (void *)0x0;
  cVar2 = g_symbol_size_table[0x12];
  pcVar5 = pcVar4;
  for (uVar3 = g_symbol_size_table[0x12] >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar5->kind = '\0';
    pcVar5->flags1 = '\0';
    pcVar5->flags2 = '\0';
    pcVar5->flags3 = '\0';
    pcVar5 = (c1_symbol *)&pcVar5->flags4;
  }
  for (uVar3 = cVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar5->kind = '\0';
    pcVar5 = (c1_symbol *)&pcVar5->flags1;
  }
  *free_cell = name;
  pcVar4->kind = pcVar4->kind & 0xf2 | 0x12;
  if (pcVar4 == (c1_symbol *)0x0) {
    a = g_arenas + arena_index;
    uVar3 = g_symbol_size_table[0x12] + 3;
    pcVar4 = (c1_symbol *)a->cur;
    pcVar1 = g_arenas[arena_index].end;
    a->cur = &pcVar4->kind + (uVar3 & 0xfffffffc);
    if (pcVar1 < &pcVar4->kind + (uVar3 & 0xfffffffc)) {
      arena_grow(a);
    }
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4->kind = pcVar4->kind & 0xf2 | 0x12;
      if (&pcVar4->name != (fe_name **)0x0) {
        pcVar4->name = name;
        pcVar4->next = (c1_symbol *)0x0;
      }
    }
  }
  pcVar4->type = (c1_type *)result;
  if (ambiguous != '\0') {
    pcVar4->flags3 = pcVar4->flags3 | 4;
  }
  return pcVar4;
}

