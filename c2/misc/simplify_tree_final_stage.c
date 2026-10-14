c2_tuple * __fastcall simplify_tree_final_stage(c2_tuple *t,c2_tuple *parent)

{
  c2_symbol *offset;
  c2_operand *pcVar1;
  c2_operand *k;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_operand *pcVar7;
  c2_symbol *pcVar8;
  c2_operand *pcVar9;
  c2_operand *pcVar10;
  
  pcVar3 = widen_conversion_pushdown(t,parent);
  pcVar4 = pcVar3->src;
  while (pcVar10 = pcVar4, pcVar10 != (c2_operand *)0x0) {
    pcVar4 = pcVar10->next;
    if ((1 << (pcVar10->kind & 0x1f) & 0xffeU) == 0) {
      simplify_tree_final_stage((c2_tuple *)pcVar10,pcVar3);
    }
  }
  pcVar3 = distribute_before_final(pcVar3,parent);
  pcVar4 = (c2_operand *)simplify_node_algebraic(pcVar3,parent);
  iVar5 = tuple_is_commutative((c2_tuple *)pcVar4);
  if (iVar5 == 0) {
    uVar6 = is_unary_il_opcode((c2_node *)pcVar4);
    if (uVar6 == 0) {
      uVar6 = is_reorderable_binary_opcode((c2_node *)pcVar4);
      if (uVar6 == 0) {
        return (c2_tuple *)pcVar4;
      }
      pcVar10 = (pcVar4->u18).children;
      if ((pcVar10->kind == '\a') && (pcVar10->next->kind == '\a')) {
        pcVar10 = fold_integer_constants((c2_tuple *)pcVar4,pcVar4->type,pcVar10,pcVar10->next);
        if (pcVar10 == (c2_operand *)0x0) {
          return (c2_tuple *)pcVar4;
        }
        pcVar10 = ((pcVar4->u18).children)->next;
      }
      else {
        if (pcVar10->kind != '\t') {
          return (c2_tuple *)pcVar4;
        }
        if (pcVar10->next->kind != '\t') {
          return (c2_tuple *)pcVar4;
        }
        pcVar10 = fold_float_constants((c2_tuple *)pcVar4,pcVar4->type,pcVar10,pcVar10->next);
        if (pcVar10 == (c2_operand *)0x0) {
          return (c2_tuple *)pcVar4;
        }
        pcVar10 = ((pcVar4->u18).children)->next;
      }
      tuple_remove_src((c2_tuple *)pcVar4,pcVar10);
    }
    else {
      pcVar10 = (pcVar4->u18).children;
      if (pcVar10->kind == '\a') {
        pcVar10 = fold_integer_constants((c2_tuple *)pcVar4,pcVar4->type,pcVar10,(c2_operand *)0x0);
      }
      else {
        if (pcVar10->kind != '\t') {
          return (c2_tuple *)pcVar4;
        }
        pcVar10 = fold_float_constants((c2_tuple *)pcVar4,pcVar4->type,pcVar10,(c2_operand *)0x0);
      }
      if (pcVar10 == (c2_operand *)0x0) {
        return (c2_tuple *)pcVar4;
      }
    }
    pcVar4 = tuple_forward_src_and_free((c2_tuple *)pcVar4,parent);
    g_simplify_changed = 1;
  }
  else {
    if ((1 << (byte)(pcVar4->type >> 0xc) & 0xeU) == 0) {
      if ((pcVar4->type & 0xf000) == 0x4000) {
        pcVar10 = (pcVar4->u18).children;
        pcVar9 = (c2_operand *)0x0;
        while (pcVar1 = pcVar9, pcVar2 = pcVar10, pcVar2 != (c2_operand *)0x0) {
          pcVar10 = pcVar2->next;
          pcVar9 = pcVar1;
          if (((pcVar2->kind == '\t') && (pcVar9 = pcVar2, pcVar1 != (c2_operand *)0x0)) &&
             (pcVar9 = fold_float_constants((c2_tuple *)pcVar4,pcVar4->type,pcVar1,pcVar2),
             pcVar9 != (c2_operand *)0x0)) {
            tuple_remove_src((c2_tuple *)pcVar4,pcVar2);
            g_simplify_changed = 1;
          }
        }
      }
    }
    else {
      pcVar10 = (pcVar4->u18).children;
      pcVar2 = (c2_operand *)0x0;
      pcVar9 = (c2_operand *)0x0;
      while (k = pcVar2, pcVar1 = pcVar10, pcVar1 != (c2_operand *)0x0) {
        pcVar10 = pcVar1->next;
        pcVar2 = k;
        if (pcVar1->kind == '\a') {
          pcVar2 = pcVar1;
          if ((k != (c2_operand *)0x0) &&
             (pcVar7 = fold_integer_constants((c2_tuple *)pcVar4,pcVar4->type,k,pcVar1), pcVar2 = k,
             pcVar7 != (c2_operand *)0x0)) {
            tuple_remove_src((c2_tuple *)pcVar4,pcVar1);
            g_simplify_changed = 1;
          }
        }
        else if ((pcVar1->kind == '\x03') && (pcVar4->op == 0x16d)) {
          pcVar9 = pcVar1;
        }
      }
      if (((g_opt_dlp == 0) && (pcVar9 != (c2_operand *)0x0)) && (k != (c2_operand *)0x0)) {
        pcVar8 = pcVar9->sym;
        offset = (k->u18).reg;
        if ((-1 < (int)&offset->fe + pcVar8->offset) &&
           (((pcVar8->type & 0xf000) == 0x5000 || ((int)offset < (int)(pcVar8->type & 0xfff))))) {
          pcVar8 = symbol_get_part(pcVar8,0x5000,0,(int32_t)offset);
          pcVar9->sym = pcVar8;
          tuple_remove_src((c2_tuple *)pcVar4,k);
        }
      }
    }
    if (((pcVar4->u18).reg)->fe == (c2_fe_symbol *)0x0) {
      pcVar4 = tuple_forward_src_and_free((c2_tuple *)pcVar4,parent);
      return (c2_tuple *)pcVar4;
    }
  }
  return (c2_tuple *)pcVar4;
}

