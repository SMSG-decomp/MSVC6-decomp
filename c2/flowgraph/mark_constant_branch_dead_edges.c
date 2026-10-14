void __fastcall mark_constant_branch_dead_edges(c2_function *fn)

{
  uint32_t *puVar1;
  c2_block *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  bool bVar7;
  c2_tuple *pcVar8;
  int iVar9;
  c2_edge *pcVar10;
  c2_block *pcVar11;
  c2_block *to;
  uint uVar12;
  uint32_t uVar13;
  c2_edge *local_8;
  
  pcVar2 = fn->cfg->first;
  for (pcVar11 = pcVar2; pcVar11 != (c2_block *)0x0; pcVar11 = pcVar11->next) {
    local_8 = (c2_edge *)0x0;
    pcVar8 = tuple_prev_real_before_boundary(pcVar11->end);
    if ((((pcVar8 != (c2_tuple *)0x0) && (pcVar8->kind == '\x11')) &&
        (((pcVar8->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar8->op == 0x18b)))) &&
       ((pcVar8->flags & 8) == 0)) {
      pcVar3 = pcVar8->src;
      pcVar4 = pcVar3->next->sym->def;
      if (((pcVar4->op == 0x17d) && (pcVar5 = pcVar4->src, pcVar5->kind == '\a')) &&
         (pcVar6 = pcVar5->next, pcVar6->kind == '\a')) {
        iVar9 = fold_constant_compare
                          ((uint)((pcVar4->type & 0xf000) == 0x1000),pcVar4->type & 0xfff,
                           (pcVar5->u18).lo,pcVar5->tag,(pcVar6->u18).lo,pcVar6->tag,
                           (uint8_t)pcVar8->type);
        if (iVar9 == 0) {
          to = *(c2_block **)(*(int *)((int)&pcVar3->sym->u30 + 2) + 0x14);
        }
        else {
          to = pcVar11->next;
        }
        local_8 = flow_edge_find(pcVar11,to);
      }
    }
    uVar12 = pcVar11->flags;
    for (pcVar10 = pcVar11->succs; pcVar10 != (c2_edge *)0x0; pcVar10 = pcVar10->next_succ) {
      if (((uVar12 & 1) == 0) || (pcVar10 == local_8)) {
        uVar13 = pcVar10->flags & 0xfffffffe;
      }
      else {
        uVar13 = pcVar10->flags | 1;
      }
      pcVar10->flags = uVar13;
    }
  }
  do {
    bVar7 = false;
    pcVar11 = pcVar2;
    if (pcVar2 == (c2_block *)0x0) {
      return;
    }
    do {
      if (((pcVar11->flags & 1) != 0) && (pcVar10 = pcVar11->preds, pcVar10 != (c2_edge *)0x0)) {
        uVar12 = 0;
        if (pcVar10 != (c2_edge *)0x0) {
          do {
            puVar1 = &pcVar10->flags;
            pcVar10 = pcVar10->next_pred;
            uVar12 = uVar12 | *puVar1 & 1;
          } while (pcVar10 != (c2_edge *)0x0);
          if (uVar12 != 0) goto LAB_1072a468;
        }
        pcVar10 = pcVar11->succs;
        bVar7 = true;
        pcVar11->flags = pcVar11->flags & 0xfffffffe;
        for (; pcVar10 != (c2_edge *)0x0; pcVar10 = pcVar10->next_succ) {
          pcVar10->flags = pcVar10->flags & 0xfffffffe;
        }
      }
LAB_1072a468:
      pcVar11 = pcVar11->next;
    } while (pcVar11 != (c2_block *)0x0);
    if (!bVar7) {
      return;
    }
  } while( true );
}

