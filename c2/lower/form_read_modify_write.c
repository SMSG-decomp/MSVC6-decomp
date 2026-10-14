void __fastcall form_read_modify_write(c2_tuple *anchor)

{
  ushort uVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_tuple *t;
  c2_operand *new_op;
  c2_operand *pcVar4;
  c2_tuple *t_00;
  
  uVar1 = anchor->type;
  if ((uVar1 & 0xf000) == 0x4000) {
    return;
  }
  pcVar4 = anchor->src;
  if (((pcVar4->kind != 1) || (pcVar4->sym->cls != '\x03')) ||
     (t_00 = pcVar4->sym->def, t_00 == (c2_tuple *)0x0)) {
    t_00 = anchor->prev;
    if ((1 << (pcVar4->kind & 0x1f) & 6U) == 0) {
      return;
    }
    if ((t_00->flags & 1) == 0) {
      return;
    }
    pcVar2 = t_00->dst;
    if (pcVar2 == (c2_operand *)0x0) {
      return;
    }
    if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
      return;
    }
    if (pcVar2->sym != pcVar4->sym) {
      return;
    }
  }
  g_rmw_store = anchor;
  switch(t_00->op) {
  case 0x16d:
  case 0x172:
  case 0x173:
    g_rmw_match_op = t_00->op;
    break;
  case 0x16e:
    g_rmw_match_op = 0x16d;
    break;
  default:
    goto switchD_1071eb12_caseD_16f;
  case 0x174:
    pcVar4 = t_00->src;
    pcVar2 = pcVar4->next;
    if ((uVar1 == pcVar2->type) && (iVar3 = operand_compare(anchor->dst,pcVar2), iVar3 == 0)) {
      rewrite_as_rmw_tuple(anchor,pcVar2,pcVar4,t_00);
      return;
    }
  case 0x171:
  case 0x177:
    pcVar4 = t_00->src;
    if (uVar1 != pcVar4->type) {
      return;
    }
    iVar3 = operand_compare(anchor->dst,pcVar4);
    if (iVar3 != 0) {
      return;
    }
    if (((uVar1 & 0xfff) == 8) && (t_00->op != 0x174)) {
      return;
    }
    rewrite_as_rmw_tuple(anchor,pcVar4,pcVar4->next,t_00);
    return;
  }
  pcVar2 = anchor->dst;
  g_rmw_found_negated = 0;
  g_rmw_dest_operand = pcVar2;
  iVar3 = find_rmw_dest_in_expr((c2_node *)t_00,0);
  if (iVar3 != 0) {
    if (((pcVar4->kind != '\x01') || (pcVar4->sym->cls != '\x03')) ||
       (pcVar4->sym->def == (c2_tuple *)0x0)) {
      pcVar4 = operand_new_temp(pcVar4->type);
      tuple_new(0x15b,t_00->type,t_00->dst,pcVar2,tuple_insert_after,anchor);
      tuple_replace_dst(t_00,t_00->dst,pcVar4);
      symbol_mark_overlapping_parts(pcVar4->sym,t_00);
    }
    t = tuple_new_binary(t_00->op,anchor->type,anchor->dst,anchor->dst,pcVar4,(c2_insert_fn *)0x0,
                         (c2_tuple *)0x0);
    tuple_replace(anchor,(c2_node *)t);
    if ((t_00->op == 0x16e) || (g_rmw_found_negated != 0)) {
      t->op = 0x16d;
    }
    rmw_dispatch_then_const(g_rmw_found_tuple);
    tuple_replace_src(g_rmw_found_tuple,g_rmw_found_operand,new_op);
    rmw_fold_negated_add(t);
  }
switchD_1071eb12_caseD_16f:
  return;
}

