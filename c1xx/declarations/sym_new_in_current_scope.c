c1_symbol * __cdecl sym_new_in_current_scope(void)

{
  c1_type *pcVar1;
  c1_u8 *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  void *name;
  c1_u32 cVar5;
  c1_symbol *pcVar6;
  c1_arena *pcVar7;
  uint uVar8;
  int unused;
  c1_symbol *pcVar9;
  int *free_cell;
  
  name = g_name_abstract_declarator;
  if (((g_compile_flags_c8 & 0x10000000) == 0) && (((byte)g_compile_flags_cc & 0x48) == 0)) {
    if (g_prototype_scope_depth < 1) {
      unused = 5;
    }
    else {
      unused = (g_class_depth < 0) + 3;
    }
  }
  else {
    unused = 0;
  }
  if ((unused == 0) &&
     (free_cell = (int *)g_symbol_free_lists[g_symbol_size_class_table[0xd]],
     free_cell != (int *)0x0)) {
    g_symbol_free_lists[g_symbol_size_class_table[0xd]] = (uint *)free_cell[1];
    pcVar6 = (c1_symbol *)(free_cell + -2);
    *free_cell = 0;
    free_cell[1] = 0;
    cVar5 = g_symbol_size_table[0xd];
    pcVar9 = pcVar6;
    for (uVar8 = g_symbol_size_table[0xd] >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
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
    *free_cell = (int)name;
    pcVar6->kind = pcVar6->kind & 0xed | 0xd;
    if (pcVar6 != (c1_symbol *)0x0) goto LAB_1043f415;
  }
  pcVar7 = g_arenas + unused;
  uVar8 = g_symbol_size_table[0xd] + 3;
  pcVar6 = (c1_symbol *)pcVar7->cur;
  pcVar2 = g_arenas[unused].end;
  pcVar7->cur = &pcVar6->kind + (uVar8 & 0xfffffffc);
  if (pcVar2 < &pcVar6->kind + (uVar8 & 0xfffffffc)) {
    arena_grow(pcVar7);
  }
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6 = sym_init_kind(pcVar6,'\r',name,unused);
  }
LAB_1043f415:
  pcVar7 = g_arenas + unused;
  pcVar3 = (c1_type *)pcVar7->cur;
  pcVar4 = (c1_type *)g_arenas[unused].end;
  pcVar1 = pcVar3 + 1;
  pcVar7->cur = (c1_u8 *)pcVar1;
  if (pcVar4 < pcVar1) {
    arena_grow(pcVar7);
  }
  pcVar6->type = pcVar3;
  return pcVar6;
}

