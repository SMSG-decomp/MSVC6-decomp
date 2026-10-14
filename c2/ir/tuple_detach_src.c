void __fastcall tuple_detach_src(c2_node *node,c2_operand *op)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  uint uVar3;
  c2_operand *pcVar4;
  
  pcVar1 = *(c2_operand **)&node[1].kind;
  pcVar4 = (c2_operand *)0x0;
  if (*(c2_operand **)&node[1].kind != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      if (pcVar2 == op) break;
      pcVar1 = pcVar2->next;
      pcVar4 = pcVar2;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar4 != (c2_operand *)0x0) {
      pcVar4->next = op->next;
      goto LAB_1070ba58;
    }
  }
  *(c2_operand **)&node[1].kind = op->next;
LAB_1070ba58:
  uVar3 = 1 << (op->kind & 0x1f);
  op->next = (c2_operand *)0x0;
  if ((uVar3 & 0xffe) != 0) {
    op->flags = op->flags & 0xef;
  }
  if ((uVar3 & 0x60) != 0) {
    tuple_detach_mem_subops(node,op);
  }
  return;
}

