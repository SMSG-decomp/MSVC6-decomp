c2_tuple * __fastcall negate_operand(c2_node *opnd,c2_tuple *parent)

{
  uint16_t type;
  c2_operand *src;
  c2_tuple *neg;
  c2_operand *prev;
  
  prev = (c2_operand *)opnd;
  if (parent != (c2_tuple *)0x0) {
    prev = (c2_operand *)list_find_prev((c2_link *)parent->src,(c2_link *)opnd);
    tuple_detach_src((c2_node *)parent,(c2_operand *)opnd);
  }
  type = opnd->type;
  src = operand_new_temp(type);
  neg = tuple_new_unary_temp(0x161,type,src,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
  tuple_replace_src(neg,neg->src,(c2_operand *)opnd);
  neg->flags12 = '\x02';
  if (parent != (c2_tuple *)0x0) {
    if (prev != (c2_operand *)0x0) {
      tuple_insert_src_after(parent,prev,(c2_operand *)neg);
      return neg;
    }
    prev = parent->src;
    parent->src = (c2_operand *)neg;
    neg->next = (c2_tuple *)prev;
  }
  return neg;
}

