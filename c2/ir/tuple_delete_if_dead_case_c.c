c2_node * tuple_delete_if_dead_case_c(c2_tuple *t)

{
  ushort type;
  c2_operand *node;
  c2_const_operand *size;
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *anchor;
  c2_insert_fn *insert_fn;
  
  if (t->dst == (c2_operand *)0x0) {
    anchor = t;
    for (node = t->src; node != (c2_operand *)0x0; node = node->next) {
      if ((node->flags & 0x20) == 0) {
        type = node->type;
        insert_fn = tuple_splice_after;
        if ((node->type & 0xf000) == 0x5000) {
          size = operand_new_intconst(type,type & 0xfff,0);
          pcVar1 = (c2_operand *)node_clone((c2_node *)node);
          pcVar2 = operand_new_temp_sym(type);
          anchor = tuple_new_blockop(0x16b,type,pcVar2,pcVar1,size,insert_fn,anchor);
        }
        else {
          pcVar1 = (c2_operand *)node_clone((c2_node *)node);
          pcVar2 = operand_new_temp_sym(type);
          anchor = tuple_new(0x15b,type,pcVar2,pcVar1,insert_fn,anchor);
        }
      }
    }
    tuple_unlink(t);
    node_free((c2_node *)t);
    return (c2_node *)anchor;
  }
  return (c2_node *)t;
}

