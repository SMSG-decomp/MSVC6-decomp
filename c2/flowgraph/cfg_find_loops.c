int __fastcall cfg_find_loops(c2_function *fn,int mode)

{
  short sVar1;
  c2_block *to;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_loop *pcVar4;
  c2_edge *edge;
  c2_loop *pcVar5;
  c2_loop *pcVar6;
  c2_loop *pcVar7;
  int iVar8;
  c2_tuple *pcVar9;
  c2_fe_symbol *label_sym;
  c2_loop *loop;
  uint32_t uVar10;
  c2_edge *pcVar11;
  c2_block *pcVar12;
  c2_edge *local_20;
  int local_18;
  c2_block *local_14;
  c2_loop *local_c;
  
  local_c = loop_alloc();
  fn->loops = local_c;
  to = fn->cfg->first;
  for (pcVar12 = to; local_18 = mode, pcVar12 != (c2_block *)0x0; pcVar12 = pcVar12->next) {
    pcVar12->loop = (c2_loop *)0x0;
  }
  do {
    if (to == (c2_block *)0x0) {
      fn->loops = fn->loops->next;
      return local_18;
    }
    pcVar11 = to->preds;
    pcVar12 = to;
    if (pcVar11 == (c2_edge *)0x0) {
LAB_10704ccd:
      local_20 = to->preds;
      if (local_20 != (c2_edge *)0x0) {
        sVar1 = to->rpo;
        do {
          pcVar12 = local_20->from;
          iVar8 = bitvec_test(pcVar12->dominators,(int)sVar1);
          if ((iVar8 != 0) && (sVar1 <= pcVar12->rpo)) {
            if (local_18 != 0) goto LAB_10704e0c;
            local_14 = to->prev;
            if (local_14->loop != to->loop) {
              local_18 = 1;
              goto LAB_10704e0c;
            }
            pcVar11 = to->preds;
            if (pcVar11 == (c2_edge *)0x0) goto LAB_10704e5e;
            pcVar3 = to->head->next;
            goto LAB_10704dc2;
          }
          local_20 = local_20->next_pred;
        } while (local_20 != (c2_edge *)0x0);
      }
    }
    else {
      do {
        pcVar2 = pcVar11->from;
        iVar8 = bitvec_test((c2_bitvec *)pcVar2->x64,(int)to->rpo);
        if (((iVar8 != 0) && (iVar8 = bitvec_test(pcVar2->dominators,(int)to->rpo), iVar8 == 0)) &&
           (pcVar12->rpo < pcVar2->rpo)) {
          pcVar12 = pcVar2;
        }
        pcVar11 = pcVar11->next_pred;
      } while (pcVar11 != (c2_edge *)0x0);
      if (pcVar12 == to) goto LAB_10704ccd;
      loop = loop_alloc();
      loop->guard = to;
      loop->first = to;
      loop->flags = loop->flags | 1;
      loop->last = pcVar12;
      local_14 = to;
LAB_10704e94:
      pcVar4 = to->loop;
      if (pcVar4 == (c2_loop *)0x0) {
        local_c->next = loop;
        local_c = loop;
      }
      else {
        pcVar7 = pcVar4->inner;
        pcVar6 = (c2_loop *)&pcVar4->inner;
        while (pcVar5 = pcVar7, pcVar5 != (c2_loop *)0x0) {
          pcVar6 = pcVar5;
          pcVar7 = pcVar5->next;
        }
        pcVar6->next = loop;
        loop->parent = pcVar4;
        if (local_18 != 0) {
          local_14->loop = pcVar4;
        }
      }
      if (((fn->flags & 0x10000) != 0) || ((fn->fsym->attrs & 0x1000) != 0)) {
        loop_mark_eh_entry(loop);
      }
      if ((loop->flags & 1) == 0) {
        loop_collect_body(loop,loop->last);
      }
      else {
        for (pcVar4 = loop->parent; pcVar4 != (c2_loop *)0x0; pcVar4 = pcVar4->parent) {
          pcVar4->flags = pcVar4->flags | 1;
        }
        pcVar12 = loop->last;
        for (pcVar2 = to; pcVar2 != pcVar12; pcVar2 = pcVar2->next) {
          pcVar2->loop = loop;
        }
        pcVar2->loop = loop;
      }
    }
    to = to->next;
  } while( true );
LAB_10704dc2:
  pcVar12 = pcVar11->from;
  pcVar9 = pcVar12->end->prev;
  if ((((1 << (pcVar9->kind & 0x1f) & 0xa0000U) == 0) || (pcVar3->kind != '\x1a')) ||
     ((pcVar9 = branch_targets_label(pcVar9,pcVar3), pcVar9 == (c2_tuple *)0x0 ||
      (iVar8 = bitvec_test(pcVar12->dominators,(int)sVar1), iVar8 != 0)))) goto LAB_10704db7;
  local_18 = 1;
LAB_10704e0c:
  label_sym = label_symbol_new();
  pcVar9 = tuple_new_label(label_sym);
  pcVar3 = to->head->next;
  tuple_insert_before(to->head,pcVar9);
  local_14 = block_split_before(fn,to->prev,pcVar9);
  pcVar11 = to->preds;
  while (edge = pcVar11, edge != (c2_edge *)0x0) {
    sVar1 = to->rpo;
    pcVar11 = edge->next_pred;
    pcVar12 = edge->from;
    iVar8 = bitvec_test(pcVar12->dominators,(int)sVar1);
    if (((iVar8 == 0) || (pcVar12->rpo < sVar1)) &&
       (uVar10 = redirect_branch_edge(edge,pcVar9,pcVar3,fn), uVar10 == 0)) {
      cfg_edge_redirect(edge,local_14,fn);
    }
  }
  cfg_add_edge(fn,local_14,to);
LAB_10704e5e:
  loop = loop_alloc();
  loop->last = local_20->from;
  pcVar11 = to->preds;
  loop->first = to;
  for (; pcVar11 != (c2_edge *)0x0; pcVar11 = pcVar11->next_pred) {
    if (loop->last->rpo < pcVar11->from->rpo) {
      loop->last = pcVar11->from;
    }
  }
  goto LAB_10704e94;
LAB_10704db7:
  pcVar11 = pcVar11->next_pred;
  if (pcVar11 == (c2_edge *)0x0) goto LAB_10704e5e;
  goto LAB_10704dc2;
}

