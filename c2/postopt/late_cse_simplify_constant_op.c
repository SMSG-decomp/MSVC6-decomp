int __fastcall late_cse_simplify_constant_op(c2_tuple *t,c2_symbol *reg)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_const_operand *pcVar5;
  uint32_t lo;
  
  pcVar4 = (reg->u34).lcse_values;
  while( true ) {
    if (pcVar4 == (c2_operand *)0x0) {
      return 0;
    }
    if (pcVar4->kind == '\a') break;
    pcVar4 = (c2_operand *)pcVar4->rank;
  }
  if (pcVar4 == (c2_operand *)0x0) {
    return 0;
  }
  pcVar1 = t->dst;
  if (pcVar1->kind != '\x01') {
    return 0;
  }
  if ((pcVar1->u18).reg != reg) {
    return 0;
  }
  pcVar2 = (c2_symbol *)(pcVar4->u18).lo;
  switch(t->op) {
  case 1:
    break;
  default:
    return 0;
  case 0xc:
    pcVar3 = t->prev;
    if (pcVar3->op != 0xd) {
      return 0;
    }
    pcVar4 = pcVar3->src;
    if ((pcVar4->kind != '\a') || ((pcVar4->u18).reg != pcVar2)) {
      if (pcVar4->kind != '\x01') {
        return 0;
      }
      if ((pcVar4->u18).reg != reg) {
        return 0;
      }
    }
    tuple_unlink_free(pcVar3);
    tuple_unlink_free(t);
    return 1;
  case 0x2d:
    if (pcVar2 != (c2_symbol *)0x0) {
      return 0;
    }
    pcVar3 = find_next_reg_writer(t);
    if (pcVar3 == (c2_tuple *)0x0) {
      t->op = 1;
      tuple_remove_src(t,t->src);
      return 0;
    }
    return 0;
  case 0x34:
    if (pcVar2 != (c2_symbol *)0x0) {
      return 0;
    }
    pcVar4 = t->src->next;
    if (pcVar4->kind != '\x01') {
      return 0;
    }
    if ((pcVar4->u18).reg != reg) {
      return 0;
    }
    pcVar4 = pcVar1->next;
    if (((pcVar4 != (c2_operand *)0x0) && (pcVar4->kind == '\x01')) && (pcVar4->sym->cls != '\x01'))
    {
      return 0;
    }
    tuple_unlink_free(t);
    return 1;
  }
  if (t->src->kind != '\a') {
    return 0;
  }
  if (g_opt_favor_speed != 0) {
    return 0;
  }
  pcVar3 = find_next_reg_writer(t);
  if (pcVar3 != (c2_tuple *)0x0) {
    return 0;
  }
  pcVar4 = t->src;
  lo = (int)(pcVar4->u18).reg - (int)pcVar2;
  if (0x7f < (int)lo) {
    return 0;
  }
  if ((int)lo < 1) {
    if ((int)lo < -0x80) {
      return 0;
    }
    tuple_remove_src(t,pcVar4);
    pcVar4 = (c2_operand *)node_clone((c2_node *)t->dst);
    pcVar4->next = t->src;
    t->src = pcVar4;
    if (lo != 0xffffffff) goto LAB_1076ba99;
    t->op = 0x1e;
  }
  else {
    tuple_remove_src(t,pcVar4);
    pcVar4 = (c2_operand *)node_clone((c2_node *)t->dst);
    pcVar4->next = t->src;
    t->src = pcVar4;
    if (lo != 1) {
LAB_1076ba99:
      t->op = 0x2d;
      pcVar4 = operand_new_hardreg(0x42,0x8000);
      tuple_append_dst(t,pcVar4);
      pcVar5 = operand_new_intconst(t->type,lo,(int)lo >> 0x1f);
      pcVar4 = t->src;
      pcVar5->next = pcVar4->next;
      pcVar4->next = pcVar5;
      return 0;
    }
    t->op = 0x21;
  }
  pcVar4 = operand_new_hardreg(0x43,0x8000);
  tuple_append_dst(t,pcVar4);
  return 0;
}

