uint32_t __fastcall
compute_alias_points_to(c2_block *first,uint32_t nscopes,int oa,int oa_across_calls)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  ushort uVar3;
  uint uVar4;
  c2_eh_state *pcVar5;
  c2_eh_tuple_cell *pcVar6;
  c2_operand *pcVar7;
  c2_eh_op_try *pcVar8;
  c2_fe_symbol *pcVar9;
  c2_alias_call_record *pcVar10;
  c2_alias_scope_slot *scopes;
  uint32_t uVar11;
  c2_alias_call_record *call_rec;
  c2_bitset *mask;
  c2_alias_memeffect *pcVar12;
  c2_tuple *pcVar13;
  int iVar14;
  c2_symbol_cell *taken_list;
  c2_symbol *pcVar15;
  c2_symbol_cell *member_copy;
  c2_symbol *pcVar16;
  c2_alias_memeffect *region_effect;
  c2_symbol_cell *pcVar17;
  c2_operand *pcVar18;
  c2_alias_memeffect *pcVar19;
  c2_alias_class_subst *pcVar20;
  c2_seh_try_scope *pcVar21;
  uint32_t alias;
  c2_symbol_cell *taken_prev;
  c2_eh_state *eh_object;
  c2_tuple *t;
  c2_symbol *pcVar22;
  c2_eh_state *pcVar23;
  bool bVar24;
  int iVar25;
  c2_bitset *pcVar26;
  c2_block *pcVar27;
  int iVar28;
  uint list_pass;
  c2_tuple *next_tuple;
  uint32_t next_scope_cls;
  int depth;
  c2_symbol_cell *members_head;
  c2_symbol *marker_storage;
  c2_symbol **member_slot;
  c2_list_cell *marker_cell;
  c2_list_cell *closing_cell;
  c2_tuple *return_object_ctor;
  c2_alias_ref *refs;
  
  depth = 0;
  next_scope_cls = 4;
  scopes = arena_alloc(4,nscopes << 3);
  scopes->scope = g_alias_scope_symbols;
  scopes->cls = 3;
  if (oa != 0) {
    g_alias_unknown_base = arena_alloc(4,0x54);
  }
  do {
    if (first == (c2_block *)0x0) {
      if ((((g_cur_function->flags & 0x18000) != 0) && (g_eh_return_branch_list != (void *)0x0)) &&
         (pcVar16 = get_cxx_eh_record(), pcVar16 != (c2_symbol *)0x0)) {
        region_effect = arena_alloc(4,0x18);
        pcVar17 = symbol_list_add_unique(region_effect->read,pcVar16->storage,1);
        pcVar16 = g_alias_scope_symbols;
        uVar11 = g_alias_class_count;
        region_effect->read = pcVar17;
        region_effect->src_cls = uVar11;
        region_effect->scope = pcVar16;
        region_effect->next = g_alias_eh_effect_records;
        g_alias_eh_effect_records = region_effect;
        do {
          pcVar18 = operand_new_memeffect(g_alias_class_count);
          tuple_append_src(*(c2_tuple **)((int)g_eh_return_branch_list + 4),pcVar18);
          g_eh_return_branch_list = *(void **)g_eh_return_branch_list;
        } while (g_eh_return_branch_list != (void *)0x0);
        g_alias_class_count = g_alias_class_count + 1;
        g_eh_return_branch_list = (void *)0x0;
      }
      return next_scope_cls;
    }
    mask = (first->avail_in).set;
    t = first->head;
    iVar25 = depth;
LAB_1072c9df:
    do {
      next_tuple = t->next;
      uVar3 = t->line;
      if (uVar3 != 0) {
        g_current_line_abs = g_cur_function->line_base + (uint)uVar3;
        g_cur_line = uVar3;
      }
      if ((t->flags & 1) == 0) {
        if (t->kind == '\x16') {
          if (t->op == 0x1b4) {
            marker_cell = (t->u14).scope_locals;
            taken_prev = (c2_symbol_cell *)0x0;
            depth = iVar25;
            if (marker_cell != (c2_list_cell *)0x0) {
              do {
                marker_storage = ((marker_cell->u04).sym)->storage;
                if ((marker_storage != (c2_symbol *)0x0) && ((marker_storage->flags5 & 2) != 0)) {
                  taken_list = arena_alloc(1,8);
                  taken_list->next = taken_prev;
                  taken_list->sym = marker_storage;
                  taken_prev = taken_list;
                }
                marker_cell = marker_cell->next;
              } while (marker_cell != (c2_list_cell *)0x0);
              if (taken_prev != (c2_symbol_cell *)0x0) {
                pcVar15 = arena_alloc(1,0x54);
                pcVar22 = g_alias_scope_symbols;
                pcVar16 = scopes[depth].scope;
                g_alias_scope_symbols = pcVar15;
                (pcVar15->u30).members = taken_prev;
                pcVar15->cls = '\f';
                pcVar17 = (pcVar16->u30).members;
                pcVar15->order_next = pcVar22;
                while (pcVar17 != (c2_symbol_cell *)0x0) {
                  member_copy = arena_alloc(1,8);
                  member_slot = &pcVar17->sym;
                  pcVar17 = pcVar17->next;
                  members_head = (pcVar15->u30).members;
                  member_copy->sym = *member_slot;
                  member_copy->next = members_head;
                  (pcVar15->u30).members = member_copy;
                }
                depth = depth + 1;
                scopes[depth].scope = pcVar15;
                scopes[depth].cls = next_scope_cls;
                next_scope_cls = next_scope_cls + 1;
              }
            }
            tuple_unlink_free(t);
            iVar25 = depth;
          }
          else if (t->op == 0x1b5) {
            closing_cell = (t->u14).scope_locals;
            if (closing_cell == (c2_list_cell *)0x0) {
LAB_1072cd3f:
              tuple_unlink_free(t);
            }
            else {
              do {
                pcVar16 = ((closing_cell->u04).sym)->storage;
                if ((pcVar16 != (c2_symbol *)0x0) && ((pcVar16->flags5 & 2) != 0)) {
                  if (closing_cell != (c2_list_cell *)0x0) {
                    depth = depth + -1;
                    iVar25 = depth;
                  }
                  goto LAB_1072cd3f;
                }
                closing_cell = closing_cell->next;
              } while (closing_cell != (c2_list_cell *)0x0);
              tuple_unlink_free(t);
            }
          }
        }
        goto LAB_1072c9ce;
      }
      if (t->op == 0x191) {
        refs = g_alias_ref_table;
        for (pcVar18 = t->dst; g_alias_ref_table = refs, pcVar18 != (c2_operand *)0x0;
            pcVar18 = pcVar18->next) {
          uVar11 = pcVar18->rank;
          if (uVar11 != 0) {
            if (oa == 0) {
              pcVar17 = symbol_list_add_unique(refs[uVar11].pointees,g_alias_special_symbol,4);
              refs[uVar11].pointees = pcVar17;
            }
            pcVar17 = symbol_list_add_unique(refs[uVar11].pointees,scopes[depth].scope,4);
            pcVar16 = pcVar18->sym;
            refs[uVar11].pointees = pcVar17;
            pcVar22 = pcVar16->storage;
            depth = iVar25;
            if (pcVar22 != (c2_symbol *)0x0) {
              iVar25 = pcVar16->offset;
              do {
                if ((iVar25 <= pcVar22->offset) &&
                   (pcVar22->size + pcVar22->offset <= pcVar16->size + iVar25)) {
                  bitset_andnot(mask,((pcVar22->u30).alias_info)->ref_nodes);
                }
                pcVar22 = pcVar22->part_next;
              } while (pcVar22 != (c2_symbol *)0x0);
            }
            bitset_set(mask,pcVar18->rank);
            iVar25 = depth;
          }
          refs = g_alias_ref_table;
        }
        pcVar19 = arena_alloc(4,0x18);
        alias_collect_symbols_in_range((t->u20).default_label,(c2_tuple *)0x0,1,1,pcVar19);
        pcVar18 = operand_new_memeffect(g_alias_class_count);
        tuple_append_dst(t,pcVar18);
        pcVar19->dst_cls = g_alias_class_count;
        g_alias_class_count = g_alias_class_count + 1;
        pcVar18 = operand_new_memeffect(g_alias_class_count);
        tuple_append_src(t,pcVar18);
        pcVar19->src_cls = g_alias_class_count;
        g_alias_class_count = g_alias_class_count + 1;
        pcVar19->scope = scopes[depth].scope;
        pcVar19->next = g_alias_eh_effect_records;
        t = next_tuple;
        g_alias_eh_effect_records = pcVar19;
        goto LAB_1072c9df;
      }
      if (t->op == 0x19c) {
        if (g_alias_seh_edge_class == 0) {
          g_alias_seh_edge_class = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
        }
        pcVar18 = operand_new_memeffect(g_alias_seh_edge_class);
        tuple_append_dst(t,pcVar18);
      }
      list_pass = 0;
      do {
        if (list_pass == 0) {
          pcVar18 = t->dst;
        }
        else {
          pcVar18 = t->src;
        }
        for (; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next) {
          if ((1 << (pcVar18->kind & 0x1f) & 0x60U) == 0) {
            if ((pcVar18->kind == 2) && ((pcVar18->flags & 0x40) != 0)) {
              puVar1 = &pcVar18->sym->storage->flags5;
              *puVar1 = *puVar1 | 0x40;
            }
          }
          else {
            if (pcVar18->base == (c2_operand *)0x0) {
              pcVar18->tag = scopes[depth].cls;
              if (oa != 0) {
                (pcVar18->u18).reg = g_alias_unknown_base;
              }
            }
            else {
              if (oa == 0) {
                uVar11 = alias_class_for_memory_base
                                   (pcVar18->base->sym,mask,scopes[depth].cls,first);
              }
              else {
                uVar11 = alias_class_for_operand(pcVar18,mask,scopes[depth].cls);
              }
              pcVar18->tag = uVar11;
            }
            if (((pcVar18->flags & 0x80) != 0) && (g_alias_analysis_overflow == 0)) {
              uVar4 = pcVar18->tag;
              if (uVar4 < g_alias_class_skip_index) {
                if (g_alias_loadv_class == 0) {
                  g_alias_loadv_class = g_alias_class_count;
                  g_alias_class_count = g_alias_class_count + 1;
                }
                pcVar18->tag = g_alias_loadv_class;
                if (oa != 0) {
                  (pcVar18->u18).reg = g_alias_unknown_base;
                }
              }
              else {
                pcVar20 = g_alias_loadv_class_substitutions;
                if (g_alias_symbol_class_count <= uVar4) {
                  for (; pcVar20 != (c2_alias_class_subst *)0x0; pcVar20 = pcVar20->next) {
                    if (pcVar20->from_cls == uVar4) {
                      if (pcVar20 != (c2_alias_class_subst *)0x0) {
                        pcVar18->tag = pcVar20->to_cls;
                        goto LAB_1072ca5e;
                      }
                      break;
                    }
                  }
                  pcVar20 = arena_alloc(4,0xc);
                  pcVar20->to_cls = g_alias_class_count;
                  pcVar18->tag = g_alias_class_count;
                  g_alias_class_count = g_alias_class_count + 1;
                  pcVar20->from_cls = uVar4;
                  pcVar20->next = g_alias_loadv_class_substitutions;
                  g_alias_loadv_class_substitutions = pcVar20;
                }
              }
            }
          }
LAB_1072ca5e:
        }
        list_pass = list_pass + 1;
      } while (list_pass < 2);
      uVar2 = t->kind;
      if (uVar2 == '\x0e') {
        pcVar16 = scopes[depth].scope;
        alias_add_pointee(t,oa,pcVar16);
        uVar11 = g_alias_class_count;
        pcVar26 = mask;
        for (pcVar18 = t->src; g_alias_class_count = uVar11, pcVar18 != (c2_operand *)0x0;
            pcVar18 = pcVar18->next) {
          if ((((1 << (pcVar18->kind & 0x1f) & 6U) != 0) &&
              (pcVar13 = pcVar18->sym->def, pcVar13 != (c2_tuple *)0x0)) &&
             ((pcVar13->op == 0x15a || (pcVar13->op == 0x16a)))) {
            mark_address_taken_operand(pcVar13->src,mask);
          }
          uVar11 = g_alias_class_count;
        }
        if (oa == 0) {
          uVar11 = scopes[iVar25].cls;
        }
        else if (oa_across_calls == 0) {
          pcVar18 = operand_new_memeffect(3);
          tuple_append_src(t,pcVar18);
          tuple_append_dst(t,pcVar18);
          uVar11 = scopes[iVar25].cls;
        }
        else {
          g_alias_class_count = uVar11 + 1;
          call_rec = arena_alloc(4,0x14);
          pcVar10 = call_rec;
          call_rec->next = g_alias_call_records;
          g_alias_call_records = pcVar10;
          call_rec->scope = pcVar16;
          call_rec->cls = uVar11;
          mask = bitset_new(6);
          pcVar18 = t->src;
          call_rec->pointee_nodes = mask;
          for (; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next) {
            if ((((1 << (pcVar18->kind & 0x1f) & 6U) != 0) &&
                (pcVar13 = pcVar18->sym->def, pcVar13 != (c2_tuple *)0x0)) &&
               ((pcVar13->op == 0x15a || (pcVar13->op == 0x16a)))) {
              alias_collect_pointees(pcVar13->src,call_rec,pcVar26);
            }
          }
        }
        pcVar18 = operand_new_memeffect(uVar11);
        tuple_append_src(t,pcVar18);
        tuple_append_dst(t,pcVar18);
        pcVar27 = first;
        goto switchD_1072c610_caseD_a8;
      }
      if (uVar2 != '\x12') {
        if (uVar2 == '\x14') {
          pcVar26 = mask;
          pcVar27 = first;
          switch(t->op) {
          case 0x194:
          case 0x196:
          case 0x198:
            if (g_opt_basic == 0) {
              pcVar19 = arena_alloc(4,0x18);
              alias_collect_symbols_in_range(((t->u20).seh_scope)->begin_tuple,t,1,0,pcVar19);
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(t,pcVar18);
              pcVar19->dst_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar19->next = g_alias_eh_effect_records;
              g_alias_eh_effect_records = pcVar19;
              pcVar19->scope = scopes[depth].scope;
              pcVar26 = mask;
              pcVar27 = first;
            }
            break;
          case 0x195:
            if (g_opt_basic == 0) {
              pcVar13 = ((((t->u20).seh_scope)->handler_label->u32).label_tuple)->next;
              pcVar19 = arena_alloc(4,0x18);
              alias_collect_symbols_in_range(pcVar13,t,1,1,pcVar19);
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(pcVar13,pcVar18);
              pcVar19->next = g_alias_eh_effect_records;
              pcVar16 = scopes[depth].scope;
              pcVar21 = (t->u20).seh_scope;
              pcVar19->src_cls = g_alias_class_count;
              alias = g_alias_class_count + 1;
              uVar11 = pcVar21->flags;
              g_alias_class_count = alias;
              pcVar19->scope = pcVar16;
              if ((uVar11 & 2) != 0) {
                pcVar18 = operand_new_memeffect(alias);
                tuple_append_src(t,pcVar18);
                pcVar19->dst_cls = g_alias_class_count;
                g_alias_class_count = g_alias_class_count + 1;
                pcVar19->scope = pcVar16;
                pcVar19->next = g_alias_eh_effect_records;
              }
              g_alias_eh_effect_records = pcVar19;
              pcVar18 = operand_new_memeffect(scopes[depth].cls);
              tuple_append_src(t,pcVar18);
              pcVar26 = mask;
              pcVar27 = first;
            }
            break;
          default:
switchD_1072c753_caseD_197:
            for (pcVar18 = t->dst; pcVar26 = mask, pcVar27 = first, pcVar18 != (c2_operand *)0x0;
                pcVar18 = pcVar18->next) {
              if (pcVar18->rank == 0) {
                if (((1 << (pcVar18->kind & 0x1f) & 6U) == 0) ||
                   (pcVar18->sym->def == (c2_tuple *)0x0)) {
                  for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                    mark_address_taken_operand(pcVar7,mask);
                  }
                  if (oa != 0) {
                    if (pcVar18->kind == '\x02') {
                      pcVar16 = pcVar18->sym->storage;
                    }
                    else if ((pcVar18->kind != '\x06') ||
                            (pcVar16 = (c2_symbol *)(pcVar18->u18).range,
                            pcVar16 == g_alias_unknown_base)) goto LAB_1072c998;
                    if (pcVar16 != (c2_symbol *)0x0) {
                      for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                        alias_collect_pointees_of_tree_offset
                                  (pcVar16,pcVar7,pcVar26,((pcVar16->u30).alias_info)->points_to);
                      }
                    }
                  }
                }
              }
              else {
                iVar28 = 0;
                refs = g_alias_ref_table + pcVar18->rank;
                if (((t->op == 0x15b) && (pcVar7 = t->src, pcVar7->kind == '\a')) &&
                   ((pcVar7->u18).reg != (c2_symbol *)0x0 || pcVar7->tag != 0)) {
                  iVar28 = 1;
                }
                else {
                  pcVar7 = t->src;
                  if (oa == 0) {
                    for (; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                      iVar14 = alias_collect_pointees_of_tree(pcVar7,mask,refs);
                      if (iVar14 != 0) {
                        iVar28 = 1;
                      }
                    }
                  }
                  else {
                    for (; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                      iVar14 = alias_collect_pointees_of_tree_offset(pcVar18->sym,pcVar7,mask,refs);
                      if (iVar14 != 0) {
                        iVar28 = 1;
                      }
                    }
                  }
                }
                pcVar26 = mask;
                if ((pcVar18->sym->flags6 & 0x10) != 0) {
                  for (pcVar7 = t->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                    mark_address_taken_operand(pcVar7,pcVar26);
                  }
                }
                if (iVar28 != 0) {
                  if (oa == 0) {
                    pcVar17 = symbol_list_add_unique(refs->pointees,g_alias_special_symbol,4);
                    refs->pointees = pcVar17;
                  }
                  pcVar17 = symbol_list_add_unique(refs->pointees,scopes[depth].scope,4);
                  refs->pointees = pcVar17;
                }
              }
LAB_1072c998:
              mask = pcVar26;
            }
            break;
          case 0x1a0:
            eh_object = ((t->u20).eh_construct)->object;
            if (eh_object->funclet != (c2_function *)0x0) {
              if ((g_opt_eh_enabled != 0) || ((eh_object->flags & 0x1000) != 0)) {
                if (eh_object->funclet_syms == (c2_symbol_cell *)0x0) {
                  pcVar12 = arena_alloc(4,0x18);
                  iVar14 = 1;
                  iVar28 = 0;
                  pcVar19 = pcVar12;
                  pcVar13 = eh_funclet_entry_tuple(t);
                  alias_collect_symbols_in_range(pcVar13,(c2_tuple *)0x0,iVar28,iVar14,pcVar19);
                  pcVar23 = ((t->u20).eh_construct)->object;
                  eh_object = pcVar23;
                  for (pcVar5 = pcVar23->parent; pcVar5 != (c2_eh_state *)0x0;
                      pcVar5 = pcVar5->parent) {
                    if (pcVar5->funclet_syms != (c2_symbol_cell *)0x0) {
LAB_1072c7c9:
                      pcVar17 = symbol_list_add_all(pcVar12->read,pcVar5->funclet_syms,1);
                      pcVar12->read = pcVar17;
                      break;
                    }
                    if ((char)pcVar5->flags == '\x04') {
                      pcVar19 = arena_alloc(4,0x18);
                      alias_collect_symbols_in_range
                                (pcVar5->funclet->cfg->first->head,(c2_tuple *)0x0,0,1,pcVar19);
                      pcVar16 = get_cxx_eh_record();
                      pcVar23 = eh_object;
                      if (pcVar16 != (c2_symbol *)0x0) {
                        pcVar17 = symbol_list_add_unique(pcVar19->read,pcVar16->storage,1);
                        pcVar19->read = pcVar17;
                        pcVar23 = eh_object;
                      }
                      pcVar17 = pcVar19->read;
                      pcVar5->funclet_cls = g_alias_class_count;
                      pcVar19->src_cls = g_alias_class_count;
                      g_alias_class_count = g_alias_class_count + 1;
                      pcVar5->funclet_syms = pcVar17;
                      pcVar19->scope = scopes[iVar25].scope;
                      pcVar19->next = g_alias_eh_effect_records;
                      g_alias_eh_effect_records = pcVar19;
                      eh_object = pcVar23;
                    }
                    if (pcVar5->funclet_syms != (c2_symbol_cell *)0x0) goto LAB_1072c7c9;
                  }
                  pcVar16 = get_cxx_eh_record();
                  if (pcVar16 != (c2_symbol *)0x0) {
                    pcVar17 = symbol_list_add_unique(pcVar12->read,pcVar16->storage,1);
                    pcVar12->read = pcVar17;
                  }
                  pcVar23->funclet_syms = pcVar12->read;
                  pcVar23->funclet_cls = g_alias_class_count;
                  pcVar12->src_cls = g_alias_class_count;
                  g_alias_class_count = g_alias_class_count + 1;
                  pcVar12->scope = scopes[iVar25].scope;
                  pcVar12->next = g_alias_eh_effect_records;
                  g_alias_eh_effect_records = pcVar12;
                }
                uVar11 = eh_object->funclet_cls;
                depth = iVar25;
                for (pcVar6 = eh_object->return_branches; pcVar6 != (c2_eh_tuple_cell *)0x0;
                    pcVar6 = pcVar6->next) {
                  pcVar18 = operand_new_memeffect(uVar11);
                  tuple_append_src(pcVar6->tuple,pcVar18);
                }
                iVar25 = depth;
                pcVar26 = mask;
                pcVar27 = first;
                if (g_opt_eh_enabled != 0) break;
              }
              pcVar26 = mask;
              pcVar27 = first;
              if (((byte)((t->u20).eh_construct)->flags & 7) == 4) {
                alias_add_call_memeffects(t,eh_object,scopes[depth].cls,scopes[depth].scope);
                pcVar26 = mask;
                pcVar27 = first;
                return_object_ctor = t;
              }
            }
            break;
          case 0x1a4:
            region_effect = arena_alloc(4,0x18);
            for (pcVar21 = (((t->u20).default_label)->prev->u20).seh_scope;
                pcVar21 != (c2_seh_try_scope *)0x0; pcVar21 = pcVar21->next) {
              if (pcVar21->enclosing_level != 0) {
                pcVar17 = symbol_list_add_unique
                                    (region_effect->written,
                                     *(c2_symbol **)(*(int *)(pcVar21->enclosing_level + 8) + 8),1);
                region_effect->written = pcVar17;
              }
            }
            pcVar26 = mask;
            pcVar27 = first;
            if (region_effect->written != (c2_symbol_cell *)0x0) {
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(t,pcVar18);
              region_effect->dst_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              region_effect->next = g_alias_eh_effect_records;
              g_alias_eh_effect_records = region_effect;
              region_effect->scope = scopes[depth].scope;
              pcVar26 = mask;
              pcVar27 = first;
            }
            break;
          case 0x1a5:
            pcVar8 = (t->u20).eh_try;
            pcVar9 = pcVar8->catch_rec->object;
            if (g_opt_eh_enabled == 0) {
              pcVar19 = arena_alloc(4,0x18);
              pcVar13 = pcVar8->try_block->begin_tuple;
              alias_collect_symbols_in_range
                        (pcVar13,(((pcVar13->u20).eh_try)->try_block->catches->label->u32).
                                 label_tuple,1,0,pcVar19);
              if (pcVar9 != (c2_fe_symbol *)0x0) {
                pcVar17 = symbol_list_add_unique(pcVar19->written,pcVar9->storage_sym->storage,1);
                pcVar19->written = pcVar17;
              }
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(t,pcVar18);
              pcVar19->dst_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar19->scope = scopes[iVar25].scope;
              pcVar19->next = g_alias_eh_effect_records;
              g_alias_eh_effect_records = pcVar19;
              pcVar26 = mask;
              pcVar27 = first;
            }
            else if (pcVar9 != (c2_fe_symbol *)0x0) {
              pcVar18 = operand_new_memeffect((uint)(pcVar9->u3e).alias_class);
              tuple_append_dst(t,pcVar18);
              pcVar26 = mask;
              pcVar27 = first;
            }
            break;
          case 0x1a8:
            if (g_opt_eh_enabled != 0) goto switchD_1072c753_caseD_197;
            alias_add_call_memeffects
                      (t,((t->u20).eh_construct)->object,scopes[depth].cls,scopes[depth].scope);
            pcVar26 = mask;
            pcVar27 = first;
          }
        }
        else {
          if (((t->op != 0x16c) || (g_opt_eh_enabled != 0)) ||
             (g_eh_return_object_record == (c2_eh_state *)0x0)) goto switchD_1072c753_caseD_197;
          alias_add_call_memeffects
                    (t,((return_object_ctor->u20).eh_construct)->object,scopes[depth].cls,
                     scopes[depth].scope);
          pcVar26 = mask;
          pcVar27 = first;
        }
        goto switchD_1072c610_caseD_a8;
      }
      pcVar16 = scopes[iVar25].scope;
      alias_add_pointee(t,oa,pcVar16);
      pcVar26 = mask;
      pcVar27 = first;
      switch((t->u20).intrinsic.id) {
      case 0xa3:
        pcVar18 = memory_effect_for_call_arg(t->src,mask,scopes[iVar25].cls,(int)first);
        tuple_append_src(t,pcVar18);
        uVar11 = compute_alias_points_to_case_ad
                           (t,scopes,iVar25,mask,first,next_scope_cls,list_pass,return_object_ctor,
                            next_tuple,oa,oa_across_calls);
        return uVar11;
      case 0xa4:
      case 0xac:
        uVar11 = scopes[iVar25].cls;
        pcVar18 = memory_effect_for_call_arg(t->src,mask,uVar11,(int)first);
        tuple_append_dst(t,pcVar18);
        pcVar18 = memory_effect_for_call_arg(t->src->next,mask,uVar11,(int)first);
        tuple_append_src(t,pcVar18);
        break;
      case 0xa5:
      case 0xaa:
        uVar11 = scopes[iVar25].cls;
        pcVar18 = memory_effect_for_call_arg(t->src,mask,uVar11,(int)first);
        tuple_append_src(t,pcVar18);
        pcVar18 = memory_effect_for_call_arg(t->src->next,mask,uVar11,(int)first);
        tuple_append_src(t,pcVar18);
        break;
      case 0xa6:
        uVar11 = scopes[iVar25].cls;
        pcVar18 = memory_effect_for_call_arg(t->src,mask,uVar11,(int)first);
        tuple_append_dst(t,pcVar18);
        pcVar18 = memory_effect_for_call_arg(t->src->next,mask,uVar11,(int)first);
        tuple_append_src(t,pcVar18);
        goto LAB_1072c62c;
      case 0xa7:
        uVar11 = scopes[iVar25].cls;
        goto LAB_1072c62c;
      case 0xad:
        pcVar18 = memory_effect_for_call_arg(t->src,mask,scopes[iVar25].cls,(int)first);
        tuple_append_dst(t,pcVar18);
        pcVar26 = mask;
        pcVar27 = first;
        break;
      case 0x11b:
      case 0x11c:
      case 0x11d:
      case 0x13e:
      case 0x13f:
      case 0x14b:
        pcVar18 = operand_new_memeffect(scopes[iVar25].cls);
        tuple_append_src(t,pcVar18);
        tuple_append_dst(t,pcVar18);
        pcVar26 = mask;
        pcVar27 = first;
        break;
      case 0x17a:
        if (g_opt_basic == 0) {
          for (pcVar13 = t->prev; (pcVar13 != (c2_tuple *)0x0 && (pcVar13->op != 0x192));
              pcVar13 = pcVar13->prev) {
          }
          pcVar22 = (t->src->sym->def->src->u18).reg;
          for (pcVar21 = (pcVar13->u20).seh_scope;
              (pcVar26 = mask, pcVar27 = first, pcVar21 != (c2_seh_try_scope *)0x0 &&
              ((int)pcVar22 < pcVar21->level));
              pcVar21 = seh_find_try_record(g_seh_try_records,pcVar21->enclosing_level)) {
            if (pcVar21->kind == 2) {
              pcVar19 = arena_alloc(4,0x18);
              alias_collect_symbols_in_range
                        ((pcVar21->handler_label->u32).label_tuple,
                         (pcVar21->continuation_label->u32).label_tuple,1,1,pcVar19);
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_src(t,pcVar18);
              pcVar19->src_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar18 = operand_new_memeffect(g_alias_class_count);
              tuple_append_dst(t,pcVar18);
              pcVar19->dst_cls = g_alias_class_count;
              g_alias_class_count = g_alias_class_count + 1;
              pcVar19->scope = pcVar16;
              uVar11 = scopes[iVar25].cls;
              pcVar19->next = g_alias_eh_effect_records;
              g_alias_eh_effect_records = pcVar19;
              pcVar18 = operand_new_memeffect(uVar11);
              tuple_append_dst(t,pcVar18);
              tuple_append_src(t,pcVar18);
            }
          }
        }
        break;
      case 0x17d:
        pcVar18 = operand_new_memeffect(scopes[iVar25].cls);
        tuple_append_dst(t,pcVar18);
        pcVar26 = mask;
        pcVar27 = first;
        break;
      case 0x17f:
      case 0x180:
      case 0x184:
        uVar11 = scopes[iVar25].cls;
        goto LAB_1072c62c;
      case 0x181:
        uVar11 = scopes[iVar25].cls;
        pcVar18 = memory_effect_for_call_arg(t->src,mask,uVar11,(int)first);
        tuple_append_dst(t,pcVar18);
LAB_1072c62c:
        pcVar18 = memory_effect_for_call_arg(t->src,mask,uVar11,(int)first);
        tuple_append_src(t,pcVar18);
      }
