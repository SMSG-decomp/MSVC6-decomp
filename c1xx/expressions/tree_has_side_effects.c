char __thiscall tree_has_side_effects(c1_tree_visitor *visitor,c1_node *node)

{
  char cVar1;
  
  while (node != (c1_node *)0x0) {
    if (((visitor->kind_mask & g_node_kind_bits[node->kind & 7]) != 0) &&
       (cVar1 = (**visitor->vtbl)(node), cVar1 != '\0')) {
      return '\x01';
    }
    switch(node->kind & 7) {
    default:
      goto switchD_1041b64f_caseD_0;
    case 1:
      node = node->left;
      break;
    case 2:
      cVar1 = tree_has_side_effects(visitor,node->left);
      if ((cVar1 == '\0') && (cVar1 = tree_has_side_effects(visitor,node->right), cVar1 == '\0')) {
        return '\0';
      }
      return '\x01';
    }
  }
switchD_1041b64f_caseD_0:
  return '\0';
}

