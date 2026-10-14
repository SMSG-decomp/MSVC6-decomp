int __cdecl expr_is_reusable_lvalue(c1_node *node)

{
  char cVar1;
  c1_node *pcVar2;
  void *visitor_vptr;
  uint visitor_mask;
  
  if (node->op == '7') {
    node = node->right;
  }
  if (node->op == '=') {
    visitor_mask = 0xff;
    visitor_vptr = &g_side_effect_visitor_vtable;
    cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor_vptr,node);
    if (cVar1 == '\0') {
      pcVar2 = expr_lvalue_address(node,0);
      if (pcVar2 != (c1_node *)0x0) {
        return 1;
      }
    }
  }
  return 0;
}

