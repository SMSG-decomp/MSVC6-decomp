void cxx_eh_lower_state_transitions_part
               (c2_eh_state *state,c2_tuple *branch,int arena,int intrinsic_depth,int in_vec_ctor,
               uint32_t object_moved,c2_tuple *first,c2_tuple *cursor,int saw_1a9,c2_tuple *end,
               int drop_unused_defs,c2_function *fn,c2_cxx_try_block *catch_try)

{
  uint32_t *puVar1;
  c2_cxx_try_block **ppcVar2;
  ushort uVar3;
  uint16_t uVar4;
  c2_eh_tuple_cell *pcVar5;
  c2_operand *pcVar6;
  c2_cxx_catch *pcVar7;
  c2_cxx_try_block *pcVar8;
  c2_fe_symbol *pcVar9;
  c2_eh_tuple_cell *branch_cell;
  c2_tuple *next_t;
  uint uVar10;
  int iVar11;
  c2_tuple *pcVar12;
  uint32_t uVar13;
  c2_cxx_try_block *open_try;
  c2_cxx_try_block *try_walk;
  c2_cxx_catch *catch_rec;
  c2_cxx_catch *catch_walk;
  c2_eh_state *open_state;
  c2_eh_state *object;
  
  next_t = cursor;
code_r0x10755875:
  cursor = next_t;
  if (in_vec_ctor != 0) {
    state = g_eh_return_object_record;
  }
LAB_10755847:
  branch_cell = arena_alloc(arena,8);
  branch_cell->tuple = branch;
  if (state == (c2_eh_state *)0x0) {
    branch_cell->next = g_eh_return_branch_list;
    g_eh_return_branch_list = branch_cell;
    next_t = cursor;
  }
  else {
    pcVar5 = state->return_branches;
    state->return_branches = branch_cell;
    branch_cell->next = pcVar5;
    next_t = cursor;
  }
LAB_10755862:
  cursor = next_t;
  open_try = g_cxx_try_records;
  next_t = cursor;
  if (g_cxx_try_records != (c2_cxx_try_block *)0x0) {
    try_walk = open_try;
    if ((((branch->kind != '\x11') && (pcVar6 = branch->dst, pcVar6 != (c2_operand *)0x0)) &&
        ((arena << (pcVar6->kind & 0x1f) & 6U) != 0)) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
      if ((intrinsic_depth != 0) && (iVar11 = tree_has_unbalanced_intrinsic(branch,0), iVar11 != 0))
      {
        pcVar12 = follow_single_use_chain(branch);
        number_tuples_in_range(first,&pcVar12->next);
        uVar13 = tuple_reads_value_defined_before(pcVar12,branch);
        object_moved = object_moved | uVar13;
      }
      reader_spill_eh_value(branch);
    }
    do {
      for (catch_rec = try_walk->catches; catch_rec != (c2_cxx_catch *)0x0;
          catch_rec = catch_rec->next) {
        tuple_new_branch(0x18b,'\0',(c2_node *)(catch_rec->label->u32).label_tuple,(c2_operand *)0x0
                         ,(c2_tuple *)0x0,tuple_insert_after,branch);
      }
      ppcVar2 = &try_walk->outer;
      try_walk = *ppcVar2;
    } while (*ppcVar2 != (c2_cxx_try_block *)0x0);
    drop_unused_defs = 1;
  }
  do {
    cursor = next_t;
    if (cursor == end) {
      object = g_eh_object_records;
      if (saw_1a9 != 0) {
        next_t = first->next;
        while (pcVar12 = next_t, object = g_eh_object_records, pcVar12 != end) {
          next_t = pcVar12->next;
          if (pcVar12->op == 0x1a9) {
            insert_eh_state_store
                      (*(int32_t *)((int)&pcVar12->src->sym->u34 + 2),
                       ((pcVar12->u20).eh_construct)->object->state,(c2_eh_state *)0x0,pcVar12);
            tuple_unlink_free(pcVar12);
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
      if (drop_unused_defs == 0) {
        return;
      }
      do {
        if (first == (c2_tuple *)0x0) {
          return;
        }
        if (((first->flags & 1) != 0) &&
           (((pcVar6 = first->dst, pcVar6 == (c2_operand *)0x0 ||
             ((1 << (pcVar6->kind & 0x1f) & 6U) == 0)) || (pcVar6->sym->def == (c2_tuple *)0x0)))) {
          if (first->op == 0x16c) {
            if (((1 << (first->src->kind & 0x1f) & 6U) == 0) ||
               (next_t = first->src->sym->def, next_t == (c2_tuple *)0x0)) goto LAB_10788f26;
          }
          else {
            next_t = first;
            if (first->op == 0x185) {
              next_t = first->src->next->sym->def;
            }
          }
          tuple_unlink_first_src_def(next_t);
        }
LAB_10788f26:
        first = first->next;
      } while( true );
    }
    arena = 1;
    next_t = cursor->next;
    uVar3 = cursor->line;
    if (uVar3 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar3;
      g_cur_line = uVar3;
    }
    branch = cursor;
    switch(cursor->op) {
    case 0x16c:
      in_vec_ctor = 0;
      break;
    case 0x184:
      if ((g_opt_eh_enabled != 0) &&
         ((pcVar9 = call_target_function_symbol(cursor), pcVar9 == (c2_fe_symbol *)0x0 ||
          ((pcVar9->attrs & 0x800) == 0)))) goto LAB_10755825;
      break;
    case 0x187:
      cxx_eh_empty_hook(cursor,catch_try,*(c2_tuple **)((int)&cursor->src->sym->u30 + 2));
      break;
    case 0x18c:
      if ((g_opt_eh_enabled == 0) && (open_state = g_eh_current_state, g_opt_global != 0))
      goto joined_r0x10788c37;
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
          in_vec_ctor = 1;
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
        for (pcVar7 = open_try->catches; pcVar7 != (c2_cxx_catch *)0x0; pcVar7 = pcVar7->next) {
          tuple_new_branch(0x18b,'\0',(c2_node *)(pcVar7->label->u32).label_tuple,(c2_operand *)0x0,
                           (c2_tuple *)0x0,tuple_insert_after,cursor);
        }
        pcVar12 = ((open_try->catches->label->u32).label_tuple)->next;
        for (; cursor != pcVar12; cursor = cursor->next) {
          if ((cursor->flags & 1) != 0) {
            for (pcVar6 = cursor->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
              if (((1 << (pcVar6->kind & 0x1f) & 6U) == 0) || (pcVar6->sym->cls != '\x03')) {
                pcVar6->flags11 = pcVar6->flags11 | 8;
              }
            }
          }
        }
      }
      break;
    case 0x1a5:
      if ((g_opt_eh_enabled == 0) &&
         (((cursor->u20).eh_try)->catch_rec == ((cursor->u20).eh_try)->try_block->catches)) {
        pcVar12 = tuple_prev_real(cursor);
        for (catch_walk = open_try->catches; catch_walk != (c2_cxx_catch *)0x0;
            catch_walk = catch_walk->next) {
          tuple_new_branch(0x18b,'\0',(c2_node *)(catch_walk->label->u32).label_tuple,
                           (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,pcVar12);
        }
      }
      catch_try = ((cursor->u20).eh_try)->try_block;
      if (open_try == catch_try) {
        open_try = g_cxx_try_records->outer;
        g_cxx_try_records = open_try;
      }
      cxx_eh_enter_try_state(cursor);
      cxx_eh_empty_hook(cursor,catch_try,(((cursor->u20).eh_try)->catch_rec->label->u32).label_tuple
                       );
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
      saw_1a9 = 1;
      break;
    case 0x1ae:
      if (g_eh_current_state == (c2_eh_state *)0x0) {
        *(undefined4 *)((int)&cursor->src[1].op + 2) = 0xffffffff;
      }
      else {
        *(int32_t *)((int)&cursor->src[1].op + 2) = g_eh_current_state->state;
      }
    }
  } while( true );
joined_r0x10788c37:
  for (; state = g_eh_current_state, open_state != (c2_eh_state *)0x0;
      open_state = open_state->parent) {
    open_state->flags = open_state->flags | 0x1000;
  }
joined_r0x10755836:
  do {
    if (state == (c2_eh_state *)0x0) goto code_r0x10755875;
    if (state->funclet != (c2_function *)0x0) goto code_r0x10755843;
    state = state->parent;
  } while( true );
LAB_10755825:
  state = g_eh_current_state;
  if (g_opt_global != 0) goto joined_r0x10755836;
  goto LAB_10755862;
code_r0x10755843:
  cursor = next_t;
  if (state == (c2_eh_state *)0x0) goto code_r0x10755875;
  goto LAB_10755847;
}

