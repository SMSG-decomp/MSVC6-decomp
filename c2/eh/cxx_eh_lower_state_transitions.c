void __fastcall cxx_eh_lower_state_transitions(c2_function *fn)

{
  uint32_t *puVar1;
  c2_cxx_try_block **ppcVar2;
  ushort uVar3;
  uint16_t uVar4;
  c2_tuple *first;
  c2_eh_tuple_cell *pcVar5;
  c2_cxx_catch *pcVar6;
  c2_operand *pcVar7;
  c2_cxx_try_block *pcVar8;
  c2_fe_symbol *pcVar9;
  c2_eh_tuple_cell *branch_cell;
  c2_tuple *next_t;
  uint uVar10;
  int iVar11;
  uint32_t uVar12;
  c2_tuple *pcVar13;
  c2_tuple *end;
  c2_cxx_try_block *open_try;
  c2_cxx_try_block *try_walk;
  c2_eh_state *state;
  int intrinsic_depth;
  uint object_moved;
  c2_tuple *cursor;
  c2_cxx_try_block *catch_try;
  c2_cxx_catch *catch_rec;
  c2_cxx_catch *catch_walk;
  c2_eh_state *object;
  c2_eh_state *open_state;
  bool drop_unused_defs;
  bool return_object_open;
  bool saw_1a9;
  
  return_object_open = false;
  intrinsic_depth = 0;
  object_moved = 0;
  drop_unused_defs = false;
  saw_1a9 = false;
  cxx_eh_create_funcinfo();
  g_cxx_try_records = (c2_cxx_try_block *)0x0;
  g_eh_return_branch_list = (void *)0x0;
  first = fn->cfg->first->head;
  end = fn->cfg->last->end;
  cursor = first->next;
  open_try = catch_try;
  object = g_eh_object_records;
  if (cursor != end) {
    do {
      next_t = cursor->next;
      uVar3 = cursor->line;
      if (uVar3 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar3;
        g_cur_line = uVar3;
      }
      switch(cursor->op) {
      case 0x16c:
        return_object_open = false;
        break;
      case 0x184:
        if ((g_opt_eh_enabled != 0) &&
           ((pcVar9 = call_target_function_symbol(cursor), pcVar9 == (c2_fe_symbol *)0x0 ||
            ((pcVar9->attrs & 0x800) == 0)))) {
          state = g_eh_current_state;
          if (g_opt_global != 0) goto joined_r0x10755836;
LAB_10755862:
          open_try = g_cxx_try_records;
          if (g_cxx_try_records != (c2_cxx_try_block *)0x0) {
            try_walk = open_try;
            if ((((cursor->kind != '\x11') && (pcVar7 = cursor->dst, pcVar7 != (c2_operand *)0x0))
                && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) &&
               (pcVar7->sym->def != (c2_tuple *)0x0)) {
              if ((intrinsic_depth != 0) &&
                 (iVar11 = tree_has_unbalanced_intrinsic(cursor,0), iVar11 != 0)) {
                pcVar13 = follow_single_use_chain(cursor);
                number_tuples_in_range(first,&pcVar13->next);
                uVar12 = tuple_reads_value_defined_before(pcVar13,cursor);
                object_moved = object_moved | uVar12;
              }
              reader_spill_eh_value(cursor);
            }
            do {
              for (catch_rec = try_walk->catches; catch_rec != (c2_cxx_catch *)0x0;
                  catch_rec = catch_rec->next) {
                tuple_new_branch(0x18b,'\0',(c2_node *)(catch_rec->label->u32).label_tuple,
                                 (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after,cursor);
              }
              ppcVar2 = &try_walk->outer;
              try_walk = *ppcVar2;
            } while (*ppcVar2 != (c2_cxx_try_block *)0x0);
            drop_unused_defs = true;
          }
        }
        break;
      case 0x187:
        cxx_eh_empty_hook(cursor,catch_try,*(c2_tuple **)((int)&cursor->src->sym->u30 + 2));
        break;
      case 0x18c:
        if ((g_opt_eh_enabled == 0) && (open_state = g_eh_current_state, g_opt_global != 0)) {
          for (; state = g_eh_current_state, open_state != (c2_eh_state *)0x0;
              open_state = open_state->parent) {
            open_state->flags = open_state->flags | 0x1000;
          }
joined_r0x10755836:
          for (; state != (c2_eh_state *)0x0; state = state->parent) {
            if (state->funclet != (c2_function *)0x0) {
              if (state != (c2_eh_state *)0x0) goto LAB_10755847;
              break;
            }
          }
          if (return_object_open) {
            state = g_eh_return_object_record;
          }
LAB_10755847:
          branch_cell = arena_alloc(1,8);
          branch_cell->tuple = cursor;
          if (state == (c2_eh_state *)0x0) {
            branch_cell->next = g_eh_return_branch_list;
            g_eh_return_branch_list = branch_cell;
          }
          else {
            pcVar5 = state->return_branches;
            state->return_branches = branch_cell;
            branch_cell->next = pcVar5;
          }
          goto LAB_10755862;
        }
        break;
      case 400:
        uVar4 = (cursor->u20).intrinsic.id;
        if (uVar4 == 0xde) {
          intrinsic_depth = intrinsic_depth + 1;
        }
        else if (uVar4 == 0xdf) {
          intrinsic_depth = intrinsic_depth + -1;
        }
        break;
      case 0x1a0:
        if (cursor->src != (c2_operand *)0x0) {
          if ((char)((cursor->u20).eh_construct)->object->flags == '\x04') {
            return_object_open = true;
          }
          cxx_eh_lower_object_construction(cursor);
        }
        break;
      case 0x1a1:
        cxx_eh_lower_object_destruction(cursor);
        break;
      case 0x1a2:
        next_t = cxx_eh_lower_try_end(cursor);
        break;
      case 0x1a3:
        g_eh_current_state = ((cursor->u20).eh_construct)->object;
        tuple_unlink_free(cursor);
        break;
      case 0x1a4:
        open_try = ((cursor->u20).eh_try)->try_block;
        pcVar8 = open_try;
        open_try->outer = g_cxx_try_records;
        g_cxx_try_records = pcVar8;
        cxx_eh_enter_object_state(cursor);
        if (g_opt_eh_enabled == 0) {
          for (pcVar6 = open_try->catches; pcVar6 != (c2_cxx_catch *)0x0; pcVar6 = pcVar6->next) {
            tuple_new_branch(0x18b,'\0',(c2_node *)(pcVar6->label->u32).label_tuple,
                             (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_after,cursor);
          }
          pcVar13 = ((open_try->catches->label->u32).label_tuple)->next;
          for (; cursor != pcVar13; cursor = cursor->next) {
            if ((cursor->flags & 1) != 0) {
              for (pcVar7 = cursor->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                if (((1 << (pcVar7->kind & 0x1f) & 6U) == 0) || (pcVar7->sym->cls != '\x03')) {
                  pcVar7->flags11 = pcVar7->flags11 | 8;
                }
              }
            }
          }
        }
        break;
      case 0x1a5:
        if ((g_opt_eh_enabled == 0) &&
           (((cursor->u20).eh_try)->catch_rec == ((cursor->u20).eh_try)->try_block->catches)) {
          pcVar13 = tuple_prev_real(cursor);
          for (catch_walk = open_try->catches; catch_walk != (c2_cxx_catch *)0x0;
              catch_walk = catch_walk->next) {
            tuple_new_branch(0x18b,'\0',(c2_node *)(catch_walk->label->u32).label_tuple,
                             (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,pcVar13);
          }
        }
        catch_try = ((cursor->u20).eh_try)->try_block;
        if (open_try == catch_try) {
          open_try = g_cxx_try_records->outer;
          g_cxx_try_records = open_try;
        }
        cxx_eh_enter_try_state(cursor);
        cxx_eh_empty_hook(cursor,catch_try,
                          (((cursor->u20).eh_try)->catch_rec->label->u32).label_tuple);
        break;
      case 0x1a6:
        cxx_eh_leave_object_state(cursor);
        break;
      case 0x1a8:
        if (((cursor->u20).eh_state_store)->sets_walk_state != 0) {
          g_eh_current_state = ((cursor->u20).eh_state_store)->new_state;
        }
        break;
      case 0x1a9:
        saw_1a9 = true;
        break;
      case 0x1ae:
        if (g_eh_current_state == (c2_eh_state *)0x0) {
          *(undefined4 *)((int)&cursor->src[1].op + 2) = 0xffffffff;
        }
        else {
          *(int32_t *)((int)&cursor->src[1].op + 2) = g_eh_current_state->state;
        }
      }
      cursor = next_t;
    } while (cursor != end);
    object = g_eh_object_records;
    if (saw_1a9) {
      next_t = first->next;
      while (pcVar13 = next_t, object = g_eh_object_records, pcVar13 != end) {
        next_t = pcVar13->next;
        if (pcVar13->op == 0x1a9) {
          insert_eh_state_store
                    (*(int32_t *)((int)&pcVar13->src->sym->u34 + 2),
                     ((pcVar13->u20).eh_construct)->object->state,(c2_eh_state *)0x0,pcVar13);
          tuple_unlink_free(pcVar13);
        }
      }
    }
  }
  for (; object != (c2_eh_state *)0x0; object = object->next) {
    uVar10 = object->flags & 0xff;
    if (((uVar10 != 6) && (uVar10 != 7)) && (object->funclet != (c2_function *)0x0)) {
      puVar1 = &object->funclet->flags;
      *puVar1 = *puVar1 & 0xffffbfff;
    }
  }
  g_eh_object_move_pending = g_eh_object_move_pending | object_moved;
  if (drop_unused_defs) {
    for (; first != (c2_tuple *)0x0; first = first->next) {
      if (((first->flags & 1) != 0) &&
         (((pcVar7 = first->dst, pcVar7 == (c2_operand *)0x0 ||
           ((1 << (pcVar7->kind & 0x1f) & 6U) == 0)) || (pcVar7->sym->def == (c2_tuple *)0x0)))) {
        if (first->op == 0x16c) {
          if (((1 << (first->src->kind & 0x1f) & 6U) == 0) ||
             (end = first->src->sym->def, end == (c2_tuple *)0x0)) goto LAB_10788f26;
        }
        else {
          end = first;
          if (first->op == 0x185) {
            end = first->src->next->sym->def;
          }
        }
        tuple_unlink_first_src_def(end);
      }
LAB_10788f26:
    }
  }
  return;
}

