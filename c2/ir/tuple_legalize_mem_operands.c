void __fastcall tuple_legalize_mem_operands(c2_tuple *t)

{
  if (t->op != 0x145) {
    legalize_mem_operand(t,t->dst,tuple_replace_dst);
    legalize_mem_operand(t,t->src,tuple_replace_src);
    if (t->src != (c2_operand *)0x0) {
      legalize_mem_operand(t,t->src->next,tuple_replace_src);
    }
  }
  return;
}

