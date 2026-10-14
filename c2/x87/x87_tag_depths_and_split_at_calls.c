c2_bitset * __fastcall x87_tag_depths_and_split_at_calls(c2_function *fn,c2_bitset *candidates)

{
  ushort uVar1;
  uint16_t type;
  c2_block *pcVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  uint8_t uVar5;
  c2_bitset *live_ranges;
  c2_bitset *to_split;
  int iVar6;
  uint32_t uVar7;
  c2_x87_block_stack *pcVar8;
  c2_bitset *bs;
  c2_symbol *pcVar9;
  c2_operand *src;
  c2_operand *dst;
  c2_tuple *pcVar10;
  int depth;
  c2_tuple *t;
  int operand_pass;
  c2_insert_fn *insert_fn;
  bool split_pending;
  
  depth = 0;
  split_pending = false;
  live_ranges = bitset_new(6);
  to_split = bitset_new(6);
  pcVar2 = fn->cfg->first;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      bitset_free(live_ranges);
      if (to_split->chunks == (c2_bitset_chunk *)0x0) {
        bitset_free(to_split);
        to_split = (c2_bitset *)0x0;
      }
      return to_split;
    }
    pcVar8 = arena_alloc(4,0x20);
    (pcVar2->u58).x87_stack = pcVar8;
    bitset_copy(live_ranges,candidates);
    bitset_and(live_ranges,pcVar2->live_out);
    t = pcVar2->end->prev;
LAB_1075d6ab:
    uVar1 = t->line;
    if (uVar1 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar1;
      g_cur_line = uVar1;
    }
    if ((split_pending) && (depth == 0)) {
      split_pending = false;
      if (live_ranges->chunks != (c2_bitset_chunk *)0x0) {
        insert_split_marker_after_spill(t,live_ranges);
        bitset_or(to_split,live_ranges);
        pcVar2->flags = pcVar2->flags | 0x40000;
      }
      pcVar10 = t->next;
      uVar5 = pcVar10->kind;
      while (uVar5 != '\x19') {
        if ((pcVar10->flags & 1) != 0) {
          operand_pass = 0;
          do {
            if (operand_pass == 0) {
              if (pcVar10->flags12 != '\0') {
                pcVar3 = pcVar10->dst;
                goto joined_r0x10777ee0;
              }
            }
            else {
              pcVar3 = pcVar10->src;
joined_r0x10777ee0:
              for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
                if ((((pcVar3->type & 0xf000) == 0x4000) && (pcVar3->kind == '\x01')) &&
                   (pcVar9 = (pcVar3->u18).reg, pcVar9->cls == '\x02')) {
                  bs = bitset_new(6);
                  bitset_set(bs,pcVar9->id);
                  insert_split_marker_after_spill(pcVar10,bs);
                  insert_split_marker_after_spill(pcVar10->prev,bs);
                  bitset_free(bs);
                  bitset_set(to_split,((pcVar3->u18).reg)->id);
                  pcVar2->flags = pcVar2->flags | 0x40000;
                }
              }
            }
            operand_pass = operand_pass + 1;
          } while ((uint)operand_pass < 2);
          if (pcVar10->flags12 == '\0') break;
        }
        pcVar10 = pcVar10->next;
        uVar5 = pcVar10->kind;
      }
    }
    if ((t->flags & 1) != 0) {
      if (((depth != 0) && (t->kind == '\x0e')) &&
         ((t->src->kind != '\x04' || (((uint)t->src->sym->def & 0x10000) == 0)))) {
        split_pending = true;
      }
      if (((((t->kind == '\x0e') &&
            ((t->src->kind != '\x04' || (((uint)t->src->sym->def & 0x10000) == 0)))) ||
           (t->kind == '\x15')) || (t->op == 0x18b)) &&
         (live_ranges->chunks != (c2_bitset_chunk *)0x0)) {
        insert_split_marker_after_spill(t,live_ranges);
        bitset_or(to_split,live_ranges);
        pcVar2->flags = pcVar2->flags | 0x40000;
      }
      uVar5 = (uint8_t)depth;
      t->flags12 = uVar5;
      t->flags13 = uVar5;
      if (depth == 8) {
        split_pending = true;
      }
      pcVar3 = t->dst;
      if (((pcVar3 != (c2_operand *)0x0) && ((pcVar3->type & 0xf000) == 0x4000)) &&
         (pcVar3->kind == '\x01')) {
        if (((pcVar3->u18).reg)->cls == '\x02') {
          uVar4 = ((pcVar3->u18).reg)->id;
          bitset_clear(live_ranges,uVar4);
          bitset_set(pcVar2->live,uVar4);
        }
        else if (((pcVar3->sym->cls == '\x01') && (uVar4 = t->op, uVar4 != 99)) &&
                ((uVar4 != 0x5f && ((uVar4 != 0x178 || ((t->type & 0xf000) == 0x4000)))))) {
          pcVar9 = symbol_new_temp(pcVar3->type);
          type = pcVar3->type;
          insert_fn = tuple_insert_after;
          pcVar9->def = t;
          pcVar10 = t;
          src = operand_new_reg(0x149,type,pcVar9,g_reg_symbols + 0x1f);
          dst = operand_new_reg(0x149,type,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
          pcVar10 = tuple_new(0x62,type,dst,src,insert_fn,pcVar10);
          pcVar10->flags12 = uVar5;
          pcVar10->flags13 = uVar5;
          tuple_replace_dst(t,pcVar3,pcVar10->src);
          depth = depth + 1;
          t->flags12 = (uint8_t)depth;
          t->flags13 = (uint8_t)depth;
        }
      }
      if (t->op == 0x5d) {
        x87_swap_compare_operands(t);
      }
      for (pcVar3 = t->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (pcVar3->kind == '\x01') {
          pcVar3->rank = 0;
          if (((pcVar3->type & 0xf000) == 0x4000) && (((pcVar3->u18).reg)->cls == '\x02')) {
            uVar4 = ((pcVar3->u18).reg)->id;
            uVar7 = bitset_test(live_ranges,uVar4);
            if (uVar7 == 0) {
              bitset_set(live_ranges,uVar4);
              pcVar3->flags11 = pcVar3->flags11 | 0x10;
            }
            else {
              pcVar3->flags11 = pcVar3->flags11 & 0xef;
            }
          }
        }
        else if (pcVar3->kind == '\x02') {
          pcVar3->rank = 0;
        }
      }
      iVar6 = x87_stack_effect(t);
      depth = depth - iVar6;
      t = t->prev;
      goto LAB_1075d6ab;
    }
    if (t->kind != '\x19') {
      t = t->prev;
      goto LAB_1075d6ab;
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

