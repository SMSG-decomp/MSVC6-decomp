void __fastcall coalesce_copy_live_ranges(c2_function *fn,c2_bitset **class_candidates)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_block *pcVar3;
  int iVar4;
  c2_bitset *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_operand *pcVar8;
  c2_list_cell *pcVar9;
  uint32_t uVar10;
  c2_block *pcVar11;
  c2_symbol *pcVar12;
  uint32_t uVar13;
  c2_live_range **bucket;
  c2_symbol *merged_sym;
  c2_live_range *merged_range;
  c2_symbol *pcVar14;
  c2_tuple *last_use;
  c2_live_range *kept_range;
  c2_list_cell *copies;
  c2_live_range *dst_range;
  c2_list_cell *cell;
  c2_live_range *range;
  
  pcVar1 = fn->cfg->first->head;
  copies = (c2_list_cell *)0x0;
  for (; pcVar9 = copies, pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if ((pcVar1->flags & 1) != 0) {
      pcVar8 = pcVar1->dst;
      cell = copies;
      for (pcVar6 = pcVar8; copies = cell, pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
        if (((((pcVar6->kind == '\x01') && (pcVar14 = (pcVar6->u18).reg, pcVar14->cls == '\x02')) &&
             (pcVar14->offset = pcVar14->offset + 1, pcVar1->op == 1)) &&
            ((pcVar6->rank != 0 && (pcVar2 = pcVar1->src, pcVar2->kind == '\x01')))) &&
           (((((pcVar2->u18).reg)->cls == '\x02' &&
             ((pcVar2->sym->cls != '\r' && (pcVar2->next == (c2_operand *)0x0)))) &&
            (pcVar8->next == (c2_operand *)0x0)))) {
          copies = alloc_split_cell();
          (copies->u04).tuple = pcVar1;
          copies->next = cell;
        }
        cell = copies;
      }
    }
  }
  do {
    if (pcVar9 == (c2_list_cell *)0x0) {
      bucket = g_live_range_hash;
      do {
        for (range = *bucket; range != (c2_live_range *)0x0; range = range->hash_next) {
          range->refcount = 0;
        }
        bucket = bucket + 1;
      } while ((int)bucket < 0x1079e88c);
      if (copies != (c2_list_cell *)0x0) {
        free_split_cell_list(copies);
      }
      return;
    }
    pcVar1 = (pcVar9->u04).tuple;
    pcVar6 = pcVar1->dst;
    dst_range = (pcVar6->u18).range;
    if (dst_range->refcount == 1) {
      merged_sym = pcVar6->sym;
      kept_range = (pcVar1->src->u18).range;
      pcVar14 = pcVar1->src->sym;
      merged_range = dst_range;
LAB_10720a92:
      last_use = merged_range->last_block->end;
      uVar10 = bitset_test(merged_range->last_block->live_out,merged_range->id);
      if (uVar10 == 0) {
        if (last_use->kind == '\x19') {
          last_use = last_use->prev;
        }
        do {
          if ((last_use->flags & 1) != 0) {
            for (pcVar6 = last_use->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if ((pcVar6->kind == '\x01') && ((pcVar6->u18).reg == (c2_symbol *)merged_range))
              goto LAB_10720ae7;
            }
          }
          last_use = last_use->prev;
        } while( true );
      }
LAB_10720ae7:
      uVar10 = has_intervening_base_definition(pcVar14,pcVar1,last_use,merged_range);
      if ((uVar10 == 0) && ((merged_sym->type & 0xfff) <= (pcVar14->type & 0xfff))) {
        if ((last_use->flags & 1) != 0) {
          last_use = last_use->next;
        }
        if ((c2_symbol *)(merged_sym->u34).lcse_values != (c2_symbol *)0x0) {
          merged_sym = (c2_symbol *)(merged_sym->u34).lcse_values;
        }
        pcVar1 = (pcVar9->u04).tuple;
        for (pcVar7 = pcVar1->next; pcVar7 != last_use; pcVar7 = pcVar7->next) {
          if ((pcVar7->flags & 1) != 0) {
            for (pcVar6 = pcVar7->src; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if ((pcVar6->kind == '\x01') && ((pcVar6->u18).reg == (c2_symbol *)merged_range)) {
                (pcVar6->u18).range = kept_range;
                if (pcVar6->sym == merged_sym) {
                  pcVar6->sym = pcVar14;
                }
                else {
                  pcVar12 = symbol_get_part(pcVar14,pcVar6->type,pcVar6->type & 0xfff,
                                            pcVar6->sym->offset - merged_sym->offset);
                  iVar4 = (pcVar14->u34).refs;
                  pcVar6->sym = pcVar12;
                  if (iVar4 == 0) {
                    (pcVar12->u34).parent = pcVar14;
                  }
                  else {
                    (pcVar12->u34).refs = iVar4;
                  }
                }
              }
            }
          }
        }
        pcVar11 = tuple_get_block_nonnull(pcVar1);
        pcVar3 = merged_range->last_block;
        uVar10 = merged_range->id;
        while( true ) {
          pcVar5 = pcVar11->live_in;
          uVar13 = bitset_test(pcVar5,uVar10);
          if (uVar13 != 0) {
            bitset_clear(pcVar5,uVar10);
            bitset_set(pcVar5,kept_range->id);
          }
          pcVar5 = pcVar11->live_out;
          uVar13 = bitset_test(pcVar5,uVar10);
          if (uVar13 != 0) {
            bitset_clear(pcVar5,uVar10);
            bitset_set(pcVar5,kept_range->id);
          }
          if (pcVar11 == pcVar3) break;
          pcVar11 = pcVar11->next;
        }
        for (pcVar3 = kept_range->last_block; pcVar3 != (c2_block *)0x0; pcVar3 = pcVar3->next) {
          if (pcVar3 == pcVar11) {
            if (pcVar3 != (c2_block *)0x0) {
              kept_range->last_block = pcVar11;
            }
            break;
          }
        }
        bitset_clear(class_candidates[g_type_class[merged_range->sym->type >> 0xc]],uVar10);
        if ((merged_range->flags6 & 4) != 0) {
          kept_range->flags6 = kept_range->flags6 | 4;
        }
        free_live_range(merged_range,0);
        pcVar1 = (pcVar9->u04).tuple;
        if ((c2_symbol *)kept_range == (pcVar1->dst->u18).reg) {
          pcVar6 = pcVar1->prev->dst;
          pcVar6->sym = pcVar14;
          (pcVar6->u18).range = kept_range;
        }
        tuple_unlink_free(pcVar1);
      }
    }
    else {
      merged_range = (pcVar1->src->u18).range;
      if ((((merged_range->refcount == 1) && (pcVar7 = pcVar1->prev, (pcVar7->flags & 1) != 0)) &&
          (pcVar7->op != 0x163)) &&
         (((pcVar8 = pcVar7->dst, pcVar8 != (c2_operand *)0x0 && (pcVar8->kind == '\x01')) &&
          (((pcVar8->u18).range == merged_range && (((pcVar1->type ^ pcVar8->type) & 0xfff) == 0))))
         )) {
        pcVar14 = pcVar6->sym;
        merged_sym = pcVar1->src->sym;
        kept_range = dst_range;
        goto LAB_10720a92;
      }
    }
    pcVar9 = pcVar9->next;
  } while( true );
}

