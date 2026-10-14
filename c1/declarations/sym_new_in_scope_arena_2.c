c1_symbol * __cdecl sym_new_in_scope_arena_2(void *name)

{
  c1_type *pcVar1;
  uint *puVar2;
  uchar *puVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  uint uVar7;
  uint uVar8;
  fe_arena *pfVar9;
  uint unused;
  c1_symbol *pcVar10;
  
  unused = -(uint)(g_block_depth != '\0') & 2;
  if (unused == 0) {
    puVar2 = g_symbol_free_lists[g_symbol_size_class_table[1]];
    if (puVar2 != (uint *)0x0) {
      g_symbol_free_lists[g_symbol_size_class_table[1]] = (uint *)puVar2[1];
      pcVar6 = (c1_symbol *)(puVar2 + -2);
      *puVar2 = 0;
      puVar2[1] = 0;
      uVar8 = g_symbol_size_table[1];
      pcVar10 = pcVar6;
      for (uVar7 = g_symbol_size_table[1] >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        pcVar10->kind = '\0';
        pcVar10->flags1 = '\0';
        pcVar10->flags2 = '\0';
        pcVar10->flags3 = '\0';
        pcVar10 = (c1_symbol *)&pcVar10->flags4;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        pcVar10->kind = '\0';
        pcVar10 = (c1_symbol *)&pcVar10->flags1;
      }
      *puVar2 = (uint)name;
      pcVar6->kind = pcVar6->kind & 0xe1 | 1;
      if (pcVar6 != (c1_symbol *)0x0) goto LAB_10634cc1;
    }
  }
  pfVar9 = g_arenas + unused;
  uVar8 = g_symbol_size_table[1] + 3;
  pcVar6 = (c1_symbol *)pfVar9->cur;
  puVar3 = g_arenas[unused].end;
  pfVar9->cur = &pcVar6->kind + (uVar8 & 0xfffffffc);
  if (puVar3 < &pcVar6->kind + (uVar8 & 0xfffffffc)) {
    arena_grow(pfVar9);
  }
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6 = sym_init_kind(pcVar6,'\x01',name,unused);
  }
LAB_10634cc1:
  pfVar9 = g_arenas + g_context_arena_index;
  pcVar4 = (c1_type *)pfVar9->cur;
  pcVar5 = (c1_type *)g_arenas[g_context_arena_index].end;
  pcVar1 = pcVar4 + 1;
  pfVar9->cur = (uchar *)pcVar1;
  if (pcVar5 < pcVar1) {
    arena_grow(pfVar9);
  }
  pcVar6->type = pcVar4;
  return pcVar6;
}

