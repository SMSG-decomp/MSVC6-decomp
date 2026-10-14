void __fastcall branch_delete_cleanup(c2_tuple *branch)

{
  c2_tuple *t;
  c2_symbol *reg;
  c2_operand *pcVar1;
  c2_tuple *t_00;
  c2_operand *pcVar2;
  int iVar3;
  
  t_00 = tuple_prev_real(branch);
  if (g_jumpopt_no_crossjump == 0) {
    if (branch->kind == '\x13') {
      return;
    }
    pcVar2 = find_dst_clobbering_reg(t_00,(branch->src->next->u18).reg);
    if (pcVar2 == (c2_operand *)0x0) {
      return;
    }
    if (t_00->dst->next != (c2_operand *)0x0) {
      return;
    }
    tuple_unlink_free(t_00);
    return;
  }
  if ((t_00->op == 0x19e) && ((t_00->flags & 0xf0) != 0)) {
    pcVar2 = t_00->src;
    t = t_00->prev;
    reg = (pcVar2->u18).reg;
    while ((t != (c2_tuple *)0x0 &&
           (pcVar2 = operand_list_find_reg(t->dst,reg), pcVar2 == (c2_operand *)0x0))) {
      t = t->prev;
    }
    if (reg->cls == '\x01') {
      pcVar2->sym = reg;
    }
    else {
      if ((reg->cls == '\x02') || (iVar3 = node_has_side_effects((c2_node *)t), iVar3 != 0))
      goto LAB_1075095b;
      for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if (pcVar1->kind != '\x01') {
          if (pcVar1 != (c2_operand *)0x0) goto LAB_1075095b;
          break;
        }
      }
      tuple_remove_dst(t,pcVar2);
    }
    tuple_unlink_free(t_00);
  }
LAB_1075095b:
  pcVar2 = branch->src;
  if (pcVar2 == (c2_operand *)0x0) {
    return;
  }
  do {
    if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
      tuple_drop_unused_results(pcVar2);
    }
    pcVar2 = pcVar2->next;
  } while (pcVar2 != (c2_operand *)0x0);
  return;
}

