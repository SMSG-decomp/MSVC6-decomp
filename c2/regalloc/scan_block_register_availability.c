int __fastcall
scan_block_register_availability
          (c2_live_range *range,c2_block *b,c2_bitset *free,int first,c2_bitset *regs)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_live_range *pcVar5;
  c2_bitset *src;
  c2_bitset *bs;
  uint32_t uVar6;
  c2_bitset *pcVar7;
  int iVar8;
  
  src = bitset_clone(b->set24);
  bs = bitset_clone(free);
  pcVar1 = b->head;
  pcVar2 = b->end;
  do {
    if (pcVar1 == pcVar2) {
      if (first == 0) {
        b->avail_out = b->avail_in;
      }
      if (bs->chunks == (c2_bitset_chunk *)0x0) {
        pcVar1 = pcVar1->prev;
        if (pcVar1->kind == '\x1b') {
          bitset_set((pcVar1->u14).regs,range->id);
          iVar8 = 0;
          b->flags = b->flags | 0x40000;
        }
        else {
          insert_split_marker_after(pcVar1,range->id);
          iVar8 = 0;
          b->flags = b->flags | 0x40000;
        }
      }
      else {
        bitset_copy(free,bs);
        iVar8 = 1;
      }
      bitset_free(src);
      bitset_free(bs);
      return iVar8;
    }
    if ((pcVar1->flags & 1) == 0) {
      if ((pcVar1->kind == '\x1b') &&
         (uVar6 = bitset_test((pcVar1->u14).regs,range->id), uVar6 != 0)) {
        if (first == 0) {
LAB_10725993:
          bitset_free(src);
          bitset_free(bs);
          return 0;
        }
        bitset_clear_all(bs);
      }
    }
    else {
      if (pcVar1->op != 0x164) {
        for (pcVar4 = pcVar1->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if ((pcVar4->kind == '\x01') && ((pcVar4->u18).reg == (c2_symbol *)range)) {
            if (bs->chunks == (c2_bitset_chunk *)0x0) {
              bitset_copy(bs,regs);
              bitset_andnot(bs,src);
              insert_split_marker_after(pcVar1->prev,range->id);
              b->flags = b->flags | 0x40000;
              if (first == 0) goto LAB_10725993;
            }
            else {
              bitset_copy(free,bs);
            }
          }
        }
      }
      for (pcVar4 = pcVar1->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if (pcVar4->kind == '\x01') {
          pcVar5 = (pcVar4->u18).range;
          pcVar7 = src;
          if (pcVar5->kind == '\x02') {
            if (((pcVar5->colour != (c2_register_descriptor *)0x0) &&
                ((pcVar4->flags11 & 0x10) != 0)) && ((pcVar4->flags & 0x80) == 0)) {
              uVar6 = pcVar5->colour->id;
              goto LAB_107259d7;
            }
          }
          else if (pcVar5->kind == '\x01') {
            if (pcVar4->sym->cls == '\x03') {
              if (((pcVar4->flags11 & 0x10) == 0) || ((pcVar4->flags & 0x80) != 0))
              goto LAB_107259dc;
              uVar6 = pcVar5->self->id;
            }
            else {
              uVar6 = pcVar5->self->id;
              pcVar7 = bs;
            }
LAB_107259d7:
            bitset_clear(pcVar7,uVar6);
          }
        }
LAB_107259dc:
      }
      if ((((pcVar1->flags12 & 2) != 0) && ((range->flags6 & 2) == 0)) &&
         (bitset_and(bs,g_nonbyte_register_set), bs->chunks == (c2_bitset_chunk *)0x0)) {
        bitset_copy(bs,regs);
        bitset_andnot(bs,src);
        bitset_and(bs,g_nonbyte_register_set);
        insert_split_marker_after(pcVar1->prev,range->id);
        if (first == 0) {
          bitset_free(src);
          bitset_free(bs);
          return 0;
        }
      }
      pcVar3 = pcVar1->dst;
      for (pcVar4 = pcVar3; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if (pcVar4->kind == '\x01') {
          pcVar5 = (pcVar4->u18).range;
          if (pcVar5->kind == '\x02') {
            if (pcVar5->colour != (c2_register_descriptor *)0x0) {
              uVar6 = pcVar5->colour->id;
              bitset_clear(bs,uVar6);
LAB_10725a30:
              bitset_set(src,uVar6);
            }
          }
          else if (pcVar5->kind == '\x01') {
            uVar6 = pcVar5->self->id;
            bitset_clear(bs,uVar6);
            if (pcVar4->sym->cls == '\x03') goto LAB_10725a30;
          }
        }
        else if (pcVar4->kind == '\n') {
          bitset_andnot(bs,(c2_bitset *)pcVar4->sym);
        }
      }
      if (pcVar1->op != 0x163) {
        for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == (c2_symbol *)range)) {
            if ((pcVar3->flags & 0xf) != 0) break;
            bitset_copy(bs,regs);
            bitset_andnot(bs,src);
            if (first == 0) {
              bitset_free(src);
              bitset_free(bs);
              return 0;
            }
          }
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

