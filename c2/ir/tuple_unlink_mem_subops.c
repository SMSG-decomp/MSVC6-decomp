void __fastcall tuple_unlink_mem_subops(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  uint uVar4;
  
  for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if ((1 << (pcVar1->kind & 0x1f) & 0x60U) != 0) {
      pcVar1->flags11 = pcVar1->flags11 | 0x20;
    }
  }
  pcVar1 = t->src;
  pcVar3 = (c2_operand *)0x0;
  while (pcVar2 = pcVar3, pcVar3 = pcVar1, pcVar3 != (c2_operand *)0x0) {
    pcVar1 = pcVar3->next;
    uVar4 = 1 << (pcVar3->kind & 0x1f);
    if ((uVar4 & 0x60) != 0) {
      pcVar3->flags11 = pcVar3->flags11 | 0x20;
    }
    if (((uVar4 & 0xffe) != 0) && ((pcVar3->flags & 0x20) != 0)) {
      pcVar2->next = pcVar1;
      pcVar3->next = (c2_operand *)0x0;
      pcVar3 = pcVar2;
    }
  }
  return;
}

