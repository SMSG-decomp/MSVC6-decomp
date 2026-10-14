void __fastcall place_split_points_in_block(c2_block *b,c2_live_range *lr,c2_bitset *regs)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_live_range *pcVar5;
  c2_bitset *src;
  c2_bitset *dst;
  c2_bitset *pcVar6;
  uint32_t uVar7;
  
  src = bitset_clone(b->set24);
  dst = bitset_clone(regs);
  bitset_andnot(dst,src);
  pcVar1 = b->head;
  pcVar2 = b->end;
  do {
    if (pcVar1 == pcVar2) {
      bitset_free(src);
      bitset_free(dst);
      return;
    }
    if ((pcVar1->flags & 1) != 0) {
      if (pcVar1->op != 0x164) {
        for (pcVar4 = pcVar1->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if ((pcVar4->kind == '\x01') && ((pcVar4->u18).reg == (c2_symbol *)lr)) {
            if (dst->chunks == (c2_bitset_chunk *)0x0) {
              bitset_copy(dst,regs);
              bitset_andnot(dst,src);
              insert_split_marker_after(pcVar1->prev,lr->id);
              b->flags = b->flags | 0x40000;
            }
            break;
          }
        }
      }
      for (pcVar4 = pcVar1->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if (pcVar4->kind == '\x01') {
          pcVar5 = (pcVar4->u18).range;
          pcVar6 = src;
          if (pcVar5->kind == '\x02') {
            if (((pcVar5->colour != (c2_register_descriptor *)0x0) &&
                ((pcVar4->flags11 & 0x10) != 0)) && ((pcVar4->flags & 0x80) == 0)) {
              uVar7 = pcVar5->colour->id;
              goto LAB_1074d3a1;
            }
          }
          else if (pcVar5->kind == '\x01') {
            if (pcVar4->sym->cls == '\x03') {
              if (((pcVar4->flags11 & 0x10) == 0) || ((pcVar4->flags & 0x80) != 0))
              goto LAB_1074d3a6;
              uVar7 = pcVar5->self->id;
            }
            else {
              uVar7 = pcVar5->self->id;
              pcVar6 = dst;
            }
LAB_1074d3a1:
            bitset_clear(pcVar6,uVar7);
          }
        }
LAB_1074d3a6:
      }
      if (((pcVar1->flags12 & 2) != 0) && ((lr->flags6 & 2) == 0)) {
        bitset_and(dst,g_nonbyte_register_set);
      }
      pcVar3 = pcVar1->dst;
      for (pcVar4 = pcVar3; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
        if (pcVar4->kind == '\x01') {
          pcVar5 = (pcVar4->u18).range;
          if (pcVar5->kind == '\x02') {
            if (pcVar5->colour != (c2_register_descriptor *)0x0) {
              uVar7 = pcVar5->colour->id;
              bitset_clear(dst,uVar7);
LAB_1074d513:
              bitset_set(src,uVar7);
            }
          }
          else if (pcVar5->kind == '\x01') {
            uVar7 = pcVar5->self->id;
            bitset_clear(dst,uVar7);
            if (pcVar4->sym->cls == '\x03') goto LAB_1074d513;
          }
        }
        else if (pcVar4->kind == '\n') {
          bitset_andnot(dst,(c2_bitset *)pcVar4->sym);
        }
      }
      if (pcVar1->op != 0x163) {
        for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == (c2_symbol *)lr)) {
            if ((pcVar3->flags & 0xf) == 0) {
              bitset_copy(dst,regs);
              bitset_andnot(dst,src);
            }
            break;
          }
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

