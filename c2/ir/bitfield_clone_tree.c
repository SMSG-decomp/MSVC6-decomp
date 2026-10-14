c2_node * __fastcall bitfield_clone_tree(c2_node *n)

{
  c2_operand *op;
  
  op = (c2_operand *)node_clone(n);
  if ((op->flags9 & 1) != 0) {
    bitfield_clone_tuple_tree((c2_tuple *)op);
    return (c2_node *)op;
  }
  bitfield_clone_leaf(op);
  return (c2_node *)op;
}

