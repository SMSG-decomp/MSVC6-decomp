c2_operand * __fastcall tuple_replace_src_with_base_copy(c2_tuple *t,c2_operand *old,c2_symbol *sym)

{
  c2_const_operand *new_op;
  c2_operand *pcVar1;
  
  pcVar1 = (sym->u28).const_operand;
  if (pcVar1->kind == '\a') {
    new_op = operand_new_intconst(old->type,(pcVar1->u18).lo,pcVar1->tag);
    pcVar1 = tuple_replace_src(t,old,new_op);
    return pcVar1;
  }
  pcVar1 = (c2_operand *)node_clone((c2_node *)pcVar1);
  pcVar1 = tuple_replace_src(t,old,pcVar1);
  return pcVar1;
}

