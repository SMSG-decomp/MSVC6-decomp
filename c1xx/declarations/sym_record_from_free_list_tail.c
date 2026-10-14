c1_symbol * __cdecl
sym_record_from_free_list_tail(int size_class,int arena_index,void **free_cell,void *name)

{
  c1_type *pcVar1;
  c1_u8 *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  c1_u32 cVar5;
  c1_symbol *pcVar6;
  c1_arena *pcVar7;
  uint uVar8;
  c1_symbol *pcVar9;
  
  g_symbol_free_lists[size_class] = free_cell[1];
  pcVar6 = (c1_symbol *)(free_cell + -2);
  *free_cell = (void *)0x0;
  free_cell[1] = (void *)0x0;
  cVar5 = g_symbol_size_table[1];
  pcVar9 = pcVar6;
  for (uVar8 = g_symbol_size_table[1] >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    pcVar9->kind = '\0';
    pcVar9->flags1 = '\0';
    pcVar9->flags2 = '\0';
    pcVar9->flags3 = '\0';
    pcVar9 = (c1_symbol *)&pcVar9->flags4;
  }
  for (uVar8 = cVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    pcVar9->kind = '\0';
    pcVar9 = (c1_symbol *)&pcVar9->flags1;
  }
  *free_cell = name;
  pcVar6->kind = pcVar6->kind & 0xe1 | 1;
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar7 = g_arenas + arena_index;
    uVar8 = g_symbol_size_table[1] + 3;
    pcVar6 = (c1_symbol *)pcVar7->cur;
    pcVar2 = g_arenas[arena_index].end;
    pcVar7->cur = &pcVar6->kind + (uVar8 & 0xfffffffc);
    if (pcVar2 < &pcVar6->kind + (uVar8 & 0xfffffffc)) {
      arena_grow(pcVar7);
    }
    if (pcVar6 == (c1_symbol *)0x0) {
      pcVar6 = (c1_symbol *)0x0;
    }
    else {
      pcVar6 = sym_init_kind(pcVar6,'\x01',name,arena_index);
    }
  }
  pcVar7 = g_arenas + g_context_arena_index;
  pcVar3 = (c1_type *)pcVar7->cur;
  pcVar4 = (c1_type *)g_arenas[g_context_arena_index].end;
  pcVar1 = pcVar3 + 1;
  pcVar7->cur = (c1_u8 *)pcVar1;
  if (pcVar4 < pcVar1) {
    arena_grow(pcVar7);
  }
  pcVar6->type = pcVar3;
  (pcVar6->tail).fn.op_token = '\x01';
  return pcVar6;
}

