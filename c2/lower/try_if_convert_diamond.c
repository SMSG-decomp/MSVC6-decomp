c2_tuple * __fastcall try_if_convert_diamond(c2_function *fn,c2_tuple *branch)

{
  byte cc;
  ushort uVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *op;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  int iVar8;
  c2_tuple *pcVar9;
  c2_operand *local_20;
  c2_tuple *local_1c;
  c2_tuple *local_18;
  c2_label_ref *ref;
  c2_tuple *label;
  c2_tuple *after_label;
  
  pcVar2 = branch->src;
  local_18 = (c2_tuple *)0x0;
  if (pcVar2->kind != '\x04') {
    return branch;
  }
  label = *(c2_tuple **)((int)&pcVar2->sym->u30 + 2);
  if (label == (c2_tuple *)0x0) {
    return branch;
  }
  pcVar2 = pcVar2->next;
  cc = g_cond_inverse[(byte)branch->type];
  pcVar9 = pcVar2->sym->def;
  if (pcVar9 != branch->prev) {
    return branch;
  }
  for (ref = (c2_label_ref *)label->dst; ref != (c2_label_ref *)0x0; ref = ref->next) {
    if ((c2_tuple *)ref->referrer != branch) {
      return branch;
    }
  }
  for (pcVar4 = label->prev; (pcVar4->kind == '\x19' || (pcVar4->kind == '\x16'));
      pcVar4 = pcVar4->prev) {
  }
  if (pcVar4->kind != '\x11') {
    return branch;
  }
  if ((pcVar4->u20).cond_cells != (c2_cond_cell *)0x0) {
    return branch;
  }
  if (pcVar4->op == 0x18b) {
    return branch;
  }
  pcVar3 = *(c2_tuple **)((int)&pcVar4->src->sym->u30 + 2);
  pcVar6 = pcVar4;
  do {
    do {
      pcVar6 = pcVar6->prev;
    } while (pcVar6->kind == '\x19');
  } while (pcVar6->kind == '\x16');
  if (pcVar6->op == 0x15b) {
    local_20 = pcVar6->dst;
  }
  else {
    if (pcVar6->op != 0x16c) {
      return branch;
    }
    local_20 = (c2_operand *)0x0;
  }
  op = pcVar6->src;
  do {
    do {
      pcVar6 = pcVar6->prev;
    } while (pcVar6->kind == '\x19');
  } while (pcVar6->kind == '\x16');
  if (pcVar6 != branch) {
    return branch;
  }
  for (after_label = label->next; (after_label->kind == '\x19' || (after_label->kind == '\x16'));
      after_label = after_label->next) {
  }
  if (after_label->op == 0x15b) {
    if (local_20 == (c2_operand *)0x0) goto LAB_1071f22c;
    pcVar5 = (c2_operand *)operand_compare(local_20,after_label->dst);
  }
  else {
    pcVar5 = local_20;
    if (after_label->op != 0x16c) {
      return branch;
    }
  }
  if (pcVar5 != (c2_operand *)0x0) {
    return branch;
  }
LAB_1071f22c:
  pcVar5 = after_label->src;
  for (pcVar6 = after_label->next; (pcVar6->kind == '\x19' || (pcVar6->kind == '\x16'));
      pcVar6 = pcVar6->next) {
  }
  local_1c = pcVar3;
  if (((pcVar6 == pcVar3) ||
      ((((pcVar6->kind == '\x11' && ((pcVar6->u20).cond_cells == (c2_cond_cell *)0x0)) &&
        (pcVar6->op != 0x18b)) &&
       (local_1c = pcVar6, local_18 = pcVar6,
       *(c2_tuple **)((int)&pcVar6->src->sym->u30 + 2) == pcVar3)))) &&
     ((uVar7 = operand_is_unsafe_for_if_convert(op), uVar7 == 0 &&
      (uVar7 = operand_is_unsafe_for_if_convert(pcVar5), uVar7 == 0)))) {
    if (op->type != pcVar5->type) {
      operand_set_type(pcVar5,op->type);
    }
    uVar1 = branch->line;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    iVar8 = select_is_profitable(op->type,(int)pcVar9,op,pcVar5,g_cond_inverse[cc],1);
    if (iVar8 != 0) {
      pcVar9 = tuple_new_ternary_temp(399,op->type,pcVar2,op,pcVar5,cc,tuple_insert_before,branch);
      if (local_20 == (c2_operand *)0x0) {
        tuple_new_exit(0x16c,op->type,(c2_operand *)0x0,pcVar9->dst,tuple_insert_after,pcVar9);
      }
      else {
        tuple_new(0x15b,op->type,local_20,pcVar9->dst,tuple_insert_after,pcVar9);
      }
      pcVar3 = branch->next;
      pcVar6 = local_1c->next;
      branch_free(branch);
      branch_free(pcVar4);
      while (pcVar4 = pcVar3, pcVar4 != pcVar6) {
        pcVar3 = pcVar4->next;
        if (((pcVar4->kind != '\x19') && (pcVar4->kind != '\x1a')) && (pcVar4 != local_18)) {
          tuple_unlink_free(pcVar4);
        }
      }
      pcVar4 = pcVar9->next;
      if (pcVar9->prev == pcVar9->src->sym->def) {
        pcVar9 = follow_single_use_chain_linked(pcVar9);
        simplify_tuple_tree(pcVar9);
      }
      return pcVar4->prev;
    }
  }
  return branch;
}

