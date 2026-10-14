uint32_t compute_alias_points_to_case_ad
                   (c2_tuple *t,c2_alias_scope_slot *scope_stack,int scope_depth,c2_bitset *reaching
                   ,c2_block *block,uint32_t next_scope_cls,uint32_t list_pass,
                   c2_tuple *last_eh_call,c2_tuple *cursor,int oa,int oa_across_calls)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  ushort uVar3;
  uint uVar4;
  c2_eh_tuple_cell *pcVar5;
  c2_tuple *cursor_00;
  c2_block *pcVar6;
  c2_eh_op_try *pcVar7;
  c2_fe_symbol *pcVar8;
  c2_alias_ref *pcVar9;
  bool bVar10;
  c2_alias_call_record *pcVar11;
  uint32_t uVar12;
  c2_alias_call_record *call_rec;
  c2_bitset *pcVar13;
  c2_operand *pcVar14;
  c2_alias_memeffect *pcVar15;
  c2_tuple *pcVar16;
  int iVar17;
  c2_symbol_cell *pcVar18;
  c2_symbol_cell *member_cell;
  c2_symbol *pcVar19;
  c2_symbol_cell *copied_cell;
  c2_symbol *pcVar20;
  c2_alias_memeffect *eh_effect;
  c2_alias_memeffect *pcVar21;
  c2_alias_class_subst *pcVar22;
  c2_seh_try_scope *pcVar23;
  uint32_t alias;
  c2_eh_state *pcVar24;
  int iVar25;
  c2_eh_state *eh_state;
  c2_symbol_cell *members;
  c2_symbol *pcVar26;
  c2_operand *in_stack_0000001c;
  c2_symbol_cell *members_head;
  c2_symbol *local_storage;
  c2_symbol **member_slot;
  c2_list_cell *marker_cell;
  c2_list_cell *closing_cell;
  c2_symbol_cell *enclosing_cell;
  
  cursor_00 = cursor;
code_r0x1072c642:
  cursor = cursor_00;
  pcVar14 = memory_effect_for_call_arg(t->src,reaching,scope_stack[scope_depth].cls,(int)block);
  tuple_append_dst(t,pcVar14);
  cursor_00 = cursor;
switchD_1072c610_caseD_a8:
  cursor = cursor_00;
  for (in_stack_0000001c = t->dst; iVar25 = scope_depth, cursor_00 = cursor,
      in_stack_0000001c != (c2_operand *)0x0; in_stack_0000001c = in_stack_0000001c->next) {
    if (in_stack_0000001c->rank != 0) {
      pcVar20 = in_stack_0000001c->sym;
      pcVar26 = pcVar20->storage;
      if (pcVar26 != (c2_symbol *)0x0) {
        iVar25 = pcVar20->offset;
        do {
          if ((iVar25 <= pcVar26->offset) &&
             (pcVar26->size + pcVar26->offset <= pcVar20->size + iVar25)) {
            bitset_andnot(reaching,((pcVar26->u30).alias_info)->ref_nodes);
          }
          pcVar26 = pcVar26->part_next;
        } while (pcVar26 != (c2_symbol *)0x0);
      }
      bitset_set(reaching,in_stack_0000001c->rank);
    }
  }
