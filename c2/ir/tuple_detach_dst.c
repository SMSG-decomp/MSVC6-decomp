void __fastcall tuple_detach_dst(c2_tuple *t,c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar1 = t->dst;
  pcVar3 = (c2_operand *)0x0;
  if (t->dst != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      if (pcVar2 == op) break;
      pcVar1 = pcVar2->next;
      pcVar3 = pcVar2;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar3 != (c2_operand *)0x0) {
      pcVar3->next = op->next;
      goto LAB_1074b54b;
    }
  }
  t->dst = op->next;
LAB_1074b54b:
  op->next = (c2_operand *)0x0;
  if ((1 << (op->kind & 0x1f) & 0xffeU) != 0) {
    op->flags = op->flags & 0xef;
  }
  return;
}

