int __fastcall tail_recursion_try_block(c2_function *fn,c2_block *block)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_tuple *pcVar4;
  uint uVar5;
  c2_tuple *pcVar6;
  c2_tuple *t;
  c2_tuple *local_c;
  
  local_c = (c2_tuple *)0x0;
  iVar3 = block_is_label_only_or_jump(block);
  if (iVar3 != 0) {
    uVar5 = tail_recursion_scan_preds(fn,block);
    return uVar5;
  }
  for (pcVar6 = block->end->prev;
      (((pcVar6 != (c2_tuple *)0x0 && (pcVar6->kind == '\x16')) && (pcVar6->op != 0x1b4)) &&
      (pcVar6->op != 0x1b5)); pcVar6 = pcVar6->prev) {
  }
  pcVar4 = pcVar6;
  if (((pcVar6->kind == '\x11') && ((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0)) &&
     ((pcVar6->op != 0x18b && (pcVar4 = pcVar6->prev, local_c = pcVar6, pcVar4 != (c2_tuple *)0x0)))
     ) {
    while ((pcVar4->kind == '\x16' && (pcVar4->op != 0x1b4))) {
      if ((pcVar4->op == 0x1b5) || (pcVar4 = pcVar4->prev, pcVar4 == (c2_tuple *)0x0)) break;
    }
  }
  pcVar6 = pcVar4;
  t = (c2_tuple *)0x0;
  if (pcVar4->kind != '\x0e') {
    if (pcVar4->kind != '\x0f') {
      return 0;
    }
    for (pcVar6 = pcVar4->prev;
        (((pcVar6 != (c2_tuple *)0x0 && (pcVar6->kind == '\x16')) && (pcVar6->op != 0x1b4)) &&
        (pcVar6->op != 0x1b5)); pcVar6 = pcVar6->prev) {
    }
    if (pcVar6->kind != '\x0e') {
      return 0;
    }
    pcVar1 = pcVar6->dst;
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    pcVar2 = pcVar4->src;
    if (pcVar2 == (c2_operand *)0x0) {
      return 0;
    }
    if ((1 << (pcVar1->kind & 0x1f) & 6U) == 0) {
      return 0;
    }
    if ((1 << (pcVar2->kind & 0x1f) & 6U) == 0) {
      return 0;
    }
    if (pcVar1->sym != pcVar2->sym) {
      return 0;
    }
    t = pcVar4;
    if (pcVar1->sym->cls != '\x03') {
      return 0;
    }
  }
  if (((pcVar6->src->kind == '\x04') && ((c2_fe_symbol *)pcVar6->src->sym == fn->fsym)) &&
     (iVar3 = rewrite_self_call_as_loop(fn,block,pcVar6), iVar3 == 1)) {
    if (t != (c2_tuple *)0x0) {
      tuple_unlink_free(t);
    }
    if (local_c != (c2_tuple *)0x0) {
      branch_free(local_c);
    }
    return 1;
  }
  return 0;
}

