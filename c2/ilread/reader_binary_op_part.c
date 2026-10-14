void reader_binary_op_part
               (c2_operand *left,c2_operand *right,c2_tuple **tail,c2_operand *right_home)

{
  c2_tuple *pos;
  
  if ((left->flags & 0x10) == 0) {
    node_free((c2_node *)left);
    right = right_home;
  }
  if ((right->flags & 0x10) != 0) {
    right_home = (c2_operand *)node_clone((c2_node *)right);
  }
  pos = (c2_tuple *)tuple_delete_if_dead((c2_node *)*tail,0);
  *tail = pos;
  tuple_splice_after(pos,(c2_tuple *)right_home);
  *tail = (c2_tuple *)right_home;
  return;
}

