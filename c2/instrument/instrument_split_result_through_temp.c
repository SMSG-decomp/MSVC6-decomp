c2_operand * __fastcall instrument_split_result_through_temp(c2_tuple *t)

{
  uint16_t type;
  c2_operand *dst;
  c2_operand *src;
  
  cse_unlink_def(t);
  if (t->kind != '\f') {
    dst = t->dst;
    type = dst->type;
    src = operand_new_temp(type);
    tuple_new(0x15b,type,dst,src,tuple_insert_after,t);
    tuple_replace_dst(t,dst,src);
    src->sym->def = t;
    return t->dst;
  }
  return t->dst;
}

