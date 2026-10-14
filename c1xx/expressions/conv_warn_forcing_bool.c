c1_node * __cdecl conv_warn_forcing_bool(uint op,c1_node *left,c1_type *type)

{
  c1_node *pcVar1;
  c1_node *node;
  
  if ((left->flags & 1) == 0) {
    pcVar1 = tree_new_int_constant(0);
    node = tree_new_node('L',left,pcVar1,type);
    pcVar1 = fold_binary_constants(node,left,pcVar1);
    if ((pcVar1->kind & 7) == 3) {
      pcVar1->type = type;
      pcVar1->flags = pcVar1->flags | 1;
      return pcVar1;
    }
    diag_warning(3,800,left->type);
    pcVar1 = tree_new_cast(type,pcVar1);
    pcVar1->flags = pcVar1->flags | 1;
    return pcVar1;
  }
  if ((left->kind & 7) == 3) {
    left->type = type;
    return left;
  }
  pcVar1 = tree_new_cast(type,left);
  pcVar1->flags = pcVar1->flags | 1;
  return pcVar1;
}

