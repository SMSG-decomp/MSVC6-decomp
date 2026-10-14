c2_node * __fastcall simplify_conversion_chain(c2_tuple *t,c2_tuple *user)

{
  c2_operand *pcVar1;
  c2_operand *t_00;
  c2_tuple *result;
  
  result = (c2_tuple *)simplify_conversion(t,user);
  if ((1 << (result->kind & 0x1f) & 0xffeU) == 0) {
    pcVar1 = result->src;
    while (t_00 = pcVar1, t_00 != (c2_operand *)0x0) {
      pcVar1 = t_00->next;
      if (t_00->op == 0x15f) {
        simplify_conversion_chain((c2_tuple *)t_00,result);
      }
    }
  }
  return (c2_node *)result;
}

