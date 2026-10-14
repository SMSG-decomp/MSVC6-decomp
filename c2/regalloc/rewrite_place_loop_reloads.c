int __fastcall
rewrite_place_loop_reloads(c2_loop *loop,c2_tuple *reload,c2_symbol *sym,c2_function *fn)

{
  byte bVar1;
  int16_t iVar2;
  uint32_t uVar3;
  c2_loop_exit *pcVar4;
  c2_block *pred;
  c2_edge *pcVar5;
  c2_block *succ;
  c2_tuple *pos;
  c2_loop *pcVar6;
  bool bVar7;
  c2_edge *edge;
  uint32_t uVar8;
  c2_tuple *pcVar9;
  c2_tuple *pcVar10;
  c2_block *pcVar11;
  c2_bitset *pcVar12;
  c2_bitset *pcVar13;
  c2_loop *pcVar14;
  c2_loop_exit *pcVar15;
  c2_loop *local_18;
  c2_live_range *reload_range;
  
  reload_range = (reload->src->u18).range;
  local_18 = loop;
  if (loop->parent != (c2_loop *)0x0) {
    uVar3 = ((sym->u30).ra)->id;
    pcVar6 = loop->parent;
    local_18 = loop;
    do {
      pcVar14 = pcVar6;
      uVar8 = bitset_test(pcVar14->candidates,uVar3);
      if (uVar8 != 0) break;
      pcVar6 = pcVar14->parent;
      local_18 = pcVar14;
    } while (pcVar14->parent != (c2_loop *)0x0);
  }
  pcVar4 = local_18->exits;
  if (pcVar4 != (c2_loop_exit *)0x0) {
    uVar3 = reload_range->id;
    pcVar15 = pcVar4;
    do {
      uVar8 = bitset_test(pcVar15->block->live_out,uVar3);
      if (uVar8 == 0) {
        return 0;
      }
      pcVar15 = pcVar15->next;
    } while (pcVar15 != (c2_loop_exit *)0x0);
  }
joined_r0x10768b81:
  if (pcVar4 == (c2_loop_exit *)0x0) {
    return 1;
  }
  pred = pcVar4->block;
  pcVar5 = pred->succs;
joined_r0x10768b93:
  do {
    edge = pcVar5;
    if (edge == (c2_edge *)0x0) break;
    pcVar5 = edge->next_succ;
    succ = edge->to;
    if (succ->loop != local_18) {
      pcVar11 = succ;
      if (succ->preds->next_pred != (c2_edge *)0x0) {
        pcVar11 = split_edge_with_new_block(fn,edge,pred,succ);
        pcVar13 = succ->set24;
        pcVar12 = bitset_clone(pcVar13);
        pcVar11->set24 = pcVar12;
        pcVar13 = bitset_clone(pcVar13);
        iVar2 = succ->loop_depth;
        pcVar11->set28 = pcVar13;
        pcVar6 = succ->loop;
        pcVar11->loop_depth = iVar2;
        pcVar11->loop = pcVar6;
      }
      pos = pcVar11->head;
      pcVar10 = pcVar11->end;
      bVar7 = false;
      pcVar9 = pos;
      if (pos != pcVar10) {
        do {
          if (((pcVar9->op == 0x164) && (pcVar9->dst->sym == sym)) &&
             ((pcVar9->src->u18).reg == (c2_symbol *)reload_range)) {
            bVar7 = true;
          }
          pcVar9 = pcVar9->next;
        } while (pcVar9 != pcVar10);
        if (bVar7) goto joined_r0x10768b93;
      }
      bVar1 = pos->flags;
      while ((((bVar1 & 1) == 0 && (pos->kind != '\x18')) && (pos != pcVar10))) {
        pos = pos->next;
        bVar1 = pos->flags;
      }
      pcVar10 = (c2_tuple *)node_clone((c2_node *)reload);
      tuple_insert_before(pos,pcVar10);
      bitset_set(pcVar11->set24,reload_range->colour->id);
    }
  } while( true );
  pcVar4 = pcVar4->next;
  goto joined_r0x10768b81;
}

