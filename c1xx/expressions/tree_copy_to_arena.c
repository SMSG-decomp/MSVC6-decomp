c1_node * __cdecl tree_copy_to_arena(c1_node *src,int arena)

{
  void **ppvVar1;
  c1_u8 cVar2;
  ushort uVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_node *pcVar6;
  c1_u8 *pcVar7;
  c1_symbol *pcVar8;
  int *piVar9;
  int iVar10;
  c1_arena *pcVar11;
  uint uVar12;
  c1_node *pcVar13;
  int arena_00;
  c1_u8 *pcVar14;
  c1_node *pcVar15;
  
  arena_00 = arena;
  if (arena == 10) {
    pcVar11 = g_arenas + g_expr_arena_index;
    pcVar13 = (c1_node *)pcVar11->cur;
    pcVar6 = (c1_node *)g_arenas[g_expr_arena_index].end;
    pcVar11->cur = &pcVar13[1].op;
    if (pcVar6 < pcVar13 + 1) goto LAB_1047f2bf;
  }
  else {
    pcVar11 = g_arenas + arena;
    pcVar13 = (c1_node *)pcVar11->cur;
    pcVar6 = (c1_node *)g_arenas[arena].end;
    pcVar11->cur = &pcVar13[1].op;
    if (pcVar6 < pcVar13 + 1) {
LAB_1047f2bf:
      arena_grow(pcVar11);
    }
  }
  pcVar6 = src;
  pcVar15 = pcVar13;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    cVar2 = pcVar6->kind;
    cVar4 = pcVar6->flags;
    cVar5 = pcVar6->pad03;
    pcVar15->op = pcVar6->op;
    pcVar15->kind = cVar2;
    pcVar15->flags = cVar4;
    pcVar15->pad03 = cVar5;
    pcVar6 = (c1_node *)&pcVar6->type;
    pcVar15 = (c1_node *)&pcVar15->type;
  }
  switch(src->kind & 7) {
  case 1:
    pcVar6 = tree_copy_to_arena(src->left,arena_00);
    pcVar13->left = pcVar6;
    goto LAB_1041af72;
  case 2:
    if (src->left != (c1_node *)0x0) {
      pcVar6 = tree_copy_to_arena(src->left,arena_00);
      pcVar13->left = pcVar6;
      pcVar6->link = pcVar13;
    }
    if (src->right == (c1_node *)0x0) {
      return pcVar13;
    }
    pcVar6 = tree_copy_to_arena(src->right,arena_00);
    pcVar13->right = pcVar6;
    if ((g_token_class[pcVar6->op] == '`') && (g_token_class[pcVar13->op] != '`')) {
      tree_list_cache_tail(pcVar6);
      return pcVar13;
    }
LAB_1041af72:
    pcVar6->link = pcVar13;
    return pcVar13;
  case 3:
    if (((byte)pcVar13->type->code >> 5 & 1) != 0) {
      piVar9 = pcVar13->left;
      pcVar7 = record3_new(*piVar9,piVar9[1],piVar9[2],arena_00);
      pcVar13->left = pcVar7;
      return pcVar13;
    }
    break;
  case 4:
    if ((src->op == '\x06') && ((src->left->kind & 0x1f) == 0x12)) {
      if (arena_00 == 10) {
        arena_00 = g_expr_arena_index;
      }
      pcVar8 = sym_new_scoped_copy(src->left,arena_00);
      pcVar13->left = pcVar8;
      return pcVar13;
    }
    break;
  case 5:
    uVar3 = *(ushort *)&src->right;
    pcVar11 = g_arenas + arena_00;
    pcVar7 = pcVar11->cur;
    pcVar14 = g_arenas[arena_00].end;
    pcVar11->cur = pcVar7 + (uVar3 + 3 & 0xfffffffc);
    if (pcVar14 < pcVar7 + (uVar3 + 3 & 0xfffffffc)) {
      arena_grow(pcVar11);
    }
    pcVar13->left = pcVar7;
    uVar3 = *(ushort *)&src->right;
    pcVar14 = src->left;
    for (uVar12 = (uint)(uVar3 >> 2); uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar14;
      pcVar14 = pcVar14 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar12 = uVar3 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar7 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      pcVar7 = pcVar7 + 1;
    }
    return pcVar13;
  case 7:
    cVar2 = src->op;
    if (cVar2 == 0xb7) {
      ppvVar1 = &src->left;
      src = (c1_node *)0x0;
      pcVar6 = tree_copy_to_arena(*ppvVar1,arena_00);
      pcVar13->left = pcVar6;
      pcVar6->link = pcVar13;
      expr_collect_temporary_leaves((int *)&src,pcVar13->left);
      pcVar13->right = src;
      return pcVar13;
    }
    if (cVar2 == 0xc5) {
      ppvVar1 = &src->left;
      src = (c1_node *)0x0;
      pcVar6 = tree_copy_to_arena(*ppvVar1,arena_00);
      pcVar13->left = pcVar6;
      pcVar6->link = pcVar13;
      eh_collect_state_markers((int *)&src,pcVar13->left,'\x01');
      pcVar13->right = src;
      return pcVar13;
    }
    if ((cVar2 == 0xb5) || (cVar2 == 0xb6)) {
      pcVar6 = tree_copy_to_arena(src->left,arena_00);
      pcVar13->left = pcVar6;
      pcVar6->link = pcVar13;
      piVar9 = tree_copy_node_cell_list_list(src->right,arena_00);
      pcVar13->right = piVar9;
    }
  }
  return pcVar13;
}

