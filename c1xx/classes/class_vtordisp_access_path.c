c1_keyed_cell * __cdecl class_vtordisp_access_path(c1_symbol *cls,c1_vbase_record *vbase)

{
  c1_vtable_record *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_u32 cVar6;
  c1_keyed_list *pcVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  uint uVar10;
  c1_arena *a;
  uint uVar11;
  int iVar12;
  c1_symbol *pcVar13;
  c1_symbol *pcVar14;
  uint *free_cell;
  
  pcVar1 = *vbase->vftables->data;
  tree_list_arena_set(5);
  pcVar7 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
  pcVar8 = pcVar1->via_base;
  while (pcVar8 != (c1_symbol *)0x0) {
    pcVar7 = tree_new_list_cell((c1_keyed_list *)0x0,(int)pcVar7->head,pcVar8);
    pcVar1 = pcVar1->outer;
    pcVar8 = pcVar1->via_base;
  }
  iVar12 = (-(uint)((g_compile_flags_c8 & 0x40000000) != 0) & 0xfffffffb) + 5;
  if ((iVar12 == 0) &&
     (free_cell = g_symbol_free_lists[g_symbol_size_class_table[10]], free_cell != (uint *)0x0)) {
    pcVar8 = (c1_symbol *)(free_cell + -2);
    g_symbol_free_lists[g_symbol_size_class_table[10]] = (uint *)free_cell[1];
    *free_cell = 0;
    free_cell[1] = 0;
    cVar6 = g_symbol_size_table[10];
    pcVar13 = pcVar8;
    for (uVar10 = g_symbol_size_table[10] >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      pcVar13->kind = '\0';
      pcVar13->flags1 = '\0';
      pcVar13->flags2 = '\0';
      pcVar13->flags3 = '\0';
      pcVar13 = (c1_symbol *)&pcVar13->flags4;
    }
    for (uVar10 = cVar6 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      pcVar13->kind = '\0';
      pcVar13 = (c1_symbol *)&pcVar13->flags1;
    }
    *free_cell = 0;
    pcVar8->kind = pcVar8->kind & 0xea | 10;
    if (pcVar8 != (c1_symbol *)0x0) goto LAB_104ae8bb;
  }
  a = g_arenas + iVar12;
  uVar10 = g_symbol_size_table[10] + 3;
  pcVar8 = (c1_symbol *)a->cur;
  pcVar2 = g_arenas[iVar12].end;
  a->cur = &pcVar8->kind + (uVar10 & 0xfffffffc);
  if (pcVar2 < &pcVar8->kind + (uVar10 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = sym_init_kind(pcVar8,'\n',(void *)0x0,iVar12);
  }
LAB_104ae8bb:
  uVar10 = g_symbol_size_table[pcVar1->vptr_member->kind & 0x1f];
  pcVar13 = pcVar1->vptr_member;
  pcVar14 = pcVar8;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    cVar3 = pcVar13->flags1;
    cVar4 = pcVar13->flags2;
    cVar5 = pcVar13->flags3;
    pcVar14->kind = pcVar13->kind;
    pcVar14->flags1 = cVar3;
    pcVar14->flags2 = cVar4;
    pcVar14->flags3 = cVar5;
    pcVar13 = (c1_symbol *)&pcVar13->flags4;
    pcVar14 = (c1_symbol *)&pcVar14->flags4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    pcVar14->kind = pcVar13->kind;
    pcVar13 = (c1_symbol *)&pcVar13->flags1;
    pcVar14 = (c1_symbol *)&pcVar14->flags1;
  }
  pcVar8->kind = pcVar8->kind & 0xdf;
  iVar12 = type_int_size();
  (pcVar8->detail).value = -iVar12;
  pcVar9 = type_int();
  pcVar8->type = pcVar9;
  pcVar7 = tree_new_list_cell((c1_keyed_list *)0x0,(int)pcVar7->head,pcVar8);
  tree_list_arena_restore();
  return pcVar7->head;
}

