void __fastcall post_schedule_merge_moves(c2_function *fn)

{
  uint32_t uVar1;
  bool bVar2;
  c2_const_operand *new_op;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_bitset *dst;
  uint32_t uVar5;
  c2_tuple *cur;
  c2_tuple *first;
  c2_tuple *prev2;
  c2_tuple *prev_t;
  c2_symbol *src_reg;
  
  first = fn->cfg->first->head;
  bVar2 = false;
  cur = fn->cfg->last->end->prev;
  if (cur != first) {
    do {
      prev_t = cur->prev;
      prev2 = prev_t->prev;
      if (((cur->flags & 1) != 0) && ((cur->flags & 4) != 0)) {
        if ((cur->op == 1) && (prev2->op == 1)) {
          if ((prev_t->flags & 4) == 0) goto LAB_1073f6b8;
          if (((((prev2->flags & 4) != 0) && (prev2->dst->kind == '\x01')) &&
              (cur->src->kind == '\x01')) &&
             ((pcVar3 = prev_t->dst, pcVar3->kind == '\x01' && (prev_t->src->kind == '\x01')))) {
            src_reg = (cur->src->u18).reg;
            uVar5 = src_reg->id;
            if (((prev2->dst->u18).reg)->id == uVar5) {
              uVar1 = ((pcVar3->u18).reg)->id;
              if ((uVar5 == uVar1) && (((prev_t->src->u18).reg)->id == uVar1)) {
                if (pcVar3->next != (c2_operand *)0x0) {
                  operand_list_find_regid(((pcVar3->u18).reg)->storage->id,pcVar3->next);
                }
                if (3 < src_reg->storage->id) {
                  bVar2 = true;
                }
                tuple_replace_src(prev_t,prev_t->src,cur->dst);
                tuple_replace_dst(prev_t,prev_t->dst,cur->dst);
                prev_t->flags = prev_t->flags & 0xfb;
                tuple_unlink_free(cur);
                tuple_unlink_free(prev2);
                prev_t = prev_t->prev;
                goto LAB_1073f6b8;
              }
            }
          }
        }
        if (((((((prev_t->flags & 4) != 0) && (prev_t->op == 1)) && (prev_t->dst->kind == '\x01'))
             && ((pcVar3 = operand_list_find_regid(((prev_t->dst->u18).reg)->storage->id,cur->dst),
                 pcVar3 == (c2_operand *)0x0 &&
                 (pcVar3 = operand_list_find_regid(((prev_t->dst->u18).reg)->storage->id,cur->src),
                 pcVar3 != (c2_operand *)0x0)))) &&
            (src_reg = (prev_t->dst->u18).reg, ((pcVar3->u18).reg)->id == src_reg->id)) &&
           ((cur->op != 1 || (cur->dst->kind == '\x01')))) {
          if (pcVar3->next == (c2_operand *)0x0) {
LAB_1073f76d:
            if (3 < src_reg->storage->id) {
              bVar2 = true;
            }
            tuple_replace_src(cur,pcVar3,prev_t->src);
          }
          else {
            uVar5 = src_reg->storage->id;
            pcVar4 = operand_list_find_regid(uVar5,pcVar3->next);
            if (pcVar4 == (c2_operand *)0x0) goto LAB_1073f76d;
            if ((((cur->op != 0x33) ||
                 (pcVar3 = cur->src, ((pcVar3->u18).reg)->id != ((pcVar3->next->u18).reg)->id)) ||
                (pcVar4 = prev_t->src, pcVar4->kind != '\x06')) ||
               ((pcVar4->disp != 0 || (pcVar4->base_sym != (c2_symbol *)0x0)))) goto LAB_1073f6b8;
            if (3 < uVar5) {
              bVar2 = true;
            }
            tuple_replace_src(cur,pcVar3,pcVar4);
            pcVar3 = cur->src->next;
            new_op = operand_new_intconst(pcVar3->type,0,0);
            tuple_replace_src(cur,pcVar3,new_op);
            cur->op = 0x2f;
          }
          cur->flags = cur->flags & 0xfb;
          tuple_unlink_free(prev_t);
          prev_t = cur->prev;
        }
      }
LAB_1073f6b8:
      cur = prev_t;
    } while (cur != first);
    if (((bVar2) && ((fn->fsym->attrs & 0x1000) == 0)) && ((fn->flags & 0x10000) == 0)) {
      g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 & 0xef;
      g_reg_symbols[4].flags5 = g_reg_symbols[4].flags5 & 0xef;
      g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 & 0xef;
      g_reg_symbols[7].flags5 = g_reg_symbols[7].flags5 & 0xef;
      dst = bitset_new(6);
      for (cur = first; cur != (c2_tuple *)0x0; cur = cur->next) {
        if (((cur->flags & 1) != 0) && (cur->op != 0xb9)) {
          for (pcVar3 = cur->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if (pcVar3->kind == '\x01') {
              g_reg_symbols[((pcVar3->u18).reg)->storage->id].flags5 =
                   g_reg_symbols[((pcVar3->u18).reg)->storage->id].flags5 | 0x10;
            }
            else if (pcVar3->kind == '\n') {
              bitset_or(dst,(c2_bitset *)pcVar3->sym);
            }
          }
        }
      }
      uVar5 = bitset_test(dst,4);
      if (uVar5 != 0) {
        g_reg_symbols[4].flags5 = g_reg_symbols[4].flags5 | 0x10;
      }
      uVar5 = bitset_test(dst,6);
      if (uVar5 != 0) {
        g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 | 0x10;
      }
      uVar5 = bitset_test(dst,7);
      if (uVar5 != 0) {
        g_reg_symbols[7].flags5 = g_reg_symbols[7].flags5 | 0x10;
      }
      uVar5 = bitset_test(dst,8);
      if (uVar5 != 0) {
        g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 | 0x10;
      }
      bitset_free(dst);
      if ((((g_reg_symbols[4].flags5 & 0x10) != 0x10) ||
          ((((g_reg_symbols[6].flags5 & 0x10) != 0x10 && (g_ebp_allocatable != 0)) ||
           ((g_reg_symbols[7].flags5 & 0x10) != 0x10)))) ||
         ((g_reg_symbols[8].flags5 & 0x10) != 0x10)) {
        while (cur = first, cur != (c2_tuple *)0x0) {
          first = cur->next;
          if (cur->op == 0xba) {
            if ((g_reg_symbols[((cur->src->u18).reg)->id].flags5 & 0x10) == 0) {
              tuple_unlink_free(cur);
              fn->callee_save_pushes = fn->callee_save_pushes + -1;
            }
          }
          else if ((cur->op == 0xb9) &&
                  ((g_reg_symbols[((cur->dst->u18).reg)->id].flags5 & 0x10) == 0)) {
            tuple_unlink_free(cur);
          }
        }
        if ((fn->flags & 0x80) != 0) {
          *(uint32_t *)(*(int *)(fn->x38 + 0x18) + 0x24) = fn->callee_save_pushes * -4 - fn->x3c;
        }
      }
    }
  }
  return;
}

