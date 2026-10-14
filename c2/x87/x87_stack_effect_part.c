int __fastcall
x87_stack_effect_part(c2_tuple *t,c2_operand *dst_operand,int delta,uint8_t operand_kind)

{
  c2_operand *pcVar1;
  int iVar2;
  
  do {
    dst_operand = dst_operand->next;
    if (dst_operand == (c2_operand *)0x0) {
      for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((pcVar1->kind == operand_kind) && ((pcVar1->type & 0xf000) == 0x4000)) {
          delta = delta + -1;
        }
      }
      return delta;
    }
  } while ((dst_operand->kind != operand_kind) || ((dst_operand->type & 0xf000) != 0x4000));
  iVar2 = x87_stack_effect_part(t,dst_operand,delta + 1,operand_kind);
  return iVar2;
}

