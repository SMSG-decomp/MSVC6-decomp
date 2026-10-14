c2_tuple * __fastcall
x87_find_split_point(c2_live_range *lr,c2_tuple *from,c2_tuple *to,c2_bitset *live)

{
  c2_block *pcVar1;
  c2_live_range *pcVar2;
  uint32_t uVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  c2_tuple *pcVar7;
  c2_edge *pcVar8;
  c2_block *local_8;
  
  local_8 = (c2_block *)0x0;
  pcVar7 = from;
  if (from != (c2_tuple *)0x0) {
    while( true ) {
      if ((from->flags & 1) != 0) {
        for (pcVar4 = from->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((pcVar4->kind == '\x01') && ((pcVar4->flags11 & 0x10) != 0)) &&
             (pcVar7 = from, (pcVar4->u18).reg == (c2_symbol *)lr)) goto joined_r0x107797b3;
        }
      }
      from = from->prev;
      pcVar7 = from;
      if (from == (c2_tuple *)0x0) break;
      if (from->kind == '\x19') {
        return (c2_tuple *)0x0;
      }
    }
  }
joined_r0x107797b3:
  do {
    if (from == (c2_tuple *)0x0) {
      if (to != (c2_tuple *)0x0) {
        return (c2_tuple *)0x0;
      }
LAB_1077981d:
      if (local_8 != (c2_block *)0x0) {
        uVar5 = lr->id;
        bitset_set(local_8->live_in,uVar5);
        bitset_set(local_8->live,uVar5);
        lr->last_block = local_8;
      }
      pcVar6 = pcVar7;
      if ((pcVar7->flags & 1) != 0) {
        while (((pcVar6->flags & 1) == 0 ||
               (pcVar4 = find_src_reg_operand((c2_symbol *)lr,pcVar6), pcVar4 == (c2_operand *)0x0))
              ) {
          pcVar6 = pcVar6->prev;
        }
        pcVar4->flags11 = pcVar4->flags11 & 0xef;
      }
      pcVar6 = tuple_new_pseudo(0x19e,0x4008);
      pcVar4 = operand_new_reg(0x149,0x4008,lr->sym,(c2_symbol *)lr);
      tuple_append_src(pcVar6,pcVar4);
      pcVar6->src->flags11 = pcVar6->src->flags11 | 0x10;
      tuple_insert_before(to,pcVar6);
      if ((pcVar7->flags & 1) != 0) {
        pcVar6->flags = pcVar6->flags & 0xf | 0x10;
      }
      return pcVar6;
    }
    if (from == to) goto LAB_1077981d;
    if ((from->flags & 1) == 0) {
      if ((from->kind == '\x19') && (pcVar1 = (from->u14).block, pcVar1 != (c2_block *)0x0)) {
        if (local_8 != (c2_block *)0x0) {
          return (c2_tuple *)0x0;
        }
        pcVar8 = pcVar1->preds;
        local_8 = pcVar1;
        if (pcVar8 != (c2_edge *)0x0) {
          uVar5 = lr->id;
          do {
            uVar3 = bitset_test(pcVar8->from->live_out,uVar5);
            if (uVar3 == 0) {
              return (c2_tuple *)0x0;
            }
            pcVar8 = pcVar8->next_pred;
          } while (pcVar8 != (c2_edge *)0x0);
        }
      }
    }
    else {
      pcVar4 = from->dst;
      if (((pcVar4 != (c2_operand *)0x0) && ((pcVar4->type & 0xf000) == 0x4000)) &&
         ((pcVar4->kind == '\x01' && (((pcVar4->u18).reg)->cls == '\x02')))) {
        return (c2_tuple *)0x0;
      }
      for (pcVar4 = from->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if ((((((pcVar4->type & 0xf000) == 0x4000) && (pcVar4->kind == '\x01')) &&
             ((pcVar4->flags11 & 0x10) != 0)) &&
            ((pcVar2 = (pcVar4->u18).range, pcVar2->kind == '\x02' &&
             (pcVar2->colour != (c2_register_descriptor *)0x0)))) &&
           (uVar5 = bitset_test(live,pcVar2->id), uVar5 == 0)) {
          return (c2_tuple *)0x0;
        }
      }
      if (from->flags12 == '\b') {
        return (c2_tuple *)0x0;
      }
    }
    from = from->next;
  } while( true );
}

