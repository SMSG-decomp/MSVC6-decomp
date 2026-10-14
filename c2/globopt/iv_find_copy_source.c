c2_operand * __fastcall iv_find_copy_source(c2_operand *op,c2_loop *loop)

{
  c2_block *pcVar1;
  int iVar2;
  c2_tuple *pcVar3;
  
  if ((1 << (op->kind & 0x1f) & 0x380U) != 0) {
    return op;
  }
  pcVar1 = loop->preheader;
  pcVar3 = pcVar1->head->next;
  if (pcVar3 != pcVar1->end) {
    while ((pcVar3->op != 0x15b || (iVar2 = operand_compare(pcVar3->dst,op), iVar2 != 0))) {
      pcVar3 = pcVar3->next;
      if (pcVar3 == pcVar1->end) {
        return op;
      }
    }
    if ((1 << (pcVar3->src->kind & 0x1f) & 0x380U) == 0) {
      return op;
    }
    return pcVar3->src;
  }
  return op;
}

