c2_operand * __fastcall tuple_iv_second_source(c2_tuple *t,c2_symbol *iv)

{
  c2_operand *pcVar1;
  
  pcVar1 = (c2_operand *)t->src->rank;
  if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym == iv)) {
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}