LAB_1072c9ce:
  cursor = cursor_00;
  if (t == block->end) {
    bitset_free(reaching);
    (block->avail_in).set = (c2_bitset *)0x0;
    bitset_free(block->de);
    block->de = (c2_bitset *)0x0;
    bitset_free(block->kill);
    block->kill = (c2_bitset *)0x0;
    bitset_free((block->avail_out).set);
    pcVar6 = block->next;
    (block->avail_out).set = (c2_bitset *)0x0;
    if (pcVar6 == (c2_block *)0x0) {
      if ((((g_cur_function->flags & 0x18000) != 0) && (g_eh_return_branch_list != (void *)0x0)) &&
         (pcVar20 = get_cxx_eh_record(), pcVar20 != (c2_symbol *)0x0)) {
        eh_effect = arena_alloc(4,0x18);
        pcVar18 = symbol_list_add_unique(eh_effect->read,pcVar20->storage,1);
        pcVar20 = g_alias_scope_symbols;
        uVar12 = g_alias_class_count;
        eh_effect->read = pcVar18;
        eh_effect->src_cls = uVar12;
        eh_effect->scope = pcVar20;
        eh_effect->next = g_alias_eh_effect_records;
        g_alias_eh_effect_records = eh_effect;
        do {
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_src(*(c2_tuple **)((int)g_eh_return_branch_list + 4),pcVar14);
          g_eh_return_branch_list = *(void **)g_eh_return_branch_list;
        } while (g_eh_return_branch_list != (void *)0x0);
        g_alias_class_count = g_alias_class_count + 1;
        g_eh_return_branch_list = (void *)0x0;
      }
      return next_scope_cls;
    }
    reaching = (pcVar6->avail_in).set;
    cursor = pcVar6->head;
    iVar25 = scope_depth;
    block = pcVar6;
  }
  while( true ) {
    cursor_00 = cursor->next;
    uVar3 = cursor->line;
    if (uVar3 != 0) {
      g_current_line_abs = g_cur_function->line_base + (uint)uVar3;
      g_cur_line = uVar3;
    }
    t = cursor;
    if ((cursor->flags & 1) == 0) goto LAB_1072cc29;
    if (cursor->op != 0x191) break;
    pcVar9 = g_alias_ref_table;
    for (pcVar14 = cursor->dst; g_alias_ref_table = pcVar9, in_stack_0000001c = pcVar14,
        pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
      uVar12 = pcVar14->rank;
      if (uVar12 != 0) {
        if (oa == 0) {
          pcVar18 = symbol_list_add_unique(pcVar9[uVar12].pointees,g_alias_special_symbol,4);
          pcVar9[uVar12].pointees = pcVar18;
        }
        pcVar18 = symbol_list_add_unique(pcVar9[uVar12].pointees,scope_stack[iVar25].scope,4);
        pcVar20 = pcVar14->sym;
        pcVar9[uVar12].pointees = pcVar18;
        pcVar26 = pcVar20->storage;
        if (pcVar26 != (c2_symbol *)0x0) {
          iVar25 = pcVar20->offset;
          do {
            if ((iVar25 <= pcVar26->offset) &&
               (pcVar26->size + pcVar26->offset <= pcVar20->size + iVar25)) {
              bitset_andnot(reaching,((pcVar26->u30).alias_info)->ref_nodes);
            }
            pcVar26 = pcVar26->part_next;
          } while (pcVar26 != (c2_symbol *)0x0);
        }
        pcVar14 = in_stack_0000001c;
        bitset_set(reaching,in_stack_0000001c->rank);
        iVar25 = scope_depth;
      }
      pcVar9 = g_alias_ref_table;
    }
    pcVar21 = arena_alloc(4,0x18);
    alias_collect_symbols_in_range((cursor->u20).default_label,(c2_tuple *)0x0,1,1,pcVar21);
    pcVar14 = operand_new_memeffect(g_alias_class_count);
    tuple_append_dst(cursor,pcVar14);
    pcVar21->dst_cls = g_alias_class_count;
    g_alias_class_count = g_alias_class_count + 1;
    pcVar14 = operand_new_memeffect(g_alias_class_count);
    tuple_append_src(cursor,pcVar14);
    pcVar21->src_cls = g_alias_class_count;
    g_alias_class_count = g_alias_class_count + 1;
    pcVar21->scope = scope_stack[iVar25].scope;
    pcVar21->next = g_alias_eh_effect_records;
    cursor = cursor_00;
    g_alias_eh_effect_records = pcVar21;
  }
  if (cursor->op == 0x19c) {
    if (g_alias_seh_edge_class == 0) {
      g_alias_seh_edge_class = g_alias_class_count;
      g_alias_class_count = g_alias_class_count + 1;
    }
    pcVar14 = operand_new_memeffect(g_alias_seh_edge_class);
    tuple_append_dst(cursor,pcVar14);
  }
  list_pass = 0;
  do {
    if (list_pass == 0) {
      pcVar14 = cursor->dst;
    }
    else {
      pcVar14 = cursor->src;
    }
    for (; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
      if ((1 << (pcVar14->kind & 0x1f) & 0x60U) == 0) {
        if ((pcVar14->kind == 2) && ((pcVar14->flags & 0x40) != 0)) {
          puVar1 = &pcVar14->sym->storage->flags5;
          *puVar1 = *puVar1 | 0x40;
        }
      }
      else {
        if (pcVar14->base == (c2_operand *)0x0) {
          pcVar14->tag = scope_stack[iVar25].cls;
          if (oa != 0) {
            (pcVar14->u18).reg = g_alias_unknown_base;
          }
        }
        else {
          if (oa == 0) {
            uVar12 = alias_class_for_memory_base
                               (pcVar14->base->sym,reaching,scope_stack[iVar25].cls,block);
          }
          else {
            uVar12 = alias_class_for_operand(pcVar14,reaching,scope_stack[iVar25].cls);
          }
          pcVar14->tag = uVar12;
        }
        if (((pcVar14->flags & 0x80) != 0) && (g_alias_analysis_overflow == 0)) {
          uVar4 = pcVar14->tag;
          if (uVar4 < g_alias_class_skip_index) {
            if (g_alias_loadv_class == 0) {
              g_alias_loadv_class = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
            }
            pcVar14->tag = g_alias_loadv_class;
            if (oa != 0) {
              (pcVar14->u18).reg = g_alias_unknown_base;
            }
          }
          else {
            pcVar22 = g_alias_loadv_class_substitutions;
            if (g_alias_symbol_class_count <= uVar4) {
              for (; pcVar22 != (c2_alias_class_subst *)0x0; pcVar22 = pcVar22->next) {
                if (pcVar22->from_cls == uVar4) {
                  if (pcVar22 != (c2_alias_class_subst *)0x0) {
                    pcVar14->tag = pcVar22->to_cls;
                    goto LAB_1072ca5e;
                  }
                  break;
                }
              }
              pcVar22 = arena_alloc(4,0xc);
              pcVar22->to_cls = g_alias_class_count;
              pcVar14->tag = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar22->from_cls = uVar4;
              pcVar22->next = g_alias_loadv_class_substitutions;
              g_alias_loadv_class_substitutions = pcVar22;
            }
          }
        }
      }
LAB_1072ca5e:
    }
    list_pass = list_pass + 1;
  } while (list_pass < 2);
  uVar2 = cursor->kind;
  if (uVar2 == '\x0e') {
    pcVar20 = scope_stack[iVar25].scope;
    alias_add_pointee(cursor,oa,pcVar20);
    uVar12 = g_alias_class_count;
    for (pcVar14 = cursor->src; g_alias_class_count = uVar12, pcVar14 != (c2_operand *)0x0;
        pcVar14 = pcVar14->next) {
      if ((((1 << (pcVar14->kind & 0x1f) & 6U) != 0) &&
          (pcVar16 = pcVar14->sym->def, pcVar16 != (c2_tuple *)0x0)) &&
         ((pcVar16->op == 0x15a || (pcVar16->op == 0x16a)))) {
        mark_address_taken_operand(pcVar16->src,reaching);
      }
      uVar12 = g_alias_class_count;
    }
    if (oa == 0) {
      uVar12 = scope_stack[scope_depth].cls;
    }
    else if (oa_across_calls == 0) {
      pcVar14 = operand_new_memeffect(3);
      tuple_append_src(cursor,pcVar14);
      tuple_append_dst(cursor,pcVar14);
      uVar12 = scope_stack[scope_depth].cls;
    }
    else {
      g_alias_class_count = uVar12 + 1;
      call_rec = arena_alloc(4,0x14);
      pcVar11 = call_rec;
      call_rec->next = g_alias_call_records;
      g_alias_call_records = pcVar11;
      call_rec->scope = pcVar20;
      call_rec->cls = uVar12;
      pcVar13 = bitset_new(6);
      pcVar14 = cursor->src;
      call_rec->pointee_nodes = pcVar13;
      for (; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
        if ((((1 << (pcVar14->kind & 0x1f) & 6U) != 0) &&
            (pcVar16 = pcVar14->sym->def, pcVar16 != (c2_tuple *)0x0)) &&
           ((pcVar16->op == 0x15a || (pcVar16->op == 0x16a)))) {
          alias_collect_pointees(pcVar16->src,call_rec,reaching);
        }
      }
    }
    pcVar14 = operand_new_memeffect(uVar12);
    tuple_append_src(cursor,pcVar14);
    tuple_append_dst(cursor,pcVar14);
    goto switchD_1072c610_caseD_a8;
  }
  if (uVar2 != '\x12') {
    if (uVar2 == '\x14') {
      switch(cursor->op) {
      case 0x194:
      case 0x196:
      case 0x198:
        if (g_opt_basic == 0) {
          pcVar21 = arena_alloc(4,0x18);
          alias_collect_symbols_in_range(((cursor->u20).seh_scope)->begin_tuple,cursor,1,0,pcVar21);
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_dst(cursor,pcVar14);
          pcVar21->dst_cls = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          pcVar21->next = g_alias_eh_effect_records;
          g_alias_eh_effect_records = pcVar21;
          pcVar21->scope = scope_stack[iVar25].scope;
        }
        goto switchD_1072c610_caseD_a8;
      case 0x195:
        if (g_opt_basic == 0) {
          pcVar16 = ((((cursor->u20).seh_scope)->handler_label->u32).label_tuple)->next;
          pcVar21 = arena_alloc(4,0x18);
          alias_collect_symbols_in_range(pcVar16,cursor,1,1,pcVar21);
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_dst(pcVar16,pcVar14);
          pcVar21->next = g_alias_eh_effect_records;
          pcVar20 = scope_stack[iVar25].scope;
          pcVar23 = (cursor->u20).seh_scope;
          pcVar21->src_cls = g_alias_class_count;
          alias = g_alias_class_count + 1;
          uVar12 = pcVar23->flags;
          g_alias_class_count = alias;
          pcVar21->scope = pcVar20;
          if ((uVar12 & 2) != 0) {
            pcVar14 = operand_new_memeffect(alias);
            tuple_append_src(cursor,pcVar14);
            pcVar21->dst_cls = g_alias_class_count;
            g_alias_class_count = g_alias_class_count + 1;
            pcVar21->scope = pcVar20;
            pcVar21->next = g_alias_eh_effect_records;
          }
          g_alias_eh_effect_records = pcVar21;
          pcVar14 = operand_new_memeffect(scope_stack[iVar25].cls);
          tuple_append_src(cursor,pcVar14);
        }
        goto switchD_1072c610_caseD_a8;
      case 0x1a0:
        eh_state = ((cursor->u20).eh_construct)->object;
        if (eh_state->funclet != (c2_function *)0x0) {
          if ((g_opt_eh_enabled != 0) || ((eh_state->flags & 0x1000) != 0)) {
            if (eh_state->funclet_syms == (c2_symbol_cell *)0x0) {
              pcVar15 = arena_alloc(4,0x18);
              iVar17 = 1;
              iVar25 = 0;
              pcVar21 = pcVar15;
              pcVar16 = eh_funclet_entry_tuple(cursor);
              alias_collect_symbols_in_range(pcVar16,(c2_tuple *)0x0,iVar25,iVar17,pcVar21);
              eh_state = ((cursor->u20).eh_construct)->object;
              pcVar24 = eh_state->parent;
              if (pcVar24 != (c2_eh_state *)0x0) {
                while (pcVar24->funclet_syms == (c2_symbol_cell *)0x0) {
                  if ((char)pcVar24->flags == '\x04') {
                    pcVar21 = arena_alloc(4,0x18);
                    alias_collect_symbols_in_range
                              (pcVar24->funclet->cfg->first->head,(c2_tuple *)0x0,0,1,pcVar21);
                    pcVar20 = get_cxx_eh_record();
                    if (pcVar20 != (c2_symbol *)0x0) {
                      pcVar18 = symbol_list_add_unique(pcVar21->read,pcVar20->storage,1);
                      pcVar21->read = pcVar18;
                    }
                    pcVar18 = pcVar21->read;
                    pcVar24->funclet_cls = g_alias_class_count;
                    pcVar21->src_cls = g_alias_class_count;
                    g_alias_class_count = g_alias_class_count + 1;
                    pcVar24->funclet_syms = pcVar18;
                    pcVar21->scope = scope_stack[scope_depth].scope;
                    pcVar21->next = g_alias_eh_effect_records;
                    g_alias_eh_effect_records = pcVar21;
                  }
                  if (pcVar24->funclet_syms != (c2_symbol_cell *)0x0) break;
                  pcVar24 = pcVar24->parent;
                  if (pcVar24 == (c2_eh_state *)0x0) goto LAB_1072c7d9;
                }
                pcVar18 = symbol_list_add_all(pcVar15->read,pcVar24->funclet_syms,1);
                pcVar15->read = pcVar18;
              }
LAB_1072c7d9:
              pcVar20 = get_cxx_eh_record();
              if (pcVar20 != (c2_symbol *)0x0) {
                pcVar18 = symbol_list_add_unique(pcVar15->read,pcVar20->storage,1);
                pcVar15->read = pcVar18;
              }
              eh_state->funclet_syms = pcVar15->read;
              eh_state->funclet_cls = g_alias_class_count;
              pcVar15->src_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar15->scope = scope_stack[scope_depth].scope;
              pcVar15->next = g_alias_eh_effect_records;
              g_alias_eh_effect_records = pcVar15;
            }
            uVar12 = eh_state->funclet_cls;
            for (pcVar5 = eh_state->return_branches; pcVar5 != (c2_eh_tuple_cell *)0x0;
                pcVar5 = pcVar5->next) {
              pcVar14 = operand_new_memeffect(uVar12);
              tuple_append_src(pcVar5->tuple,pcVar14);
            }
            iVar25 = scope_depth;
            if (g_opt_eh_enabled != 0) goto switchD_1072c610_caseD_a8;
          }
          if (((byte)((cursor->u20).eh_construct)->flags & 7) == 4) {
            alias_add_call_memeffects
                      (cursor,eh_state,scope_stack[iVar25].cls,scope_stack[iVar25].scope);
            last_eh_call = cursor;
          }
        }
        goto switchD_1072c610_caseD_a8;
      case 0x1a4:
        eh_effect = arena_alloc(4,0x18);
        for (pcVar23 = (((cursor->u20).default_label)->prev->u20).seh_scope;
            pcVar23 != (c2_seh_try_scope *)0x0; pcVar23 = pcVar23->next) {
          if (pcVar23->enclosing_level != 0) {
            pcVar18 = symbol_list_add_unique
                                (eh_effect->written,
                                 *(c2_symbol **)(*(int *)(pcVar23->enclosing_level + 8) + 8),1);
            eh_effect->written = pcVar18;
          }
        }
        if (eh_effect->written != (c2_symbol_cell *)0x0) {
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_dst(cursor,pcVar14);
          eh_effect->dst_cls = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          eh_effect->next = g_alias_eh_effect_records;
          g_alias_eh_effect_records = eh_effect;
          eh_effect->scope = scope_stack[iVar25].scope;
        }
        goto switchD_1072c610_caseD_a8;
      case 0x1a5:
        pcVar7 = (cursor->u20).eh_try;
        pcVar8 = pcVar7->catch_rec->object;
        if (g_opt_eh_enabled == 0) {
          pcVar21 = arena_alloc(4,0x18);
          pcVar16 = pcVar7->try_block->begin_tuple;
          alias_collect_symbols_in_range
                    (pcVar16,(((pcVar16->u20).eh_try)->try_block->catches->label->u32).label_tuple,1
                     ,0,pcVar21);
          if (pcVar8 != (c2_fe_symbol *)0x0) {
            pcVar18 = symbol_list_add_unique(pcVar21->written,pcVar8->storage_sym->storage,1);
            pcVar21->written = pcVar18;
          }
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_dst(cursor,pcVar14);
          pcVar21->dst_cls = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          pcVar21->scope = scope_stack[scope_depth].scope;
          pcVar21->next = g_alias_eh_effect_records;
          g_alias_eh_effect_records = pcVar21;
        }
        else if (pcVar8 != (c2_fe_symbol *)0x0) {
          pcVar14 = operand_new_memeffect((uint)(pcVar8->u3e).alias_class);
          tuple_append_dst(cursor,pcVar14);
        }
        goto switchD_1072c610_caseD_a8;
      case 0x1a8:
        if (g_opt_eh_enabled == 0) {
          alias_add_call_memeffects
                    (cursor,((cursor->u20).eh_construct)->object,scope_stack[iVar25].cls,
                     scope_stack[iVar25].scope);
          goto switchD_1072c610_caseD_a8;
        }
      }
    }
    else if (((cursor->op == 0x16c) && (g_opt_eh_enabled == 0)) &&
            (g_eh_return_object_record != (c2_eh_state *)0x0)) {
      alias_add_call_memeffects
                (cursor,((last_eh_call->u20).eh_construct)->object,scope_stack[iVar25].cls,
                 scope_stack[iVar25].scope);
      goto switchD_1072c610_caseD_a8;
    }
    for (in_stack_0000001c = cursor->dst; in_stack_0000001c != (c2_operand *)0x0;
        in_stack_0000001c = in_stack_0000001c->next) {
      if (in_stack_0000001c->rank == 0) {
        if (((1 << (in_stack_0000001c->kind & 0x1f) & 6U) == 0) ||
           (in_stack_0000001c->sym->def == (c2_tuple *)0x0)) {
          for (pcVar14 = cursor->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
            mark_address_taken_operand(pcVar14,reaching);
          }
          if (oa != 0) {
            if (in_stack_0000001c->kind == '\x02') {
              pcVar20 = in_stack_0000001c->sym->storage;
            }
            else if ((in_stack_0000001c->kind != '\x06') ||
                    (pcVar20 = (c2_symbol *)(in_stack_0000001c->u18).range,
                    pcVar20 == g_alias_unknown_base)) goto LAB_1072c998;
            if (pcVar20 != (c2_symbol *)0x0) {
              for (pcVar14 = cursor->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
                alias_collect_pointees_of_tree_offset
                          (pcVar20,pcVar14,reaching,((pcVar20->u30).alias_info)->points_to);
              }
            }
          }
        }
      }
      else {
        bVar10 = false;
        pcVar9 = g_alias_ref_table + in_stack_0000001c->rank;
        if (((cursor->op == 0x15b) && (pcVar14 = cursor->src, pcVar14->kind == '\a')) &&
           ((pcVar14->u18).reg != (c2_symbol *)0x0 || pcVar14->tag != 0)) {
          bVar10 = true;
        }
        else {
          pcVar14 = cursor->src;
          if (oa == 0) {
            for (; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
              iVar17 = alias_collect_pointees_of_tree(pcVar14,reaching,pcVar9);
              if (iVar17 != 0) {
                bVar10 = true;
              }
            }
          }
          else {
            for (; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
              iVar17 = alias_collect_pointees_of_tree_offset
                                 (in_stack_0000001c->sym,pcVar14,reaching,pcVar9);
              if (iVar17 != 0) {
                bVar10 = true;
              }
            }
          }
        }
        if ((in_stack_0000001c->sym->flags6 & 0x10) != 0) {
          for (pcVar14 = cursor->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next) {
            mark_address_taken_operand(pcVar14,reaching);
          }
        }
        if (bVar10) {
          if (oa == 0) {
            pcVar18 = symbol_list_add_unique(pcVar9->pointees,g_alias_special_symbol,4);
            pcVar9->pointees = pcVar18;
          }
          pcVar18 = symbol_list_add_unique(pcVar9->pointees,scope_stack[iVar25].scope,4);
          pcVar9->pointees = pcVar18;
        }
      }
LAB_1072c998:
    }
    goto switchD_1072c610_caseD_a8;
  }
  pcVar20 = scope_stack[scope_depth].scope;
  alias_add_pointee(cursor,oa,pcVar20);
  switch((cursor->u20).intrinsic.id) {
  case 0xa3:
    pcVar14 = memory_effect_for_call_arg
                        (cursor->src,reaching,scope_stack[scope_depth].cls,(int)block);
    tuple_append_src(cursor,pcVar14);
    uVar12 = compute_alias_points_to_case_ad
                       (cursor,scope_stack,scope_depth,reaching,block,next_scope_cls,list_pass,
                        last_eh_call,cursor_00,oa,oa_across_calls);
    return uVar12;
  case 0xa4:
  case 0xac:
    uVar12 = scope_stack[scope_depth].cls;
    pcVar14 = memory_effect_for_call_arg(cursor->src,reaching,uVar12,(int)block);
    tuple_append_dst(cursor,pcVar14);
    pcVar14 = memory_effect_for_call_arg(cursor->src->next,reaching,uVar12,(int)block);
    tuple_append_src(cursor,pcVar14);
    goto switchD_1072c610_caseD_a8;
  case 0xa5:
  case 0xaa:
    uVar12 = scope_stack[scope_depth].cls;
    pcVar14 = memory_effect_for_call_arg(cursor->src,reaching,uVar12,(int)block);
    tuple_append_src(cursor,pcVar14);
    pcVar14 = memory_effect_for_call_arg(cursor->src->next,reaching,uVar12,(int)block);
    tuple_append_src(cursor,pcVar14);
    goto switchD_1072c610_caseD_a8;
  case 0xa6:
    uVar12 = scope_stack[scope_depth].cls;
    pcVar14 = memory_effect_for_call_arg(cursor->src,reaching,uVar12,(int)block);
    tuple_append_dst(cursor,pcVar14);
    pcVar14 = memory_effect_for_call_arg(cursor->src->next,reaching,uVar12,(int)block);
    tuple_append_src(cursor,pcVar14);
    break;
  case 0xa7:
    uVar12 = scope_stack[scope_depth].cls;
    break;
  default:
    goto switchD_1072c610_caseD_a8;
  case 0xad:
    goto code_r0x1072c642;
  case 0x11b:
  case 0x11c:
  case 0x11d:
  case 0x13e:
  case 0x13f:
  case 0x14b:
    pcVar14 = operand_new_memeffect(scope_stack[scope_depth].cls);
    tuple_append_src(cursor,pcVar14);
    tuple_append_dst(cursor,pcVar14);
    goto switchD_1072c610_caseD_a8;
  case 0x17a:
    if (g_opt_basic == 0) {
      for (pcVar16 = cursor->prev; (pcVar16 != (c2_tuple *)0x0 && (pcVar16->op != 0x192));
          pcVar16 = pcVar16->prev) {
      }
      pcVar26 = (cursor->src->sym->def->src->u18).reg;
      for (pcVar23 = (pcVar16->u20).seh_scope;
          (pcVar23 != (c2_seh_try_scope *)0x0 && ((int)pcVar26 < pcVar23->level));
          pcVar23 = seh_find_try_record(g_seh_try_records,pcVar23->enclosing_level)) {
        if (pcVar23->kind == 2) {
          pcVar21 = arena_alloc(4,0x18);
          alias_collect_symbols_in_range
                    ((pcVar23->handler_label->u32).label_tuple,
                     (pcVar23->continuation_label->u32).label_tuple,1,1,pcVar21);
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_src(cursor,pcVar14);
          pcVar21->src_cls = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          pcVar14 = operand_new_memeffect(g_alias_class_count);
          tuple_append_dst(cursor,pcVar14);
          pcVar21->dst_cls = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          pcVar21->scope = pcVar20;
          uVar12 = scope_stack[scope_depth].cls;
          pcVar21->next = g_alias_eh_effect_records;
          g_alias_eh_effect_records = pcVar21;
          pcVar14 = operand_new_memeffect(uVar12);
          tuple_append_dst(cursor,pcVar14);
          tuple_append_src(cursor,pcVar14);
        }
      }
    }
    goto switchD_1072c610_caseD_a8;
  case 0x17d:
    pcVar14 = operand_new_memeffect(scope_stack[scope_depth].cls);
    tuple_append_dst(cursor,pcVar14);
    goto switchD_1072c610_caseD_a8;
  case 0x17f:
  case 0x180:
  case 0x184:
    uVar12 = scope_stack[scope_depth].cls;
    break;
  case 0x181:
    uVar12 = scope_stack[scope_depth].cls;
    pcVar14 = memory_effect_for_call_arg(cursor->src,reaching,uVar12,(int)block);
    tuple_append_dst(cursor,pcVar14);
  }
  pcVar14 = memory_effect_for_call_arg(cursor->src,reaching,uVar12,(int)block);
  tuple_append_src(cursor,pcVar14);
  goto switchD_1072c610_caseD_a8;
