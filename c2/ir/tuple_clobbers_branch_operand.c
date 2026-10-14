uint32_t __fastcall tuple_clobbers_branch_operand(c2_tuple *t,c2_tuple *t2)

{
  c2_symbol *reg;
  c2_live_range *pcVar1;
  c2_live_range *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  
  if ((t->flags & 1) == 0) {
    return 0;
  }
  reg = (t2->src->next->u18).reg;
  pcVar3 = find_dst_clobbering_reg(t,reg);
  if (pcVar3 == (c2_operand *)0x0) {
    return 0;
  }
  pcVar4 = find_src_overlapping_reg(t2,reg);
  pcVar1 = (pcVar4->u18).range;
  if (pcVar3->kind == '\n') {
    uVar5 = bitset_test((c2_bitset *)pcVar3->sym,pcVar1->self->id);
    return uVar5;
  }
  pcVar2 = (pcVar3->u18).range;
  if (pcVar1 != pcVar2) {
    if (((int)(pcVar2->allowed->pad_05 + pcVar2->refcount + -5) <= pcVar1->refcount) ||
       ((int)(pcVar1->allowed->pad_05 + pcVar1->refcount + -5) <= pcVar2->refcount)) {
      return 0;
    }
  }
  return 1;
}

