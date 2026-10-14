void __fastcall split_range_partition_cells(c2_live_range *lr)

{
  c2_edge *pcVar1;
  c2_bitset *bs;
  uint32_t n;
  c2_block *pcVar2;
  c2_register_descriptor *pcVar3;
  c2_split_uf_cell **ppcVar4;
  uint uVar5;
  c2_live_range *pcVar6;
  uint uVar7;
  c2_block *pcVar8;
  c2_split_uf_cell *pcVar9;
  c2_split_uf_cell *pcVar10;
  c2_split_uf_cell *pcVar11;
  c2_split_uf_cell *local_14;
  c2_split_uf_cell *entry_cell;
  c2_split_uf_cell *exit_cell;
  
joined_r0x10724285:
  if ((lr == (c2_live_range *)0x0) || (pcVar3 = lr->colour, pcVar3 == (c2_register_descriptor *)0x0)
     ) {
    return;
  }
  pcVar8 = lr->first_block;
  local_14 = (c2_split_uf_cell *)0x0;
  do {
    if ((pcVar8->flags & 1) != 0) {
      uVar5 = (uint)pcVar8->set24 & (uint)pcVar3;
      pcVar9 = (c2_split_uf_cell *)0x0;
      pcVar11 = (c2_split_uf_cell *)0x0;
      uVar7 = (uint)pcVar8->set28 & (uint)pcVar3;
      if (uVar5 != 0) {
        for (pcVar1 = pcVar8->preds; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
          pcVar10 = (pcVar1->from->avail_out).split_cell;
          if (pcVar10 != (c2_split_uf_cell *)0x0) {
            if (pcVar9 == (c2_split_uf_cell *)0x0) {
              (pcVar8->avail_in).split_cell = pcVar10;
              pcVar9 = pcVar10;
            }
            else if (pcVar9 != pcVar10) {
              union_find_link(pcVar9,pcVar10);
            }
          }
        }
        if ((uVar7 == 0) || (((uint)pcVar8->kill & (uint)pcVar3) != 0)) {
          if (pcVar9 != (c2_split_uf_cell *)0x0) goto LAB_107243af;
          pcVar9 = alloc_split_cell_c();
          pcVar9->next = local_14;
          local_14 = pcVar9;
        }
        else {
          for (pcVar1 = pcVar8->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
            pcVar11 = (pcVar1->to->avail_in).split_cell;
            pcVar10 = pcVar9;
            if (((pcVar11 != (c2_split_uf_cell *)0x0) &&
                (pcVar10 = pcVar11, pcVar9 != (c2_split_uf_cell *)0x0)) &&
               (pcVar10 = pcVar9, pcVar9 != pcVar11)) {
              union_find_link(pcVar9,pcVar11);
            }
            pcVar9 = pcVar10;
          }
          pcVar11 = pcVar9;
          if (pcVar9 == (c2_split_uf_cell *)0x0) {
            pcVar9 = alloc_split_cell_c();
            pcVar9->next = local_14;
            pcVar11 = pcVar9;
            local_14 = pcVar9;
          }
        }
        (pcVar8->avail_in).split_cell = pcVar9;
      }
LAB_107243af:
      if ((uVar7 != 0) && ((uVar5 == 0 || (((uint)pcVar3 & (uint)pcVar8->kill) != 0)))) {
        for (pcVar1 = pcVar8->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
          pcVar9 = (pcVar1->to->avail_in).split_cell;
          pcVar10 = pcVar11;
          if (((pcVar9 != (c2_split_uf_cell *)0x0) &&
              (pcVar10 = pcVar9, pcVar11 != (c2_split_uf_cell *)0x0)) &&
             (pcVar10 = pcVar11, pcVar11 != pcVar9)) {
            union_find_link(pcVar11,pcVar9);
          }
          pcVar11 = pcVar10;
        }
        if (pcVar11 == (c2_split_uf_cell *)0x0) {
          pcVar11 = alloc_split_cell_c();
          pcVar11->next = local_14;
          local_14 = pcVar11;
        }
      }
      (pcVar8->avail_out).split_cell = pcVar11;
      if (pcVar8 == lr->last_block) break;
    }
    pcVar8 = pcVar8->next;
  } while( true );
  bs = lr->allowed;
  bitset_clear_all(bs);
  pcVar9 = local_14;
  if (local_14 != (c2_split_uf_cell *)0x0) {
    do {
      if (pcVar9->parent == (c2_split_uf_cell *)0x0) {
        pcVar6 = new_live_range(lr->sym);
        pcVar6->tie = lr->tie;
        n = pcVar6->id;
        pcVar9->piece_id = n;
        (pcVar6->u14).queue_next = lr;
        bitset_set(bs,n);
      }
      ppcVar4 = &pcVar9->next;
      pcVar11 = local_14;
      pcVar9 = *ppcVar4;
    } while (*ppcVar4 != (c2_split_uf_cell *)0x0);
    do {
      pcVar10 = pcVar11;
      pcVar9 = pcVar10->parent;
      if (pcVar9 != (c2_split_uf_cell *)0x0) {
        for (pcVar11 = pcVar9->parent; pcVar11 != (c2_split_uf_cell *)0x0; pcVar11 = pcVar11->parent
            ) {
          pcVar9 = pcVar11;
        }
        pcVar10->piece_id = pcVar9->piece_id;
      }
      pcVar11 = pcVar10->next;
    } while (pcVar10->next != (c2_split_uf_cell *)0x0);
    pcVar9 = local_14;
    pcVar10->next = g_split_uf_cell_free;
    g_split_uf_cell_free = pcVar9;
    pcVar8 = lr->first_block;
    pcVar2 = lr->last_block;
    while( true ) {
      entry_cell = (pcVar8->avail_in).split_cell;
      if (entry_cell != (c2_split_uf_cell *)0x0) {
        bitset_set(pcVar8->live_in,entry_cell->piece_id);
        bitset_set(pcVar8->live,entry_cell->piece_id);
        (pcVar8->avail_in).set = (c2_bitset *)0x0;
      }
      exit_cell = (pcVar8->avail_out).split_cell;
      if (exit_cell != (c2_split_uf_cell *)0x0) {
        bitset_set(pcVar8->live_out,exit_cell->piece_id);
        bitset_set(pcVar8->live,exit_cell->piece_id);
        (pcVar8->avail_out).set = (c2_bitset *)0x0;
      }
      if (pcVar8 == pcVar2) break;
      pcVar8 = pcVar8->next;
    }
  }
  lr = (lr->u14).queue_next;
  goto joined_r0x10724285;
}

