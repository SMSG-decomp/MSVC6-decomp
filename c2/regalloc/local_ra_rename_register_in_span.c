void __fastcall
local_ra_rename_register_in_span
          (c2_tuple *from,c2_symbol *old_reg,c2_tuple *to,c2_symbol *new_reg,int only_live)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  uint uVar5;
  c2_bitset *dst;
  c2_operand *pcVar6;
  int iVar7;
  uint32_t uVar8;
  c2_register_descriptor *pcVar9;
  uint32_t uVar10;
  
  new_reg->flags5 = (old_reg->flags5 ^ new_reg->flags5) & 0x7f ^ old_reg->flags5;
  pcVar2 = from->prev;
  uVar1 = pcVar2->kind;
  while (uVar1 != '\x19') {
    pcVar2 = pcVar2->prev;
    uVar1 = pcVar2->kind;
  }
  dst = bitset_new(6);
  if (only_live != 0) {
    bitset_copy(dst,((pcVar2->u14).block)->set24);
  }
  for (pcVar2 = pcVar2->next; pcVar2 != to; pcVar2 = pcVar2->next) {
    if ((pcVar2->flags & 1) != 0) {
      for (pcVar3 = pcVar2->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->kind == '\x01') && ((only_live == 0 || ((pcVar3->flags11 & 0x10) != 0)))) {
          pcVar4 = (pcVar3->u18).reg;
          if (pcVar4->cls == '\x01') {
            uVar10 = pcVar4->storage->id;
          }
          else {
            pcVar9 = find_register_holding_temp(pcVar4);
            if (pcVar9 == g_reg_symbols) goto LAB_1075ab84;
            uVar10 = pcVar9->id;
          }
          bitset_clear(dst,uVar10);
        }
LAB_1075ab84:
      }
      for (pcVar3 = pcVar2->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((((pcVar3->kind == '\x01') && (((pcVar3->u18).reg)->cls == '\x01')) &&
            (pcVar3->sym->cls != '\x01')) &&
           (((uVar5 = ((pcVar3->u18).reg)->storage->id, uVar5 != 0 && (uVar5 < 9)) && (uVar5 != 5)))
           ) {
          bitset_set(dst,uVar5);
        }
      }
    }
  }
  for (; to != (c2_tuple *)0x0; to = to->next) {
    if ((to->flags & 1) != 0) {
      for (pcVar3 = to->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == old_reg)) {
          (pcVar3->u18).reg = new_reg;
          pcVar6 = find_dst_reg_operand(old_reg,to);
          if (pcVar6 == (c2_operand *)0x0) goto LAB_1075aac3;
        }
      }
      for (pcVar3 = to->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (pcVar3->kind == '\x01') {
          pcVar4 = (pcVar3->u18).reg;
          if ((((pcVar4->cls == '\x01') && (uVar5 = pcVar4->storage->id, uVar5 != 0)) && (uVar5 < 9)
              ) && (uVar5 != 5)) {
            bitset_set(dst,uVar5);
          }
          else if (pcVar4 == old_reg) {
            (pcVar3->u18).reg = new_reg;
          }
        }
        else if (pcVar3->kind == '\n') {
          bitset_or(dst,(c2_bitset *)pcVar3->sym);
        }
      }
    }
  }
LAB_1075aac3:
  if ((old_reg->flags5 & 0x80) != 0) {
    bitset_set(dst,7);
    bitset_set(dst,8);
    bitset_set(dst,6);
  }
  if ((dst->chunks != (c2_bitset_chunk *)0x0) && (iVar7 = bitset_iter_next(dst), iVar7 != -1)) {
    uVar10 = old_reg->id;
    do {
      uVar8 = bitset_test(g_local_conflicts[iVar7],uVar10);
      if (uVar8 != 0) {
        bitset_set(g_local_conflicts[iVar7],new_reg->id);
      }
      iVar7 = bitset_iter_next((c2_bitset *)0x0);
    } while (iVar7 != -1);
  }
  bitset_free(dst);
  return;
}

