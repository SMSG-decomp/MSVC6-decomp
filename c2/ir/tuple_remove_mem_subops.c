void __fastcall tuple_remove_mem_subops(c2_tuple *t,c2_operand *op)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  
  pcVar2 = op->base;
  if (pcVar2 != (c2_operand *)0x0) {
    bVar1 = op->flags11;
    pcVar2->flags = pcVar2->flags & 0xdf;
    if ((bVar1 & 0x20) == 0) {
      pcVar3 = t->src;
      pcVar5 = (c2_operand *)0x0;
      if (t->src == (c2_operand *)0x0) {
LAB_1077e556:
        t->src = pcVar2->next;
      }
      else {
        do {
          pcVar4 = pcVar3;
          if (pcVar4 == pcVar2) break;
          pcVar3 = pcVar4->next;
          pcVar5 = pcVar4;
        } while (pcVar4->next != (c2_operand *)0x0);
        if (pcVar5 == (c2_operand *)0x0) goto LAB_1077e556;
        pcVar5->next = pcVar2->next;
      }
      if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
        tuple_remove_mem_subops(t,pcVar2);
      }
    }
    node_free((c2_node *)pcVar2);
    op->base = (c2_operand *)0x0;
  }
  pcVar2 = op->index;
  if (pcVar2 == (c2_operand *)0x0) {
    return;
  }
  bVar1 = op->flags11;
  pcVar2->flags = pcVar2->flags & 0xdf;
  if ((bVar1 & 0x20) != 0) goto LAB_10703006;
  pcVar3 = t->src;
  pcVar5 = (c2_operand *)0x0;
  if (t->src == (c2_operand *)0x0) {
LAB_1077e56e:
    t->src = pcVar2->next;
  }
  else {
    do {
      pcVar4 = pcVar3;
      if (pcVar4 == pcVar2) break;
      pcVar3 = pcVar4->next;
      pcVar5 = pcVar4;
    } while (pcVar4->next != (c2_operand *)0x0);
    if (pcVar5 == (c2_operand *)0x0) goto LAB_1077e56e;
    pcVar5->next = pcVar2->next;
  }
  if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
    tuple_remove_mem_subops(t,pcVar2);
  }
LAB_10703006:
  node_free((c2_node *)pcVar2);
  op->index = (c2_operand *)0x0;
  return;
}

