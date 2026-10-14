void __fastcall
copy_mul_operand_to_temp(c2_operand **multiplicand,c2_operand **second_use,int two_copies)

{
  uint16_t type;
  c2_operand *src;
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  src = *multiplicand;
  pcVar2 = src->sym->def;
  if ((((pcVar2->op == 0x15b) && (pcVar1 = pcVar2->src, (1 << (pcVar1->kind & 0x1f) & 6U) != 0)) &&
      (pcVar1->sym->cls == '\x03')) &&
     ((pcVar1->sym->def == (c2_tuple *)0x0 && (src->type == pcVar1->type)))) {
    pcVar2 = tuple_new_unary_temp(0x15b,src->type,pcVar1,tuple_insert_after,pcVar2);
    *second_use = pcVar2->dst;
    return;
  }
  pcVar1 = operand_new_temp_sym(src->type);
  mark_operand_register_candidate(pcVar1);
  pcVar2 = tuple_new(0x15b,src->type,pcVar1,src,tuple_insert_after,pcVar2);
  if (two_copies != 0) {
    pcVar2 = tuple_new_unary_temp(0x15b,pcVar1->type,pcVar1,tuple_insert_after,pcVar2);
    type = pcVar1->type;
    *multiplicand = pcVar2->dst;
    pcVar2 = tuple_new_unary_temp(0x15b,type,pcVar1,tuple_insert_after,pcVar2);
    *second_use = pcVar2->dst;
    return;
  }
  *multiplicand = pcVar1;
  *second_use = pcVar1;
  return;
}