switchD_1072c610_caseD_a8:
      depth = iVar25;
      mask = pcVar26;
      first = pcVar27;
      for (pcVar18 = t->dst; iVar25 = depth, pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next)
      {
        if (pcVar18->rank != 0) {
          pcVar16 = pcVar18->sym;
          pcVar22 = pcVar16->storage;
          if (pcVar22 != (c2_symbol *)0x0) {
            iVar25 = pcVar16->offset;
            do {
              if ((iVar25 <= pcVar22->offset) &&
                 (pcVar22->size + pcVar22->offset <= pcVar16->size + iVar25)) {
                bitset_andnot(mask,((pcVar22->u30).alias_info)->ref_nodes);
              }
              pcVar22 = pcVar22->part_next;
            } while (pcVar22 != (c2_symbol *)0x0);
          }
          bitset_set(mask,pcVar18->rank);
        }
      }
LAB_1072c9ce:
      bVar24 = t != first->end;
      t = next_tuple;
    } while (bVar24);
    bitset_free(mask);
    (first->avail_in).set = (c2_bitset *)0x0;
    bitset_free(first->de);
    first->de = (c2_bitset *)0x0;
    bitset_free(first->kill);
    first->kill = (c2_bitset *)0x0;
    bitset_free((first->avail_out).set);
    (first->avail_out).set = (c2_bitset *)0x0;
    first = first->next;
    depth = iVar25;
  } while( true );
}

