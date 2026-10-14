c1_node * __cdecl expr_member_pointer_compare_dispatch(c1_node *node,void *builder)

{
  c1_node *pcVar1;
  
  if (node->op == ';') {
    pcVar1 = (c1_node *)(*builder)(node,0x3b,0x32,0x4f);
    return pcVar1;
  }
  if (node->op != 'L') {
    return (c1_node *)0x0;
  }
  pcVar1 = (c1_node *)(*builder)(node,0x4c,0x4f,0x32);
  return pcVar1;
}

