int __fastcall inline_expand_calls(c2_function *fn,int depth,int budget,int flag)

{
  byte bVar1;
  byte bVar2;
  uint8_t uVar3;
  ushort uVar4;
  c2_inline_binding *pcVar5;
  c2_cfg *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_function *pcVar9;
  int actual_count;
  c2_list_cell *pcVar10;
  byte *pbVar11;
  c2_fe_symbol *pcVar12;
  c2_tuple *pcVar13;
  uint uVar14;
  c2_function *fn_00;
  c2_inline_binding *bindings;
  c2_fe_symbol *pcVar15;
  char *pcVar16;
  int iVar17;
  uint32_t uVar18;
  c2_symbol *sym;
  c2_operand *pcVar19;
  uint16_t uVar20;
  uint uVar21;
  c2_operand *arg_opnd;
  c2_list_cell *pcVar22;
  c2_tuple *pcVar23;
  c2_symbol *pcVar24;
  bool bVar25;
  c2_tuple *splice_after;
  c2_list_cell *site;
  c2_tuple *callee_entry;
  c2_function *caller;
  c2_operand *result_value;
  c2_symbol *local_20;
  c2_fe_symbol *callee_fe;
  c2_function *local_18;
  int site_count;
  int cur_depth;
  c2_tuple *single_return;
  uint32_t simple_return;
  int budget_at_entry;
  
  budget_at_entry = budget;
  pcVar12 = fn->fsym;
  pcVar12->fn_flags = pcVar12->fn_flags | 0x10;
  if ((flag == 0) && ((pcVar12->attrs & 0x1000) == 0)) {
    actual_count = 0;
  }
  else {
    actual_count = 1;
  }
  caller = fn;
  cur_depth = depth;
  pcVar10 = inline_collect_call_sites(fn,&site_count,actual_count);
  do {
    if (pcVar10 == (c2_list_cell *)0x0) {
      caller->fsym->fn_flags = caller->fsym->fn_flags & 0xffffffef;
      return budget_at_entry - budget;
    }
    pcVar8 = (pcVar10->u04).tuple;
    uVar4 = pcVar8->line;
    if (uVar4 != 0) {
      g_current_line_abs = caller->line_base + (uint)uVar4;
      g_cur_line = uVar4;
    }
    arg_opnd = pcVar8->src;
    if (arg_opnd->kind == '\x04') {
      pcVar12 = (c2_fe_symbol *)arg_opnd->sym;
    }
    else {
      pcVar12 = arg_opnd->sym->storage->fe;
    }
    actual_count = 0;
    for (arg_opnd = arg_opnd->next; arg_opnd != (c2_operand *)0x0; arg_opnd = arg_opnd->next) {
      if ((((1 << (arg_opnd->kind & 0x1f) & 6U) != 0) &&
          (pcVar13 = arg_opnd->sym->def, pcVar13 != (c2_tuple *)0x0)) &&
         ((uVar18 = pcVar13->op, uVar18 == 0x15a || (uVar18 == 0x16a)))) {
        actual_count = actual_count + 1;
      }
    }
    uVar21 = pcVar12->refcount;
    site = pcVar10;
    callee_fe = pcVar12;
    uVar14 = il_type_to_c2_type((byte)pcVar12->storage & 0xf,uVar21);
    simple_return = reader_type_is_simple_scalar(pcVar12->attrs & 0x1c,(uint16_t)uVar14,uVar21);
    pcVar22 = site;
    if (((int)((uint)pcVar10[1].next & 0xff) < cur_depth) ||
       ((((pcVar12->fn_flags & 0x2000) == 0 &&
         (((budget < (short)pcVar12->inline_size && (0x28 < (short)pcVar12->inline_size)) ||
          (35000 < g_inline_total_size)))) ||
        (actual_count != (int)pcVar12->formal_count + simple_return)))) {
      if ((pcVar12->fn_flags & 0x2080) != 0) {
        pcVar15 = pcVar12;
        if ((pcVar12->storage & 0x1000) != 0) {
          pcVar15 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
        }
        pcVar16 = fe_symbol_name(pcVar15,1);
        warning(4,(-(uint)((pcVar12->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar16);
      }
    }
    else {
      if (pcVar8->flags12 == '\0') {
        splice_after = pcVar8->prev;
        pcVar22 = pcVar10;
      }
      else {
        bVar25 = false;
        for (splice_after = pcVar8->prev; splice_after != (c2_tuple *)0x0;
            splice_after = splice_after->prev) {
          if ((splice_after->flags & 1) != 0) {
            if (((splice_after->kind == '\x12') &&
                (((uVar20 = (splice_after->u20).intrinsic.id, uVar20 == 0xdf || (uVar20 == 0x184))
                 || (uVar20 == 0xde)))) || (splice_after->op == 0x1aa)) {
              if ((pcVar12->fn_flags & 0x2080) != 0) {
                pcVar15 = pcVar12;
                if ((pcVar12->storage & 0x1000) != 0) {
                  pcVar15 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
                }
                pcVar16 = fe_symbol_name(pcVar15,1);
                warning(4,(-(uint)((pcVar12->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar16);
              }
              goto LAB_1072d73b;
            }
            arg_opnd = splice_after->dst;
            if (splice_after->flags12 == '\0') {
              if (((arg_opnd == (c2_operand *)0x0) || ((1 << (arg_opnd->kind & 0x1f) & 6U) == 0)) ||
                 (arg_opnd->sym->def == (c2_tuple *)0x0)) {
                if (splice_after != (c2_tuple *)0x0) goto LAB_1072d40a;
                break;
              }
            }
            else if ((arg_opnd != (c2_operand *)0x0) &&
                    (((1 << (arg_opnd->kind & 0x1f) & 6U) == 0 ||
                     (arg_opnd->sym->def == (c2_tuple *)0x0)))) {
              bVar25 = true;
            }
          }
        }
        splice_after = caller->cfg->first->head;
LAB_1072d40a:
        pcVar8 = splice_after->next;
        bVar1 = pcVar8->flags;
        while ((bVar1 & 1) == 0) {
          pcVar8 = pcVar8->next;
          bVar1 = pcVar8->flags;
        }
        splice_after = pcVar8->prev;
        if (bVar25) {
          splice_after = inline_unlink_first_unlinked_def(splice_after,(site->u04).tuple);
        }
      }
      uVar21 = pcVar12->fn_flags & 0x2000;
      if ((uVar21 == 0) && (0x28 < (short)pcVar12->inline_size)) {
        budget = budget - (short)pcVar12->inline_size;
      }
      if (uVar21 == 0) {
        g_inline_total_size = g_inline_total_size + (short)pcVar12->inline_size;
      }
      if ((pcVar12->fn_flags & 0x2080) == 0) {
        pcVar15 = pcVar12;
        if ((pcVar12->storage & 0x1000) != 0) {
          pcVar15 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
        }
        pcVar16 = fe_symbol_name(pcVar15,1);
        warning(4,0x2c7,pcVar16);
      }
      fn_00 = read_function_il(pcVar12);
      uVar4 = ((pcVar22->u04).tuple)->line;
      if (uVar4 != 0) {
        g_current_line_abs = caller->line_base + (uint)uVar4;
        g_cur_line = uVar4;
      }
      local_18 = fn_00;
      if (((g_opt_global != 0) || (pcVar12->fn_flags != 0)) || ((fn_00->options & 0x200000) == 0)) {
        for (callee_entry = fn_00->cfg->first->head;
            (callee_entry != (c2_tuple *)0x0 && (callee_entry->kind != '\x17'));
            callee_entry = callee_entry->next) {
        }
        if ((fn_00->flags & 0x18000) != 0) {
          arg_opnd = callee_entry->src;
          local_20 = (c2_symbol *)0x0;
          do {
            if (arg_opnd != (c2_operand *)0x0) {
              pcVar16 = "___$ReturnUdt";
              pbVar11 = (byte *)arg_opnd->sym->fe->name;
              do {
                bVar1 = *pbVar11;
                bVar25 = bVar1 < (byte)*pcVar16;
                if (bVar1 != *pcVar16) {
LAB_1072d4a0:
                  actual_count = (1 - (uint)bVar25) - (uint)(bVar25 != 0);
                  goto LAB_1072d4a5;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar11[1];
                bVar25 = bVar1 < (byte)pcVar16[1];
                if (bVar1 != pcVar16[1]) goto LAB_1072d4a0;
                pbVar11 = pbVar11 + 2;
                pcVar16 = pcVar16 + 2;
              } while (bVar1 != 0);
              actual_count = 0;
LAB_1072d4a5:
              if (actual_count == 0) {
                if ((pcVar12->fn_flags & 0x2080) != 0) {
                  pcVar15 = pcVar12;
                  if ((pcVar12->storage & 0x1000) != 0) {
                    pcVar15 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
                  }
                  pcVar16 = fe_symbol_name(pcVar15,1);
                  warning(4,(-(uint)((pcVar12->fn_flags & 0x2000) != 0) & 4) + 0x2c6,pcVar16);
                }
                inline_free_callee_body(fn_00);
                if ((int)local_20 < 2) goto LAB_1072d73b;
                break;
              }
              arg_opnd = arg_opnd->next;
            }
            local_20 = (c2_symbol *)((int)&local_20->fe + 1);
          } while ((int)local_20 < 2);
        }
        pcVar8 = callee_entry;
        if ((((fn_00->flags & 1) == 0) || (g_opt_global == 0)) ||
           (actual_count = inline_asm_has_external_jumps(fn_00), actual_count == 0)) {
          uVar21 = fn_00->flags & 0x10000;
          if ((uVar21 != 0) || ((fn_00->fsym->fn_flags & 0x400) != 0)) {
            if ((g_opt_global != 0) && ((uVar21 != 0 && ((pcVar12->fn_flags & 0x2000) == 0)))) {
              if ((pcVar12->fn_flags & 0x80) != 0) {
                if ((pcVar12->storage & 0x1000) != 0) {
                  pcVar12 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
                }
                pcVar16 = fe_symbol_name(pcVar12,1);
                actual_count = 0x2c6;
                goto LAB_10793cdc;
              }
              goto LAB_10793c63;
            }
            cxx_eh_begin_function(fn_00,1);
            cxx_eh_lower_scopes(fn_00);
            cxx_eh_merge_adjacent_try_blocks(fn_00);
          }
          actual_count = inline_bind_address_actuals(fn_00,pcVar8,(site->u04).tuple);
          if ((0 < actual_count) &&
             (actual_count = inline_unbind_written_formals(pcVar8,actual_count), 0 < actual_count))
          {
            inline_propagate_address_formals(pcVar8);
          }
          if ((flag == 0) && ((caller->fsym->attrs & 0x1000) == 0)) {
            actual_count = 0;
          }
          else {
            actual_count = 1;
          }
          actual_count = inline_expand_calls(fn_00,cur_depth + 1,budget / site_count,actual_count);
          if (g_opt_favor_speed == 0) {
            if ((pcVar12->fn_flags & 0x2000) == 0) {
              iVar17 = inline_callee_too_large(fn_00,(site->u04).tuple,pcVar8);
              if (iVar17 != 0) {
                inline_free_callee_body(fn_00);
                goto LAB_1072d73b;
              }
              goto LAB_1072d97f;
            }
          }
          else {
LAB_1072d97f:
            if ((pcVar12->fn_flags & 0x2000) == 0) {
              budget = budget - actual_count;
              g_inline_total_size = g_inline_total_size + actual_count;
            }
          }
          pcVar9 = caller;
          uVar4 = ((site->u04).tuple)->line;
          if (uVar4 != 0) {
            g_current_line_abs = caller->line_base + (uint)uVar4;
            g_cur_line = uVar4;
          }
          inline_rehash_scope(caller->scope,&fn_00->scope->parent);
          if ((pcVar9->fsym->fn_flags & 0x300) != 0) {
            inline_find_pending_copy_marker((site->u04).tuple);
          }
          bindings = inline_bind_actual_arguments(fn_00,pcVar8,(site->u04).tuple);
          actual_count = inline_invalidate_written_args(pcVar8,bindings,&single_return);
          for (pcVar5 = bindings; pcVar5 != (c2_inline_binding *)0x0; pcVar5 = pcVar5->next) {
            if (pcVar5->value != (c2_operand *)0x0) {
              inline_substitute_formals(fn_00->cfg->first->head);
              break;
            }
          }
          pcVar10 = site;
          splice_after = inline_bind_formal_parameters
                                   ((site->u04).tuple,bindings,splice_after,fn_00->cfg->last->end);
          pcVar24 = (c2_symbol *)0x0;
          pcVar8 = (pcVar10->u04).tuple;
          result_value = (c2_operand *)0x0;
          local_20 = (c2_symbol *)0x0;
          if (pcVar8->dst != (c2_operand *)0x0) {
            if (((actual_count == 1) && ((fn_00->flags & 1) == 0)) &&
               (actual_count = inline_actual_is_stable(single_return,&splice_after->next,pcVar8),
               actual_count != 0)) {
              arg_opnd = single_return->src;
              if (((1 << (arg_opnd->kind & 0x1f) & 6U) == 0) ||
                 (arg_opnd->sym->def == (c2_tuple *)0x0)) {
                result_value = (c2_operand *)node_clone((c2_node *)arg_opnd);
                fn_00 = local_18;
              }
              else {
                bVar1 = arg_opnd->flags;
                single_return->src = (c2_operand *)0x0;
                arg_opnd->flags = bVar1 & 0xef;
                fn_00 = local_18;
                result_value = arg_opnd;
              }
            }
            else {
              pcVar24 = inline_fold_result_copy(pcVar8,&splice_after,callee_entry);
              local_20 = pcVar24;
              if (pcVar24 == (c2_symbol *)0x0) {
                if (simple_return == 0) {
                  if (((byte)callee_fe->storage & 0xf) == 7) {
                    uVar4 = pcVar8->dst->type;
                    uVar21 = (uint)uVar4;
                    uVar18 = type_class_to_symbol_class(uVar4);
                    uVar20 = (uint16_t)uVar18;
                  }
                  else {
                    uVar20 = (byte)callee_fe->storage & 0xf;
                    uVar21 = il_type_to_c2_type(uVar20,callee_fe->refcount);
                  }
                }
                else {
                  uVar20 = 3;
                  uVar21 = (uint)pcVar8->dst->type;
                }
                pcVar12 = fe_symbol_new_local_cur(uVar20,uVar21 & 0xfff,1,1,'\x04',0);
                pcVar24 = fe_symbol_get_storage(pcVar12);
                local_20 = pcVar24;
              }
            }
          }
          pcVar9 = caller;
          inline_rewrite_returns(fn_00,caller,pcVar24,pcVar8);
          uVar21 = pcVar9->flags;
          uVar14 = fn_00->flags;
          uVar21 = ((uVar21 | uVar14) ^ uVar21) & 1 ^ uVar21;
          uVar21 = ((uVar21 | uVar14) ^ uVar21) & 8 ^ uVar21;
          uVar21 = ((uVar21 | uVar14) ^ uVar21) & 0x40 ^ uVar21;
          uVar21 = ((uVar21 | uVar14) ^ uVar21) & 0x80 ^ uVar21;
          pcVar9->flags = ((uVar21 | uVar14) ^ uVar21) & 0x8000 ^ uVar21;
          uVar21 = fn_00->options;
          if ((uVar21 & 0x40000) != 0) {
            g_opt_float_consistency = 1;
          }
          if (g_opt_assume_no_alias != 0) {
            if (g_opt_assume_no_alias_across_calls == 0) {
              if ((uVar21 & 0x2000000) == 0) {
                g_opt_assume_no_alias = 0;
              }
            }
            else if ((uVar21 & 0x1000000) == 0) {
              g_opt_assume_no_alias = 0;
              g_opt_assume_no_alias_across_calls = 0;
              g_assume_no_alias_across_calls = 1;
            }
          }
          arg_opnd = pcVar8->dst;
          if (arg_opnd != (c2_operand *)0x0) {
            if (local_20 != (c2_symbol *)0x0) {
              result_value = operand_new_sym(0x14a,arg_opnd->type,local_20);
            }
            pcVar19 = result_value;
            if ((((1 << (arg_opnd->kind & 0x1f) & 6U) == 0) ||
                (arg_opnd->sym->def == (c2_tuple *)0x0)) ||
               (actual_count = inline_formal_substitutable(pcVar8,result_value), actual_count == 0))
            {
              bVar1 = pcVar19->kind;
              bVar2 = arg_opnd->flags;
              pcVar8->dst = (c2_operand *)0x0;
              arg_opnd->flags = bVar2 & 0xef;
              if (((((1 << (bVar1 & 0x1f) & 6U) == 0) ||
                   (pcVar13 = pcVar19->sym->def, pcVar13 == (c2_tuple *)0x0)) ||
                  ((1 << (arg_opnd->kind & 0x1f) & 6U) == 0)) ||
                 (pcVar24 = arg_opnd->sym, pcVar24->def == (c2_tuple *)0x0)) {
                pcVar13 = tuple_new(0x15b,arg_opnd->type,arg_opnd,pcVar19,tuple_insert_after,pcVar8)
                ;
              }
              else {
                uVar4 = pcVar13->dst->type;
                pcVar19 = arg_opnd;
                if (uVar4 != arg_opnd->type) {
                  sym = symbol_get_part(pcVar24,uVar4,uVar4 & 0xfff,0);
                  pcVar19 = operand_new_reg(0x149,uVar4,sym,pcVar24);
                  node_free((c2_node *)arg_opnd);
                }
                tuple_replace_dst(pcVar13,pcVar13->dst,pcVar19);
                tuple_unlink(pcVar13);
                tuple_insert_after(pcVar8,pcVar13);
                arg_opnd = pcVar19;
              }
              uVar3 = pcVar8->flags12;
              pcVar13->line = pcVar8->line;
              bVar1 = arg_opnd->kind;
              pcVar13->flags12 = uVar3;
              if (((1 << (bVar1 & 0x1f) & 6U) != 0) && (arg_opnd->sym->def != (c2_tuple *)0x0)) {
                symbol_mark_overlapping_parts(arg_opnd->sym,pcVar13);
              }
              if (((1 << (result_value->kind & 0x1f) & 6U) != 0) &&
                 (result_value->sym->def != (c2_tuple *)0x0)) {
                hoist_defining_tuples(pcVar13,pcVar13->flags12);
              }
              if (local_20 != (c2_symbol *)0x0) goto LAB_1072d6d5;
            }
            else {
              pcVar13 = inline_substitute_formal_use(pcVar8,pcVar19);
            }
            inline_drop_scope_end_marker(callee_entry,pcVar13);
          }
LAB_1072d6d5:
          pcVar6 = local_18->cfg;
          pcVar13 = pcVar6->first->head;
          tuple_splice_after(splice_after,pcVar13);
          pcVar23 = callee_entry->next;
          while (pcVar13 != pcVar23) {
            pcVar7 = pcVar13->next;
            tuple_unlink_free(pcVar13);
            pcVar13 = pcVar7;
          }
          pcVar13 = pcVar6->last->end;
          while (pcVar13 != (c2_tuple *)0x0) {
            if (pcVar13->kind == '\x18') {
              pcVar23 = (c2_tuple *)0x0;
            }
            else {
              pcVar23 = pcVar13->prev;
            }
            tuple_unlink_free(pcVar13);
            pcVar13 = pcVar23;
          }
          tuple_unlink_free(pcVar8);
          pcVar12 = callee_fe;
          if (g_opt_incremental != 0) {
            incremental_note_callee(callee_fe->id);
            pcVar12->fn_flags = pcVar12->fn_flags | 0x1000;
          }
          goto LAB_1072d73b;
        }
        if ((pcVar12->fn_flags & 0x2080) != 0) {
          pcVar15 = pcVar12;
          if ((pcVar12->storage & 0x1000) != 0) {
            pcVar15 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)pcVar12);
          }
          pcVar16 = fe_symbol_name(pcVar15,1);
          actual_count = (-(uint)((pcVar12->fn_flags & 0x2000) != 0) & 4) + 0x2c6;
LAB_10793cdc:
          warning(4,actual_count,pcVar16);
        }
      }
LAB_10793c63:
      inline_free_callee_body(fn_00);
    }
LAB_1072d73b:
    pcVar10 = site->next;
    site_count = site_count + -1;
  } while( true );
}

