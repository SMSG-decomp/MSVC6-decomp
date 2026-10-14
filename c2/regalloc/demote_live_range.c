void __fastcall demote_live_range(c2_function *fn,c2_live_range *lr)

{
  uint8_t *puVar1;
  uint16_t type;
  ushort uVar2;
  uint32_t n;
  int iVar3;
  c2_bitset *bs;
  uint uVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  bool bVar7;
  bool bVar8;
  c2_operand *op;
  c2_tuple *t;
  c2_block *b;
  uint32_t uVar9;
  c2_operand *src;
  c2_tuple *pcVar10;
  c2_symbol *pcVar11;
  int local_18;
  
  bVar7 = false;
  bVar8 = false;
  n = lr->id;
  b = lr->first_block;
  do {
    bs = b->live;
    uVar9 = bitset_test(bs,n);
    if (uVar9 != 0) {
      bitset_clear(bs,n);
      bitset_clear(b->live_in,n);
      bitset_clear(b->live_out,n);
      t = b->head;
      if (t != b->end) {
        do {
          if ((t->flags & 1) == 0) {
LAB_10715741:
            pcVar10 = t->next;
          }
          else if (t->op == 0x163) {
            pcVar10 = t->next;
            if ((t->dst->u18).reg == (c2_symbol *)lr) {
              tuple_unlink_free(t);
            }
          }
          else {
            if (t->op != 0x164) {
              local_18 = 0;
              do {
                if (local_18 == 0) {
                  op = t->dst;
                }
                else {
                  op = t->src;
                }
                for (; op != (c2_operand *)0x0; op = op->next) {
                  if ((op->kind == '\x01') && ((op->u18).reg == (c2_symbol *)lr)) {
                    if (op->sym->cls == '\r') {
                      op = tuple_replace_src_with_base_copy(t,op,op->sym);
                    }
                    else {
                      if (((local_18 == 0) && (op->rank != 0)) && (lr->refcount == 1)) {
                        for (pcVar5 = t->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
                          if (pcVar5->kind == '\x01') {
                            pcVar11 = (pcVar5->u18).reg;
                            if ((pcVar11->cls == '\x03') && (pcVar11->def != (c2_tuple *)0x0)) {
                              tuple_delete_if_dead((c2_node *)pcVar11->def,0);
                            }
                            else if ((pcVar11->cls == '\x02') &&
                                    ((iVar3._0_2_ = pcVar11->type, iVar3._2_2_ = pcVar11->x12,
                                     iVar3 == 0 &&
                                     (g_type_class[op->type >> 0xc] ==
                                      g_type_class[pcVar5->type >> 0xc])))) {
                              if (g_ranges_pending_removal == (c2_bitset *)0x0) {
                                g_ranges_pending_removal = bitset_new(6);
                              }
                              bitset_set(g_ranges_pending_removal,pcVar11->id);
                              uVar4 = b->flags;
                              pcVar11->flags5 = pcVar11->flags5 | 2;
                              b->flags = uVar4 | 0x40000;
                            }
                          }
                        }
                        tuple_unlink_free(t);
                        b->flags = b->flags | 0x80000;
                        free_live_range(lr,1);
                        return;
                      }
                      if ((op->flags & 0x20) == 0) {
                        if ((op->flags11 & 0x80) != 0) {
                          add_reference_saving(t,lr,b);
                        }
                        bVar8 = true;
                      }
                      else {
                        bVar7 = true;
                      }
                      operand_make_sym(op);
                      type = op->sym->type;
                      if (((type & 0xfff) < (op->type & 0xfff)) && (local_18 == 0)) {
                        src = operand_new_temp(op->type);
                        src->sym->def = t;
                        pcVar10 = tuple_new(1,type,op,src,tuple_insert_after,t);
                        op = tuple_replace_dst(t,op,src);
                        uVar2 = pcVar10->type;
                        pcVar5 = pcVar10->dst;
                        pcVar6 = pcVar10->src;
                        pcVar6->type = uVar2;
                        pcVar11 = pcVar6->sym;
                        pcVar5->type = uVar2;
                        pcVar11 = symbol_get_part(pcVar11,uVar2,uVar2 & 0xfff,0);
                        uVar2 = src->type;
                        pcVar6->sym = pcVar11;
                        if ((uVar2 & 0xfff) == 1) {
                          puVar1 = &((src->u18).reg)->flags5;
                          *puVar1 = *puVar1 | 0x80;
                        }
                      }
                    }
                  }
                }
                local_18 = local_18 + 1;
              } while (local_18 < 2);
              if (bVar7) {
                uVar2 = t->line;
                bVar7 = false;
                if (uVar2 != 0) {
                  g_current_line_abs = fn->line_base + (uint)uVar2;
                  g_cur_line = uVar2;
                }
                tuple_legalize_mem_operands(t);
                b->flags = b->flags | 0x80000;
              }
              if (bVar8) {
                uVar2 = t->line;
                bVar8 = false;
                if (uVar2 != 0) {
                  g_current_line_abs = fn->line_base + (uint)uVar2;
                  g_cur_line = uVar2;
                }
                t = legalize_machine_tuple(t);
                b->flags = b->flags | 0x80000;
              }
              goto LAB_10715741;
            }
            pcVar10 = t->next;
            if ((t->src->u18).reg == (c2_symbol *)lr) {
              tuple_unlink_free(t);
            }
          }
          t = pcVar10;
        } while (t != b->end);
      }
      if (b == lr->last_block) {
        free_live_range(lr,1);
        return;
      }
    }
    b = b->next;
  } while( true );
}

