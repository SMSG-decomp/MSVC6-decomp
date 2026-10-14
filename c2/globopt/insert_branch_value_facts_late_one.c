void __fastcall insert_branch_value_facts_late_one(c2_function *fn,c2_tuple *t,c2_block *block)

{
  ushort uVar1;
  uint16_t type;
  c2_edge *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *pcVar7;
  uint32_t uVar8;
  c2_block *pcVar9;
  int iVar10;
  c2_const_operand *b;
  byte bVar11;
  c2_operand *local_4;
  
  if (t->op == 0x1ab) {
    pcVar6 = t->prev;
    if ((1 << (byte)(t->type >> 0xc) & 0xeU) != 0) {
      if ((((((1 << (t->src->kind & 0x1f) & 6U) != 0) && (pcVar6 != (c2_tuple *)0x0)) &&
           (pcVar6->op == 399)) &&
          ((pcVar7 = pcVar6->prev, pcVar7 != (c2_tuple *)0x0 && (pcVar7->op == 0x17d)))) &&
         (iVar10 = operand_compare(t->src,pcVar6->dst), iVar10 == 0)) {
        pcVar3 = pcVar6->src;
        iVar10 = operand_compare(pcVar3,pcVar7->dst);
        if (iVar10 == 0) {
          pcVar4 = pcVar7->src;
          if (((pcVar4->kind != '\a') || (pcVar4->next->kind != '\a')) &&
             ((pcVar3 = pcVar3->next, pcVar3->kind == '\a' &&
              (pcVar5 = pcVar3->next, pcVar5->kind == '\a')))) {
            if (((pcVar3->u18).reg != (c2_symbol *)0x0 || pcVar3->tag != 0) !=
                ((pcVar5->u18).reg != (c2_symbol *)0x0 || pcVar5->tag != 0)) {
              bVar11 = (pcVar6->u20).cc;
              if ((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0) {
                bVar11 = g_cond_inverse[bVar11];
              }
              uVar8 = expr_table_dispatch_by_kind(bVar11);
              uVar1 = t->line;
              if (uVar1 != 0) {
                g_current_line_abs = fn->line_base + (uint)uVar1;
                g_cur_line = uVar1;
              }
              pcVar6 = tuple_new_cse_binary
                                 (uVar8,pcVar7->type,pcVar4,pcVar4->next,tuple_insert_after,t);
              pcVar6->flags13 = '\x02';
              return;
            }
          }
        }
      }
      type = t->type;
      pcVar3 = t->src;
      b = operand_new_intconst(type,0,0);
      uVar1 = t->line;
      if (uVar1 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar1;
        g_cur_line = uVar1;
      }
      pcVar6 = tuple_new_cse_binary(0x17f,type,pcVar3,b,tuple_insert_after,t);
      pcVar6->flags13 = '\x02';
      return;
    }
  }
  else {
    pcVar2 = block->succs;
    if ((((pcVar2 != (c2_edge *)0x0) &&
         ((pcVar3 = t->src, (1 << (pcVar3->kind & 0x1f) & 6U) == 0 ||
          (pcVar3->sym->def == (c2_tuple *)0x0)))) &&
        (((1 << (pcVar3->next->kind & 0x1f) & 6U) == 0 ||
         (pcVar3->next->sym->def == (c2_tuple *)0x0)))) &&
       (((pcVar6 = find_next_use_of_dst(t,&local_4), pcVar6->kind == '\x11' &&
         (pcVar7 = tuple_next_real_before_boundary(t), pcVar7 == pcVar6)) &&
        (pcVar2->next_succ != (c2_edge *)0x0)))) {
      pcVar3 = t->src;
      pcVar4 = pcVar3->next;
      if (((1 << (pcVar3->kind & 0x1f) & 0x380U) == 0) ||
         ((1 << (pcVar4->kind & 0x1f) & 0x380U) == 0)) {
        bVar11 = (byte)pcVar6->type;
        uVar8 = expr_table_dispatch_by_kind(bVar11);
        pcVar6 = *(c2_tuple **)&(pcVar6->src->sym->u30).globopt.marks;
        pcVar9 = (pcVar6->u14).block;
        if (pcVar9 == (c2_block *)0x0) {
          pcVar7 = tuple_find_prev_of_kind(pcVar6,'\x19');
          pcVar9 = (pcVar7->u14).block;
        }
        if ((pcVar9->preds != (c2_edge *)0x0) && (pcVar9->preds->next_pred == (c2_edge *)0x0)) {
          uVar1 = pcVar6->line;
          if (uVar1 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar1;
            g_cur_line = uVar1;
          }
          pcVar6 = tuple_new_cse_binary(uVar8,t->type,pcVar3,pcVar4,tuple_insert_after,pcVar6);
          pcVar6->flags13 = '\x02';
        }
        uVar8 = expr_table_dispatch_by_kind(g_cond_inverse[bVar11]);
        pcVar6 = block->next->head;
        pcVar2 = block->next->preds;
        if ((pcVar2 != (c2_edge *)0x0) && (pcVar2->next_pred == (c2_edge *)0x0)) {
          pcVar7 = tuple_next_real_in_block(pcVar6);
          if ((pcVar7 != (c2_tuple *)0x0) && (uVar1 = pcVar7->line, uVar1 != 0)) {
            g_current_line_abs = fn->line_base + (uint)uVar1;
            g_cur_line = uVar1;
          }
          pcVar6 = tuple_new_cse_binary(uVar8,t->type,pcVar3,pcVar4,tuple_insert_after,pcVar6);
          pcVar6->flags13 = '\x02';
        }
      }
    }
  }
  return;
}

