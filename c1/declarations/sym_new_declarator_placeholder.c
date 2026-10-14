c1_symbol * __cdecl sym_new_declarator_placeholder(void)

{
  c1_type *pcVar1;
  uchar *puVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  uint *puVar5;
  void *name;
  c1_symbol *pcVar6;
  fe_arena *pfVar7;
  uint uVar8;
  uint uVar9;
  int unused;
  c1_symbol *pcVar10;
  
  name = g_name_abstract_declarator;
  unused = (g_prototype_scope_depth < 1) + 2;
  if ((unused == 0) &&
     (puVar5 = g_symbol_free_lists[g_symbol_size_class_table[0xd]], puVar5 != (uint *)0x0)) {
    g_symbol_free_lists[g_symbol_size_class_table[0xd]] = (uint *)puVar5[1];
    pcVar6 = (c1_symbol *)(puVar5 + -2);
    *puVar5 = 0;
    puVar5[1] = 0;
    uVar9 = g_symbol_size_table[0xd];
    pcVar10 = pcVar6;
    for (uVar8 = g_symbol_size_table[0xd] >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      pcVar10->kind = '\0';
      pcVar10->flags1 = '\0';
      pcVar10->flags2 = '\0';
      pcVar10->flags3 = '\0';
      pcVar10 = (c1_symbol *)&pcVar10->flags4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      pcVar10->kind = '\0';
      pcVar10 = (c1_symbol *)&pcVar10->flags1;
    }
    *puVar5 = (uint)name;
    pcVar6->kind = pcVar6->kind & 0xed | 0xd;
    if (pcVar6 != (c1_symbol *)0x0) goto LAB_10615531;
  }
  pfVar7 = g_arenas + unused;
  uVar9 = g_symbol_size_table[0xd] + 3;
  pcVar6 = (c1_symbol *)pfVar7->cur;
  puVar2 = g_arenas[unused].end;
  pfVar7->cur = &pcVar6->kind + (uVar9 & 0xfffffffc);
  if (puVar2 < &pcVar6->kind + (uVar9 & 0xfffffffc)) {
    arena_grow(pfVar7);
  }
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6 = sym_init_kind(pcVar6,'\r',name,unused);
  }
LAB_10615531:
  pfVar7 = g_arenas + unused;
  pcVar3 = (c1_type *)pfVar7->cur;
  pcVar4 = (c1_type *)g_arenas[unused].end;
  pcVar1 = pcVar3 + 1;
  pfVar7->cur = (uchar *)pcVar1;
  if (pcVar4 < pcVar1) {
    arena_grow(pfVar7);
  }
  pcVar6->type = pcVar3;
  return pcVar6;
}

