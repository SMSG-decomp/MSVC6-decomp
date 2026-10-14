c1_node * __cdecl
tree_copy_replacing_temporary(c1_node *tree,int temp_key,c1_node *src,int eh_state)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  byte bVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_arena *a;
  int iVar7;
  c1_node *pcVar8;
  
  if ((tree->op == 0x9c) && (tree->left == (void *)temp_key)) {
    pcVar6 = tree_copy_to_arena(src,g_expr_arena_index);
    return pcVar6;
  }
  if ((tree->op == 0xc1) && (*(int *)((int)tree->left + 0x10) == eh_state)) {
    tree = *(c1_node **)((int)tree->right + 0x10);
  }
  a = g_arenas + g_expr_arena_index;
  pcVar6 = (c1_node *)a->cur;
  pcVar5 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar6[1].op;
  if (pcVar5 < pcVar6 + 1) {
    arena_grow(a);
  }
  pcVar5 = tree;
  pcVar8 = pcVar6;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    cVar1 = pcVar5->kind;
    cVar2 = pcVar5->flags;
    cVar3 = pcVar5->pad03;
    pcVar8->op = pcVar5->op;
    pcVar8->kind = cVar1;
    pcVar8->flags = cVar2;
    pcVar8->pad03 = cVar3;
    pcVar5 = (c1_node *)&pcVar5->type;
    pcVar8 = (c1_node *)&pcVar8->type;
  }
  bVar4 = tree->kind & 7;
  if (bVar4 == 2) {
    if (tree->left != (c1_node *)0x0) {
      pcVar5 = tree_copy_replacing_temporary(tree->left,temp_key,src,eh_state);
      pcVar6->left = pcVar5;
      pcVar5->link = pcVar6;
    }
    if (tree->right == (c1_node *)0x0) {
      return pcVar6;
    }
    pcVar5 = tree_copy_replacing_temporary(tree->right,temp_key,src,eh_state);
    pcVar6->right = pcVar5;
    if ((g_token_class[pcVar5->op] == '`') && (g_token_class[pcVar6->op] != '`')) {
      tree_list_cache_tail(pcVar5);
      return pcVar6;
    }
  }
  else {
    if (bVar4 != 1) {
      return pcVar6;
    }
    pcVar5 = tree_copy_replacing_temporary(tree->left,temp_key,src,eh_state);
    pcVar6->left = pcVar5;
  }
  pcVar5->link = pcVar6;
  return pcVar6;
}

