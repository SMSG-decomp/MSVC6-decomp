void __fastcall substitute_definition_into_uses(c2_tuple *def,c2_live_range *lr,c2_operand *base)

{
  c2_live_range *pcVar1;
  c2_block *pcVar2;
  uint32_t n;
  c2_bitset *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *sym;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_tuple *t;
  c2_tuple *base_use;
  c2_tuple *index_use;
  c2_block *pcVar7;
  c2_tuple *cur;
  c2_live_range *index_range;
  c2_operand *op_next;
  c2_operand *op;
  
  if (base == (c2_operand *)0x0) {
    base = (c2_operand *)0x0;
    index_range = (c2_live_range *)0x0;
  }
  else {
    pcVar1 = (base->u18).range;
    pcVar7 = lr->last_block;
    for (pcVar2 = pcVar1->last_block; pcVar2 != (c2_block *)0x0; pcVar2 = pcVar2->next) {
      if (pcVar2 == pcVar7) {
        if (pcVar2 != (c2_block *)0x0) {
          pcVar1->last_block = pcVar7;
        }
        break;
      }
    }
    if (base->rank == 0) {
      index_range = (c2_live_range *)0x0;
      base = (c2_operand *)pcVar1;
    }
    else {
      index_range = *(c2_live_range **)(base->rank + 0x18);
      for (pcVar2 = index_range->last_block; base = (c2_operand *)pcVar1, pcVar2 != (c2_block *)0x0;
          pcVar2 = pcVar2->next) {
        if (pcVar2 == pcVar7) {
          if (pcVar2 != (c2_block *)0x0) {
            index_range->last_block = pcVar7;
          }
          break;
        }
      }
    }
  }
  pcVar7 = lr->first_block;
  do {
    n = lr->id;
    if (base == (c2_operand *)0x0) {
      bitset_clear(pcVar7->live,n);
    }
    else {
      pcVar3 = pcVar7->live_in;
      uVar5 = bitset_test(pcVar3,n);
      if ((uVar5 != 0) && (bitset_set(pcVar3,base->tag), index_range != (c2_live_range *)0x0)) {
        bitset_set(pcVar3,index_range->id);
      }
      pcVar3 = pcVar7->live_out;
      uVar5 = bitset_test(pcVar3,n);
      if ((uVar5 != 0) && (bitset_set(pcVar3,base->tag), index_range != (c2_live_range *)0x0)) {
        bitset_set(pcVar3,index_range->id);
      }
    }
    bitset_clear(pcVar7->live_in,n);
    bitset_clear(pcVar7->live_out,n);
    cur = pcVar7->head;
    if (pcVar7->head != pcVar7->end) {
      do {
        pcVar4 = (c2_symbol *)cur->next;
        if ((cur->flags & 1) == 0) {
          if (cur->kind == '\x1b') {
            bitset_clear((cur->u14).regs,lr->id);
          }
        }
        else if ((cur == def) ||
                (pcVar6 = find_dst_reg_operand((c2_symbol *)lr,cur), pcVar6 == (c2_operand *)0x0)) {
          op_next = cur->src;
          while (op = op_next, op != (c2_operand *)0x0) {
            op_next = op->next;
            if ((op->kind == '\x01') && ((op->u18).range == lr)) {
              if ((op->flags & 0x20) == 0) {
                t = (c2_tuple *)node_clone((c2_node *)def);
                tuple_replace_dst(t,t->dst,cur->dst);
                if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) &&
                   (sym = t->dst->sym, sym->def != (c2_tuple *)0x0)) {
                  if (sym->storage->part_next == (c2_symbol *)0x0) {
                    sym->def = t;
                  }
                  else {
                    symbol_mark_overlapping_parts(sym,t);
                  }
                }
                tuple_insert_before(cur,t);
                goto LAB_10722f68;
              }
              fold_address_def_into_use(cur,op,def);
            }
          }
        }
        else {
          if (g_pressure_split_points != (void *)0x0) {
            list_clear_value(g_pressure_split_points,cur);
          }
          if (((base != (c2_operand *)0x0) && ((base->op & 0x400) == 0)) &&
             (base->sym == (c2_symbol *)cur)) {
            base->sym = pcVar4;
          }
          if (((index_range != (c2_live_range *)0x0) && ((index_range->flags5 & 4) == 0)) &&
             ((index_range->u14).queue_next == (c2_live_range *)cur)) {
            (index_range->u14).queue_next = (c2_live_range *)pcVar4;
          }
LAB_10722f68:
          tuple_unlink_free(cur);
        }
        cur = (c2_tuple *)pcVar4;
      } while (pcVar4 != (c2_symbol *)pcVar7->end);
    }
    if (pcVar7 == lr->last_block) break;
    pcVar7 = pcVar7->next;
  } while( true );
  if (((base != (c2_operand *)0x0) && ((base->op & 0x400) == 0)) &&
     (base_use = (c2_tuple *)base->sym, (c2_symbol *)base_use != (c2_symbol *)0x0)) {
    do {
      if (base_use == (lr->u14).last_use) {
        if (base_use != (c2_tuple *)0x0) {
          base->sym = (c2_symbol *)base_use;
        }
        break;
      }
      base_use = base_use->next;
    } while (base_use != (c2_tuple *)0x0);
  }
  if (((index_range != (c2_live_range *)0x0) && ((index_range->flags5 & 4) == 0)) &&
     (index_use = (index_range->u14).last_use, index_use != (c2_tuple *)0x0)) {
    while (index_use != (lr->u14).last_use) {
      index_use = index_use->next;
      if (index_use == (c2_tuple *)0x0) {
        tuple_unlink_free(def);
        return;
      }
    }
    if (index_use != (c2_tuple *)0x0) {
      (index_range->u14).last_use = index_use;
    }
  }
  tuple_unlink_free(def);
  return;
}

