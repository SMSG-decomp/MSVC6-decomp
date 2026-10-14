int __fastcall eliminate_redundant_compare_across_branch(c2_tuple *cmp,c2_tuple *jcc)

{
  byte bVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  int iVar6;
  c2_tuple *pcVar7;
  int local_8;
  
  local_8 = 0;
  pcVar4 = *(c2_tuple **)((int)&jcc->src->sym->u30 + 2);
  do {
    pcVar4 = tuple_next_real_in_block(pcVar4);
    if (pcVar4 == (c2_tuple *)0x0) goto LAB_1073cf5a;
  } while ((pcVar4->kind == '\x1a') && (pcVar4->dst == (c2_operand *)0x0));
  if (pcVar4 != (c2_tuple *)0x0) {
    if (((cmp->flags & 4) != 0) && ((pcVar4->flags & 4) != 0)) {
      pcVar7 = cmp->prev;
      pcVar3 = pcVar4->next;
      if ((((pcVar7->flags & 1) != 0) &&
          (((bVar1 = pcVar3->flags, (bVar1 & 1) != 0 && ((pcVar7->flags & 4) != 0)) &&
           ((bVar1 & 4) != 0)))) &&
         ((pcVar7 != pcVar4 && (iVar6 = tuples_equal(pcVar7,pcVar4), iVar6 != 0)))) {
        pcVar4 = pcVar3;
      }
    }
    if ((pcVar4 != (c2_tuple *)0x0) &&
       ((((uVar2 = pcVar4->op, uVar2 == 0x2f || (uVar2 == 0x33)) || (uVar2 == 0x30)) &&
        ((cmp != pcVar4 && (iVar6 = compares_equivalent(cmp,pcVar4,jcc,1), iVar6 != 0)))))) {
      pcVar4 = label_after_or_create(pcVar4);
      tuple_retarget(jcc,(c2_node *)pcVar4,0);
      local_8 = 1;
    }
  }
LAB_1073cf5a:
  pcVar4 = tuple_next_real_in_block(jcc);
  while( true ) {
    if (pcVar4 == (c2_tuple *)0x0) {
      return local_8;
    }
    if (((pcVar4->flags & 1) == 0) ||
       (pcVar5 = find_dst_clobbering_reg(pcVar4,(jcc->src->next->u18).reg),
       pcVar5 != (c2_operand *)0x0)) break;
    pcVar4 = tuple_next_real_in_block(pcVar4);
  }
  if (pcVar4 == (c2_tuple *)0x0) {
    return local_8;
  }
  uVar2 = pcVar4->op;
  if (((uVar2 != 0x2f) && (uVar2 != 0x33)) && (uVar2 != 0x30)) {
    return local_8;
  }
  iVar6 = compares_equivalent(cmp,pcVar4,jcc,0);
  if (iVar6 == 0) {
    return local_8;
  }
  pcVar5 = pcVar4->src;
  while( true ) {
    if (pcVar5 == (c2_operand *)0x0) {
      compares_equivalent(cmp,pcVar4,jcc,1);
      pcVar7 = tuple_next_real_in_block(pcVar4);
      if (((pcVar7->kind == '\x11') && ((pcVar7->u20).cond_cells != (c2_cond_cell *)0x0)) &&
         ((char)jcc->type == (char)pcVar7->type)) {
        branch_free(pcVar7);
      }
      tuple_unlink_free(pcVar4);
      return 1;
    }
    iVar6 = range_writes_alias(jcc,&pcVar4->prev->next,pcVar5);
    if (iVar6 != 0) break;
    pcVar5 = pcVar5->next;
  }
  return local_8;
}

