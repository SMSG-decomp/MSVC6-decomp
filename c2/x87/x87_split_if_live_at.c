int32_t __fastcall x87_split_if_live_at(c2_tuple *t,c2_live_range *lr)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  c2_bitset *bs;
  c2_tuple *pcVar6;
  
  pcVar2 = tuple_get_block_nonnull(t);
  uVar4 = lr->id;
  uVar3 = bitset_test(pcVar2->live,uVar4);
  if (uVar3 != 0) {
    uVar4 = bitset_test(pcVar2->live_in,uVar4);
    pcVar6 = pcVar2->head;
    while( true ) {
      for (; (pcVar6->flags & 1) == 0; pcVar6 = pcVar6->next) {
        if (pcVar6 == t) goto LAB_1075f4a7;
      }
      if (uVar4 == 0) {
        pcVar5 = find_dst_reg_operand((c2_symbol *)lr,pcVar6);
        if (pcVar5 != (c2_operand *)0x0) {
          uVar4 = 1;
        }
      }
      else {
        pcVar5 = find_src_reg_operand((c2_symbol *)lr,pcVar6);
        if ((pcVar5 != (c2_operand *)0x0) && ((pcVar5->flags11 & 0x10) != 0)) {
          uVar4 = 0;
        }
      }
      if (pcVar6 == t) break;
      pcVar6 = pcVar6->next;
    }
LAB_1075f4a7:
    if (uVar4 != 0) {
      bs = bitset_new(6);
      bitset_set(bs,lr->id);
      insert_split_marker_after_spill(t,bs);
      if ((((t->op == 99) && (t->dst->kind == '\x01')) && (((t->dst->u18).reg)->cls == '\x02')) &&
         (t->flags13 != '\0')) {
        pcVar6 = t->next;
        uVar1 = pcVar6->kind;
        while (uVar1 != '\x19') {
          if ((((pcVar6->flags & 1) != 0) && (pcVar6->op != 0x163)) && (pcVar6->op != 0x164)) {
            if (pcVar6->flags13 == '\0') break;
            pcVar5 = find_src_reg_operand((c2_symbol *)lr,pcVar6);
            if (pcVar5 != (c2_operand *)0x0) {
              insert_split_marker_after_spill(pcVar6,bs);
              insert_split_marker_after_spill(pcVar6->prev,bs);
            }
          }
          pcVar6 = pcVar6->next;
          uVar1 = pcVar6->kind;
        }
      }
      bitset_free(bs);
      pcVar2->flags = pcVar2->flags | 0x40000;
      return 1;
    }
  }
  return 0;
}

