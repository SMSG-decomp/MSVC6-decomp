void __fastcall
build_split_pieces(c2_function *fn,c2_ra_split_block *blocks,c2_bitset *class_candidates)

{
  uint8_t *puVar1;
  ushort uVar2;
  c2_ra_split_block *pcVar3;
  c2_block *b;
  c2_bitset *current_pieces;
  c2_bitset *bs;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  uint32_t uVar6;
  c2_live_range *range;
  c2_live_range *piece_range;
  c2_operand *pcVar7;
  byte bVar8;
  c2_tuple *t;
  uint32_t tie;
  c2_live_range *cut_range;
  c2_bitset *dst_pieces;
  c2_loop *loop;
  c2_bitset *src_pieces;
  
  current_pieces = bitset_new(6);
  bs = bitset_new(6);
  do {
    do {
      if (blocks == (c2_ra_split_block *)0x0) {
        bitset_free(bs);
        bitset_free(current_pieces);
        return;
      }
      pcVar3 = blocks->next;
      b = blocks->block;
      free_split_node(blocks);
      insert_entry_copies_on_pred_edges(fn,b,1);
      bitset_copy(current_pieces,class_candidates);
      bitset_and(current_pieces,b->live_in);
      t = b->head;
      blocks = pcVar3;
    } while (t == b->end);
    do {
      if ((t->flags & 1) == 0) {
        if (t->kind == '\x1b') {
          pcVar4 = t->src;
          if (pcVar4 != (c2_operand *)0x0) {
            loop = b->loop;
            pcVar7 = pcVar4;
            do {
              cut_range = (c2_live_range *)pcVar7->op;
              bitset_andnot(current_pieces,cut_range->allowed);
              if (loop != (c2_loop *)0x0) {
                split_mark_symbol_in_chain(loop,cut_range->sym);
              }
              pcVar7 = pcVar7->next;
            } while (pcVar7 != (c2_operand *)0x0);
          }
          free_rename_cell_list(pcVar4);
          t = t->prev;
          tuple_unlink_free(t->next);
        }
      }
      else {
        uVar2 = t->line;
        if (uVar2 != 0) {
          g_current_line_abs = fn->line_base + (uint)uVar2;
          g_cur_line = uVar2;
        }
        for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((pcVar4->kind == '\x01') && (range = (pcVar4->u18).range, range->kind == '\x02')) &&
             ((range->flags5 & 2) != 0)) {
            src_pieces = range->allowed;
            uVar6 = bitset_first_common(src_pieces,current_pieces);
            if (uVar6 == 0xffffffff) {
              bVar8 = pcVar4->flags11;
              if ((bVar8 & 0x40) == 0) {
                if ((((bVar8 & 0x10) != 0) && ((pcVar4->type & 0xf000) != 0x4000)) &&
                   ((pcVar4->flags & 0xf) == 0)) {
                  if (pcVar4->sym->cls == '\r') {
                    pcVar4 = tuple_replace_src_with_base_copy(t,pcVar4,pcVar4->sym);
                  }
                  else {
                    if ((bVar8 & 0x80) != 0) {
                      add_reference_saving(t,range,b);
                    }
                    pcVar4 = split_make_memory_use(t,pcVar4);
                  }
                  goto LAB_10724a06;
                }
                piece_range = new_live_range(pcVar4->sym);
                tie = range->tie;
                (piece_range->u14).queue_next = range;
                uVar6 = piece_range->id;
                piece_range->tie = tie;
                bitset_set(src_pieces,uVar6);
                bitset_set(b->live,uVar6);
                if ((bVar8 & 0x10) == 0) goto LAB_107249c6;
              }
              else {
                uVar6 = bitset_first_common(src_pieces,b->live_out);
                piece_range = live_range_from_id(uVar6);
                uVar6 = piece_range->id;
LAB_107249c6:
                bitset_set(current_pieces,uVar6);
              }
              (pcVar4->u18).range = piece_range;
              pcVar5 = insert_live_range_reload(pcVar4->sym,piece_range,t);
              if ((pcVar5->type & 0xfff) == 1) {
                piece_range->flags5 = piece_range->flags5 | 0x80;
              }
            }
            else {
              range = live_range_from_id(uVar6);
              (pcVar4->u18).range = range;
              if ((pcVar4->flags11 & 0x10) != 0) {
                bitset_clear(current_pieces,uVar6);
              }
            }
            if ((pcVar4->type & 0xfff) == 1) {
              puVar1 = &((pcVar4->u18).reg)->flags5;
              *puVar1 = *puVar1 | 0x80;
            }
          }
LAB_10724a06:
        }
        for (pcVar4 = t->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((pcVar4->kind == '\x01') &&
              (range = (pcVar4->u18).range, (char)*(uint32_t *)&range->kind == '\x02')) &&
             ((range->flags5 & 2) != 0)) {
            dst_pieces = (c2_bitset *)((c2_tuple_u20 *)&range->allowed)->cond_cells;
            bitset_andnot(current_pieces,dst_pieces);
            bVar8 = pcVar4->flags & 0xf;
            if (bVar8 == 0) {
              if ((pcVar4->flags11 & 0x40) == 0) {
                piece_range = new_live_range(pcVar4->sym);
                src_pieces = (c2_bitset *)range->tie;
                ((c2_symbol *)piece_range)->def = (c2_tuple *)range;
                uVar6 = ((c2_symbol *)piece_range)->id;
                ((c2_symbol *)piece_range)->dependents = src_pieces;
                bitset_set(dst_pieces,uVar6);
                bitset_set(b->live,uVar6);
              }
              else {
                uVar6 = bitset_first_common(dst_pieces,b->live_out);
                piece_range = live_range_from_id(uVar6);
              }
            }
            else {
              pcVar7 = tuple_nth_src(t,bVar8);
              piece_range = (c2_live_range *)(pcVar7->u18).reg;
            }
            uVar6 = ((c2_symbol *)piece_range)->id;
            (pcVar4->u18).range = piece_range;
            bitset_set(current_pieces,uVar6);
            if ((pcVar4->type & 0xfff) == 1) {
              ((c2_symbol *)piece_range)->flags5 = ((c2_symbol *)piece_range)->flags5 | 0x80;
            }
          }
        }
      }
      t = t->next;
    } while (t != b->end);
  } while( true );
}

