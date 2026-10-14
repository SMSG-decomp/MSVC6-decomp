c1_node * __cdecl expr_member_select_by_index(c1_node *src,uint flags)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  
  pcVar1 = expr_lvalue_address(src->right,flags);
  if (pcVar1 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar2 = tree_copy_to_arena(src,0);
  pcVar2->right = pcVar1;
  pcVar2->type = pcVar1->type;
  return pcVar2;
}