LAB_1072cc29:
  if (cursor->kind == '\x16') {
    if (cursor->op == 0x1b4) {
      marker_cell = (cursor->u14).scope_locals;
      members = (c2_symbol_cell *)0x0;
      if (marker_cell != (c2_list_cell *)0x0) {
        do {
          local_storage = ((marker_cell->u04).sym)->storage;
          if ((local_storage != (c2_symbol *)0x0) && ((local_storage->flags5 & 2) != 0)) {
            member_cell = arena_alloc(1,8);
            member_cell->next = members;
            member_cell->sym = local_storage;
            members = member_cell;
          }
          marker_cell = marker_cell->next;
        } while (marker_cell != (c2_list_cell *)0x0);
        if (members != (c2_symbol_cell *)0x0) {
          pcVar19 = arena_alloc(1,0x54);
          pcVar26 = g_alias_scope_symbols;
          pcVar20 = scope_stack[scope_depth].scope;
          g_alias_scope_symbols = pcVar19;
          (pcVar19->u30).members = members;
          pcVar19->cls = '\f';
          enclosing_cell = (pcVar20->u30).members;
          pcVar19->order_next = pcVar26;
          while (enclosing_cell != (c2_symbol_cell *)0x0) {
            copied_cell = arena_alloc(1,8);
            member_slot = &enclosing_cell->sym;
            enclosing_cell = enclosing_cell->next;
            members_head = (pcVar19->u30).members;
            copied_cell->sym = *member_slot;
            copied_cell->next = members_head;
            (pcVar19->u30).members = copied_cell;
          }
          scope_depth = scope_depth + 1;
          scope_stack[scope_depth].scope = pcVar19;
          scope_stack[scope_depth].cls = next_scope_cls;
          next_scope_cls = next_scope_cls + 1;
        }
      }
      tuple_unlink_free(cursor);
      iVar25 = scope_depth;
    }
    else if (cursor->op == 0x1b5) {
      closing_cell = (cursor->u14).scope_locals;
      if (closing_cell == (c2_list_cell *)0x0) {
LAB_1072cd3f:
        tuple_unlink_free(cursor);
      }
      else {
        do {
          pcVar20 = ((closing_cell->u04).sym)->storage;
          if ((pcVar20 != (c2_symbol *)0x0) && ((pcVar20->flags5 & 2) != 0)) {
            if (closing_cell != (c2_list_cell *)0x0) {
              iVar25 = iVar25 + -1;
              scope_depth = iVar25;
            }
            goto LAB_1072cd3f;
          }
          closing_cell = closing_cell->next;
        } while (closing_cell != (c2_list_cell *)0x0);
        tuple_unlink_free(cursor);
      }
    }
  }
  goto LAB_1072c9ce;
}

