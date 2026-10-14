void __fastcall split_live_ranges_at_markers(c2_function *fn,c2_bitset *ranges,int reg_class)

{
  byte bVar1;
  c2_block *pcVar2;
  c2_bitset *pcVar3;
  c2_ra_split_block *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *pcVar6;
  c2_ra_split_block *tail;
  c2_tuple *t;
  uint32_t uVar7;
  c2_live_range *lr;
  c2_live_range *pcVar8;
  int iVar9;
  c2_register_descriptor *pcVar10;
  uint uVar11;
  c2_ra_split_block *head;
  c2_live_range *pcVar12;
  c2_ra_split_block *local_c;
  c2_ra_split_block *local_8;
  
  uVar7 = bitset_iter_next(ranges);
  lr = live_range_from_id(uVar7);
  head = (c2_ra_split_block *)0x0;
  lr->colour = (c2_register_descriptor *)0x0;
  (lr->u14).queue_next = (c2_live_range *)0x0;
  uVar7 = bitset_iter_next((c2_bitset *)0x0);
  pcVar12 = lr;
  while (uVar7 != 0xffffffff) {
    pcVar8 = live_range_from_id(uVar7);
    bVar1 = pcVar8->flags5;
    (pcVar8->u14).queue_next = (c2_live_range *)0x0;
    (pcVar12->u14).queue_next = pcVar8;
    pcVar8->colour = (c2_register_descriptor *)0x0;
    pcVar8->flags5 = bVar1 & 0xfd;
    uVar7 = bitset_iter_next((c2_bitset *)0x0);
    pcVar12 = pcVar8;
  }
  local_c = (c2_ra_split_block *)0x0;
  local_8 = (c2_ra_split_block *)0x0;
  tail = local_c;
  pcVar4 = local_8;
  for (pcVar2 = fn->cfg->first; pcVar8 = lr, pcVar12 = lr, pcVar2 != (c2_block *)0x0;
      pcVar2 = pcVar2->next) {
    iVar9 = bitset_intersects(pcVar2->live,ranges);
    local_8 = pcVar4;
    if (iVar9 == 0) {
      uVar11 = pcVar2->flags;
      pcVar2->flags = uVar11 & 0xfffffffe;
      local_c = tail;
      if ((uVar11 & 0x40000) != 0) {
        pcVar5 = pcVar2->end;
        pcVar2->flags = uVar11 & 0xfffbfffe;
        pcVar6 = pcVar2->head;
        while (t = pcVar6, t != pcVar5) {
          pcVar6 = t->next;
          head = pcVar4;
          if (t->kind == '\x1b') {
            bitset_free((t->u14).regs);
            (t->u14).arg = (void *)0x0;
            tuple_unlink_free(t);
          }
        }
      }
    }
    else {
      local_c = alloc_split_node();
      local_c->block = pcVar2;
      local_c->next = (c2_ra_split_block *)0x0;
      local_c->prev = tail;
      local_8 = local_c;
      if (tail != (c2_ra_split_block *)0x0) {
        tail->next = local_c;
        local_8 = pcVar4;
      }
      uVar11 = pcVar2->flags & 0xfffbffff;
      pcVar2->flags = uVar11;
      bitset_andnot(pcVar2->live_in,ranges);
      bitset_andnot(pcVar2->live_out,ranges);
      pcVar3 = pcVar2->set28;
      local_c->saved_regs_in = pcVar2->set24;
      local_c->saved_regs_out = pcVar3;
      pcVar2->flags = uVar11 | 1;
      head = local_8;
    }
    tail = local_c;
    pcVar4 = local_8;
  }
  do {
    pcVar10 = (c2_register_descriptor *)0x1;
    for (; pcVar12 != (c2_live_range *)0x0; pcVar12 = (pcVar12->u14).queue_next) {
      pcVar12->colour = pcVar10;
      pcVar10 = (c2_register_descriptor *)((int)pcVar10 << 1);
      pcVar12->flags5 = pcVar12->flags5 | 2;
      if (pcVar10 == (c2_register_descriptor *)0x0) {
        if (pcVar12 != (c2_live_range *)0x0) {
          pcVar12 = (pcVar12->u14).queue_next;
          goto LAB_10723be1;
        }
        break;
      }
    }
    pcVar12 = (c2_live_range *)0x0;
LAB_10723be1:
    uVar7 = split_resolve_markers_in_blocks(head,ranges);
    split_solve_region_bits(head,tail,uVar7);
    split_range_partition_cells(pcVar8);
    split_insert_spill_stores(fn,head);
    pcVar4 = head;
    if (pcVar12 == (c2_live_range *)0x0) {
      while (pcVar4 != (c2_ra_split_block *)0x0) {
        pcVar2 = pcVar4->block;
        pcVar3 = pcVar4->saved_regs_in;
        pcVar2->set28 = pcVar4->saved_regs_out;
        pcVar2->set24 = pcVar3;
        bitset_andnot(pcVar2->live,ranges);
        pcVar4 = pcVar4->next;
        pcVar2->flags = pcVar2->flags & 0xfffffffe;
      }
      bitset_free(ranges);
      for (pcVar12 = lr; pcVar12 != (c2_live_range *)0x0; pcVar12 = (pcVar12->u14).queue_next) {
        pcVar12->flags5 = pcVar12->flags5 | 2;
      }
      build_split_pieces(fn,head,g_class_candidates[reg_class]);
      while (lr != (c2_live_range *)0x0) {
        pcVar12 = (lr->u14).queue_next;
        free_live_range(lr,0);
        lr = pcVar12;
      }
      return;
    }
    for (; pcVar8 != pcVar12; pcVar8 = (pcVar8->u14).queue_next) {
      pcVar8->colour = (c2_register_descriptor *)0x0;
      pcVar8->flags5 = pcVar8->flags5 & 0xfd;
    }
  } while( true );
}

