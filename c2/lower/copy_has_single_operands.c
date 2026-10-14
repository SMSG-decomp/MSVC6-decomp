int __fastcall copy_has_single_operands(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = t->src;
  pcVar2 = pcVar1->next;
  if (t->dst->next != (c2_operand *)0x0) {
    return 0;
  }
  if (pcVar2 == (c2_operand *)0x0) {
    return 1;
  }
  if (((1 << (pcVar1->kind & 0x1f) & 0x60U) != 0) && ((pcVar1->flags11 & 0x20) == 0)) {
    if (pcVar1->index != (c2_operand *)0x0) {
      pcVar2 = pcVar2->next;
    }
    if (pcVar1->base != (c2_operand *)0x0) {
      pcVar2 = pcVar2->next;
    }
  }
  return (uint)(pcVar2 == (c2_operand *)0x0);
}

