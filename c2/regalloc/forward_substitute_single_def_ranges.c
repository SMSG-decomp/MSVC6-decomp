void __fastcall forward_substitute_single_def_ranges(c2_function *fn,c2_bitset *bs)

{
  uint8_t *puVar1;
  byte bVar2;
  c2_tuple *pcVar3;
  c2_live_range *lr;
  c2_operand *pcVar4;
  uint32_t uVar5;
  c2_operand *opnd;
  c2_block *pcVar6;
  int iVar7;
  uint8_t uVar8;
  c2_live_range **reset_bucket;
  c2_tuple *t;
  c2_live_range **bucket;
  c2_live_range *range;
  c2_live_range *chain_range;
  
  t = fn->cfg->first->head;
  do {
    if (t == (c2_tuple *)0x0) {
      bucket = g_live_range_hash;
      do {
        chain_range = *bucket;
        while (lr = chain_range, lr != (c2_live_range *)0x0) {
          chain_range = lr->hash_next;
          if ((lr->flags5 & 4) == 0) {
            pcVar6 = lr->last_block;
            uVar5 = bitset_test(pcVar6->live_out,lr->id);
            if (uVar5 != 0) {
              lr->u14 = (c2_live_range_u14)pcVar6->end;
            }
            t = (lr->u38).def;
            opnd = lea_definition_base_operand(t);
            uVar5 = has_intervening_base_definition(opnd->sym,t,(lr->u14).last_use,lr);
            if (((uVar5 == 0) &&
                ((opnd->rank == 0 ||
                 ((uVar5 = has_intervening_base_definition
                                     (*(c2_symbol **)(opnd->rank + 0x14),(lr->u38).def,
                                      (lr->u14).last_use,lr), uVar5 == 0 &&
                  (((lr->u38).def)->flags12 != '\x01')))))) &&
               ((g_opt_favor_speed != 0 ||
                (iVar7 = remat_cheaper_than_spill(lr,(lr->u38).def,(lr->u14).last_use), iVar7 != 0))
               )) {
              t = (lr->u38).def;
              pcVar6 = tuple_get_block_nonnull(t);
              lr->first_block = pcVar6;
              substitute_definition_into_uses(t,lr,opnd);
              bitset_clear(bs,lr->id);
              free_live_range(lr,0);
            }
          }
        }
        bucket = bucket + 1;
      } while ((int)bucket < 0x1079e88c);
      reset_bucket = g_live_range_hash;
      do {
        for (chain_range = *reset_bucket; chain_range != (c2_live_range *)0x0;
            chain_range = chain_range->hash_next) {
          (chain_range->u14).queue_next = (c2_live_range *)0x0;
          (chain_range->u38).def = (c2_tuple *)0x0;
          chain_range->flags5 = chain_range->flags5 & 0xfb;
        }
        reset_bucket = reset_bucket + 1;
      } while ((int)reset_bucket < 0x1079e88c);
      return;
    }
    if ((t->flags & 1) != 0) {
      for (opnd = t->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
        if (((opnd->kind == '\x01') && (range = (opnd->u18).range, range->kind == '\x02')) &&
           (bVar2 = range->flags5, (bVar2 & 4) == 0)) {
          if ((opnd->flags & 0x20) == 0) {
            if (((((t->op != 1) || (pcVar4 = t->dst, pcVar4->kind != '\x01')) ||
                 ((pcVar4->next != (c2_operand *)0x0 ||
                  ((t->src->next != (c2_operand *)0x0 || (g_opt_favor_speed == 0)))))) ||
                ((range->u38).def == (c2_tuple *)0x0)) ||
               (pcVar4 = find_src_reg_operand((pcVar4->u18).reg,(range->u38).def),
               pcVar4 == (c2_operand *)0x0)) goto LAB_10720e00;
            (range->u14).last_use = t;
          }
          else if ((range->u38).def == (c2_tuple *)0x0) {
LAB_10720e00:
            range->flags5 = bVar2 | 4;
          }
          else {
            uVar5 = is_substitutable_address_use(t,opnd);
            if (uVar5 == 0) {
              range->flags5 = range->flags5 | 4;
            }
            else {
              (range->u14).last_use = t;
            }
          }
        }
      }
      for (opnd = t->dst; opnd != (c2_operand *)0x0; opnd = opnd->next) {
        if ((opnd->kind == '\x01') && (range = (opnd->u18).range, range->kind == '\x02')) {
          pcVar3 = (range->u38).def;
          if (pcVar3 == (c2_tuple *)0x0) {
            if (((((t->op == 1) && ((1 << (t->src->kind & 0x1f) & 6U) != 0)) &&
                 (pcVar3 = t->src->sym->def, pcVar3 != (c2_tuple *)0x0)) &&
                ((pcVar3 == t->prev && (iVar7 = is_foldable_address_definition(t->prev), iVar7 != 0)
                 ))) && ((pcVar3 = t->prev, ((pcVar3->type ^ t->type) & 0xfff) == 0 &&
                         (t->dst->next == (c2_operand *)0x0)))) {
              tuple_replace_dst(pcVar3,pcVar3->dst,t->dst);
              tuple_unlink_free(t);
              opnd = pcVar3->dst;
              t = pcVar3;
            }
            *(c2_tuple **)((opnd->u18).lo + 0x38) = t;
            iVar7 = is_foldable_address_definition(t);
            if (iVar7 == 0) {
              puVar1 = &((opnd->u18).reg)->flags5;
              *puVar1 = *puVar1 | 4;
            }
            else {
              uVar8 = '\0';
              for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
                if (pcVar4->kind == '\x01') {
                  uVar8 = uVar8 + '\x01';
                }
              }
              t->flags12 = uVar8;
            }
          }
          else if (((range->flags5 & 4) == 0) &&
                  ((pcVar3->op != t->op ||
                   (iVar7 = compare_trees((c2_node *)pcVar3,(c2_node *)t), iVar7 != 0)))) {
            puVar1 = &((opnd->u18).reg)->flags5;
            *puVar1 = *puVar1 | 4;
          }
        }
      }
    }
    t = t->next;
  } while( true );
}

