c1_node * __cdecl init_member_select_by_index(c1_node *src,uint mode)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  
  pcVar1 = expr_lvalue_address(*(c1_node **)((int)src->right + 0x10),mode);
  if (pcVar1 != (c1_node *)0x0) {
    pcVar2 = tree_copy_to_arena(src,g_expr_arena_index);
    *(c1_node **)((int)pcVar2->right + 0x10) = pcVar1;
    *(c1_type **)((int)pcVar2->right + 4) = pcVar1->type;
    pcVar2->type = pcVar1->type;
    return pcVar2;
  }
  return (c1_node *)0x0;
}

