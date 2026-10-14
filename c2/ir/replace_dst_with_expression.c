void __fastcall replace_dst_with_expression(c2_operand *new_op,c2_tuple *t)

{
  uint16_t type;
  c2_tuple *t_00;
  c2_operand *pcVar1;
  c2_operand *local_8;
  c2_symbol *local_4;
  
  pcVar1 = t->dst;
  if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
    local_4 = pcVar1->sym->storage;
    t_00 = find_next_use_of_dst(t,&local_8);
    tuple_replace_dst(t,pcVar1,new_op);
    type = local_8->type;
    pcVar1 = tuple_replace_src(t_00,local_8,new_op);
    if (type != 0x8000) {
      operand_set_type(pcVar1,type);
    }
    symbol_free_chain(local_4);
    return;
  }
  tuple_new(0x15b,t->type,pcVar1,new_op,tuple_insert_after,t);
  tuple_replace_dst(t,pcVar1,new_op);
  return;
}

