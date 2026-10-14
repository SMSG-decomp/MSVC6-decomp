c2_tuple * __fastcall
iv_find_preheader_equivalent
          (c2_tuple *t,c2_operand *a,c2_operand *b,c2_operand *step,uint32_t update_op,c2_loop *loop
          ,c2_function *fn)

{
  uint32_t uVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  int iVar5;
  uint16_t type;
  c2_tuple *pcVar6;
  
  pcVar6 = (c2_tuple *)0x0;
  uVar1 = t->op;
  if (uVar1 == 0x15b) {
    if ((1 << (t->src->kind & 0x1f) & 0x18U) == 0) {
      return (c2_tuple *)0x0;
    }
    pcVar4 = common_copy_ancestor(a,b);
  }
  else {
    if (uVar1 == 0x161) {
      if ((1 << (t->src->kind & 0x1f) & 0x18U) == 0) {
        return (c2_tuple *)0x0;
      }
      iVar5 = operand_reaches_via_copies(b,a);
      if (iVar5 == 0) {
        return (c2_tuple *)0x0;
      }
      type = a->type;
      pcVar3 = a->sym;
      pcVar4 = a;
      goto LAB_1076396b;
    }
    if (uVar1 != 0x16e) {
      return (c2_tuple *)0x0;
    }
    if ((1 << (t->src->kind & 0x1f) & 0x18U) == 0) {
      return (c2_tuple *)0x0;
    }
    if ((1 << (t->src->next->kind & 0x1f) & 0x18U) == 0) {
      return (c2_tuple *)0x0;
    }
    pcVar4 = common_copy_ancestor(a,b);
  }
  if (pcVar4 == (c2_operand *)0x0) {
    return (c2_tuple *)0x0;
  }
  pcVar4 = derive_iv_from_chain(pcVar4,a,t->src);
  type = pcVar4->type;
  pcVar3 = pcVar4->sym;
LAB_1076396b:
  if (pcVar3 == (c2_symbol *)0x0) {
    return (c2_tuple *)0x0;
  }
  if (pcVar3->defs != (c2_list_cell *)0x0) {
    pcVar2 = loop->preheader->head->next;
    if (pcVar2 != loop->preheader->end) {
      while ((pcVar6 = pcVar2, pcVar6->op != 0x15b ||
             (iVar5 = operand_compare(pcVar4,pcVar6->dst), iVar5 != 0))) {
        pcVar2 = pcVar6->next;
        if (pcVar6->next == loop->preheader->end) {
          return (c2_tuple *)0x0;
        }
      }
    }
    return pcVar6;
  }
  pcVar6 = materialize_iv_in_preheader(pcVar4,type,step,update_op,a->sym,1,loop,fn);
  return pcVar6;
}

