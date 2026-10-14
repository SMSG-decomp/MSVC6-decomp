void __fastcall insert_branch_value_facts_one(c2_function *fn,c2_tuple *t,c2_block *block)

{
  char cVar1;
  ushort uVar2;
  c2_edge *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  c2_block *pcVar7;
  c2_const_operand *src;
  int iVar8;
  c2_operand *pcVar9;
  c2_tuple *pcVar10;
  uint16_t uVar11;
  c2_operand *pcVar12;
  c2_switch_case *pcVar13;
  c2_symbol *pcVar14;
  bool bVar15;
  uint64_t uVar16;
  c2_tuple *anchor;
  c2_operand *local_c [2];
  uint32_t local_4;
  
  if (block->succs == (c2_edge *)0x0) {
    return;
  }
  if (t->op == 0x17d) {
    pcVar9 = t->src;
    if (((1 << (pcVar9->kind & 0x1f) & 6U) != 0) && (pcVar9->sym->def != (c2_tuple *)0x0)) {
      return;
    }
    if (((1 << (pcVar9->next->kind & 0x1f) & 6U) != 0) &&
       (pcVar9->next->sym->def != (c2_tuple *)0x0)) {
      return;
    }
    pcVar6 = find_next_use_of_dst(t,local_c);
    if (pcVar6->kind != '\x11') {
      return;
    }
    cVar1 = (char)pcVar6->type;
    if ((cVar1 != '\x02') && (cVar1 != '\x01')) {
      return;
    }
    pcVar9 = t->src;
    if ((1 << (pcVar9->kind & 0x1f) & 0x380U) == 0) {
      pcVar12 = pcVar9;
      pcVar9 = pcVar9->next;
    }
    else {
      pcVar12 = pcVar9->next;
      if ((1 << (pcVar12->kind & 0x1f) & 0x380U) != 0) {
        return;
      }
    }
    if (pcVar9->kind != '\a') {
      return;
    }
    if ((1 << (pcVar12->kind & 0x1f) & 6U) == 0) {
      return;
    }
    if (pcVar12->sym->def != (c2_tuple *)0x0) {
      return;
    }
    if (cVar1 == '\x01') {
      anchor = *(c2_tuple **)&(pcVar6->src->sym->u30).globopt.marks;
      pcVar7 = (anchor->u14).block;
      if (pcVar7 == (c2_block *)0x0) {
        pcVar10 = tuple_find_prev_of_kind(anchor,'\x19');
        pcVar7 = (pcVar10->u14).block;
      }
    }
    else {
      pcVar7 = block->next;
      anchor = pcVar7->head;
    }
    if (pcVar7->preds == (c2_edge *)0x0) {
      return;
    }
    if (pcVar7->preds->next_pred != (c2_edge *)0x0) {
      return;
    }
    if (block->succs->next_succ == (c2_edge *)0x0) {
      return;
    }
    pcVar6 = pcVar6->prev;
    local_4 = pcVar9->tag;
    pcVar14 = (pcVar9->u18).reg;
    block = (c2_block *)0x0;
    for (; pcVar6 != t; pcVar6 = pcVar6->prev) {
      uVar5 = pcVar6->op;
      if (uVar5 == 0x15b) {
        iVar8 = operand_compare(pcVar12,pcVar6->dst);
        if (iVar8 != 0) {
          return;
        }
        block = (c2_block *)pcVar6->src;
      }
      else if (uVar5 == 0x16d) {
        iVar8 = operand_compare((c2_operand *)block,pcVar6->dst);
        if (iVar8 != 0) {
          return;
        }
        pcVar4 = pcVar6->src;
        iVar8 = operand_compare(pcVar12,pcVar4);
        if (iVar8 != 0) {
          return;
        }
        pcVar4 = pcVar4->next;
        if (pcVar4->kind != '\a') {
          return;
        }
        bVar15 = CARRY4((uint)pcVar14,(uint)(pcVar4->u18).reg);
        pcVar14 = (c2_symbol *)((int)&pcVar14->fe + (int)(pcVar4->u18).reg);
        local_4 = local_4 + pcVar4->tag + (uint)bVar15;
      }
      else {
        if (uVar5 != 0x16e) {
          return;
        }
        iVar8 = operand_compare((c2_operand *)block,pcVar6->dst);
        if (iVar8 != 0) {
          return;
        }
        pcVar4 = pcVar6->src;
        iVar8 = operand_compare(pcVar12,pcVar4);
        if (iVar8 != 0) {
          return;
        }
        pcVar4 = pcVar4->next;
        if (pcVar4->kind != '\a') {
          return;
        }
        bVar15 = pcVar14 < (c2_symbol *)(pcVar4->u18).lo;
        pcVar14 = (c2_symbol *)((int)pcVar14 - (int)(pcVar4->u18).lo);
        local_4 = (local_4 - pcVar4->tag) - (uint)bVar15;
      }
    }
    if ((pcVar14 != (pcVar9->u18).reg) || (local_4 != pcVar9->tag)) {
      pcVar9 = (c2_operand *)node_clone((c2_node *)pcVar9);
      (pcVar9->u18).reg = pcVar14;
      pcVar9->tag = local_4;
    }
    pcVar6 = tuple_next_real(anchor);
    if ((pcVar6 != (c2_tuple *)0x0) && (uVar2 = pcVar6->line, uVar2 != 0)) {
      g_current_line_abs = fn->line_base + (uint)uVar2;
      g_cur_line = uVar2;
    }
    uVar11 = t->type;
  }
  else {
    if (t->op == 0x18d) {
      pcVar9 = t->src;
      if (((((1 << (pcVar9->kind & 0x1f) & 6U) != 0) && (pcVar9->sym->cls == '\x03')) &&
          (pcVar6 = t->prev, pcVar6->op == 0x15b)) &&
         (iVar8 = operand_compare(pcVar6->dst,pcVar9), iVar8 == 0)) {
        pcVar9 = pcVar6->src;
      }
      if (((1 << (pcVar9->kind & 0x1f) & 6U) != 0) && (pcVar9->sym->def != (c2_tuple *)0x0)) {
        return;
      }
      if (pcVar9->kind == 7) {
        return;
      }
      pcVar13 = (t->u24).cases;
      uVar11 = pcVar9->type;
      if (pcVar13 == (c2_switch_case *)0x0) {
        return;
      }
      do {
        if (pcVar13->lo == pcVar13->hi) {
          pcVar6 = pcVar13->label;
          pcVar3 = ((pcVar6->u14).block)->preds;
          if (((pcVar3 != (c2_edge *)0x0) && (pcVar3->next_pred == (c2_edge *)0x0)) &&
             (pcVar6->dst->next == (c2_operand *)0x0)) {
            pcVar10 = tuple_next_real(pcVar6);
            if ((pcVar10 != (c2_tuple *)0x0) && (uVar2 = pcVar10->line, uVar2 != 0)) {
              g_current_line_abs = fn->line_base + (uint)uVar2;
              g_cur_line = uVar2;
            }
            uVar16 = const_normalize(uVar11,pcVar13->lo,pcVar13->lo >> 0x1f);
            src = operand_new_intconst(uVar11,(uint32_t)uVar16,(int32_t)(uVar16 >> 0x20));
            pcVar6 = tuple_new(0x15b,uVar11,pcVar9,src,tuple_insert_after,pcVar6);
            pcVar6->flags13 = '\x01';
            number_assignment(pcVar6,1);
          }
        }
        pcVar13 = pcVar13->next;
      } while (pcVar13 != (c2_switch_case *)0x0);
      return;
    }
    pcVar6 = t->prev;
    if ((1 << (t->src->kind & 0x1f) & 6U) == 0) {
      return;
    }
    if (pcVar6 == (c2_tuple *)0x0) {
      return;
    }
    if (pcVar6->op != 399) {
      return;
    }
    pcVar10 = pcVar6->prev;
    if (pcVar10 == (c2_tuple *)0x0) {
      return;
    }
    if (pcVar10->op != 0x17d) {
      return;
    }
    iVar8 = operand_compare(t->src,pcVar6->dst);
    if (iVar8 != 0) {
      return;
    }
    pcVar9 = pcVar6->src;
    iVar8 = operand_compare(pcVar9,pcVar10->dst);
    if (iVar8 != 0) {
      return;
    }
    if ((pcVar6->u20).cc != '\x01') {
      return;
    }
    pcVar9 = pcVar9->next;
    if (pcVar9->kind != '\a') {
      return;
    }
    pcVar12 = pcVar9->next;
    if (pcVar12->kind != '\a') {
      return;
    }
    if ((pcVar9->u18).reg == (c2_symbol *)0x0 && pcVar9->tag == 0) {
      return;
    }
    if ((pcVar12->u18).reg != (c2_symbol *)0x0 || pcVar12->tag != 0) {
      return;
    }
    pcVar9 = pcVar10->src;
    if (pcVar9->kind == '\a') {
      pcVar12 = pcVar9->next;
      if (pcVar12->kind == '\a') {
        return;
      }
    }
    else {
      pcVar12 = pcVar9;
      pcVar9 = pcVar9->next;
    }
    if ((1 << (pcVar12->kind & 0x1f) & 6U) == 0) {
      return;
    }
    if (pcVar12->sym->def != (c2_tuple *)0x0) {
      return;
    }
    if (t->next == (c2_tuple *)0x0) {
      return;
    }
    pcVar6 = tuple_next_real(t);
    if ((pcVar6 != (c2_tuple *)0x0) && (uVar2 = pcVar6->line, uVar2 != 0)) {
      g_current_line_abs = fn->line_base + (uint)uVar2;
      g_cur_line = uVar2;
    }
    uVar11 = pcVar10->type;
    anchor = t;
  }
  pcVar6 = tuple_new(0x15b,uVar11,pcVar12,pcVar9,tuple_insert_after,anchor);
  pcVar6->flags13 = '\x01';
  number_assignment(pcVar6,1);
  return;
}

