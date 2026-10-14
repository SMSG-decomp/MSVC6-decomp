void __fastcall seh_lower_try_markers(c2_function *fn)

{
  c2_fe_symbol_u3e *pcVar1;
  c2_seh_try_scope *pcVar2;
  c2_seh_try_scope *pos;
  c2_fe_symbol *pcVar3;
  int32_t outer_level;
  c2_tuple *pcVar4;
  c2_eh_tuple_cell *finally_cell;
  c2_operand *dst;
  int32_t next_level;
  c2_seh_try_scope *info_scope;
  c2_tuple *next_t;
  c2_seh_try_scope *scope;
  c2_tuple *end;
  c2_fe_symbol *branch_label;
  
  pcVar2 = (c2_seh_try_scope *)fn->cfg->last->end;
  scope = pcVar2;
  pos = (c2_seh_try_scope *)fn->cfg->first->head->next;
  while (pos != pcVar2) {
    next_t = (c2_tuple *)pos->next;
    switch((uint8_t)pos->marker_op) {
    case '\x0f':
      pcVar4 = seh_lower_leave_to_state(fn,(c2_tuple *)pos,-1,g_seh_exit_label);
      if (pcVar4 != (c2_tuple *)0x0) {
        dst = operand_new_temp_sym(*(uint16_t *)((int)&pos->marker_op + 2));
        dst->sym->flags7 = dst->sym->flags7 | 2;
        tuple_new(0x15b,*(uint16_t *)((int)&pos->marker_op + 2),dst,(c2_operand *)pos->parent_level,
                  tuple_insert_before,pcVar4);
        tuple_replace_src((c2_tuple *)pos,(c2_operand *)pos->parent_level,dst);
        if (((c2_seh_try_scope *)next_t)->kind == 0x186) {
          next_t = (c2_tuple *)((c2_seh_try_scope *)next_t)->next;
        }
      }
      break;
    case '\x11':
      if ((pos->kind != 0x18c) && (((c2_operand *)pos->parent_level)->next == (c2_operand *)0x0)) {
        branch_label = (c2_fe_symbol *)((c2_operand *)pos->parent_level)->sym;
        seh_lower_leave_to_state
                  (fn,(c2_tuple *)pos,branch_label->storage,(branch_label->u32).label_tuple);
      }
      break;
    case '\x12':
      info_scope = scope;
      if ((((c2_tuple_u20 *)&pos->finally_resume_label)->intrinsic).id == 0xd9) {
        while ((info_scope != (c2_seh_try_scope *)0x0 && ((info_scope->flags & 0xc) == 0))) {
          next_level = (int32_t)info_scope->parent_level;
          if ((int)info_scope->parent_level <
              (int)((c2_tuple_u14 *)&info_scope->enclosing_level)->arg) {
            next_level = (int32_t)((c2_tuple_u14 *)&info_scope->enclosing_level)->arg;
          }
          info_scope = seh_find_try_record(g_seh_try_records,next_level);
        }
        info_scope->info_use = info_scope->info_use | ((info_scope->flags & 8) != 0) + 1;
        info_scope->flags = info_scope->flags | 1;
      }
      break;
    case '\x14':
      switch(pos->kind) {
      case 0x192:
        scope = ((c2_tuple_u20 *)&pos->finally_resume_label)->seh_scope;
        seh_scope_stack_push(scope);
        scope->marker_op = 0x192;
        scope->begin_tuple = (c2_tuple *)pos;
        if (scope->kind == 1) {
          pcVar3 = label_symbol_new();
          scope->filter_label = pcVar3;
          tuple_new_label(pcVar3);
          scope->filter_label->role = 'S';
          (scope->filter_label->u3e).label_flags = (scope->filter_label->u3e).label_flags | 1;
          scope->filter_label->storage = scope->level;
        }
        pcVar3 = label_symbol_new();
        scope->handler_label = pcVar3;
        tuple_new_label(pcVar3);
        scope->handler_label->role = 'S';
        (scope->handler_label->u3e).label_flags = (scope->handler_label->u3e).label_flags | 1;
        scope->handler_label->storage = scope->level;
        pcVar3 = label_symbol_new();
        scope->body_end_label = pcVar3;
        tuple_new_label(pcVar3);
        scope->body_end_label->role = 'S';
        (scope->body_end_label->u3e).label_flags = (scope->body_end_label->u3e).label_flags | 1;
        scope->body_end_label->storage = scope->level;
        if (scope->kind == 2) {
          pcVar3 = label_symbol_new();
          scope->finally_resume_label = pcVar3;
          pcVar3->role = 'S';
          (scope->finally_resume_label->u3e).label_flags =
               (scope->finally_resume_label->u3e).label_flags | 1;
          scope->finally_resume_label->storage = scope->level;
          tuple_new_label(scope->finally_resume_label);
        }
        pcVar3 = label_symbol_new();
        scope->continuation_label = pcVar3;
        tuple_new_label(pcVar3);
        outer_level = scope->enclosing_level;
        if (scope->enclosing_level <= scope->parent_level) {
          outer_level = scope->parent_level;
        }
        scope->continuation_label->storage = outer_level;
        if (scope->kind == 2) {
          scope->continuation_label->role = 'S';
          pcVar1 = &scope->continuation_label->u3e;
          pcVar1->label_flags = pcVar1->label_flags | 1;
        }
        break;
      case 0x193:
        scope = ((c2_tuple_u20 *)&pos->finally_resume_label)->seh_scope;
        if (scope->kind == 2) {
          tuple_insert_before((c2_tuple *)pos,(scope->body_end_label->u32).label_tuple);
          next_t = tuple_new_pseudo(0x195,0x1004);
          tuple_insert_before((c2_tuple *)pos,next_t);
          (next_t->u20).seh_scope = scope;
          pcVar4 = tuple_new_branch(0x189,'\0',
                                    (c2_node *)(scope->continuation_label->u32).label_tuple,
                                    (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,
                                    (c2_tuple *)pos);
          scope->finally_ret = pcVar4;
        }
        else {
          next_t = tuple_new_pseudo(0x197,0x1004);
          tuple_insert_before((c2_tuple *)pos,next_t);
          (next_t->u20).seh_scope = scope;
        }
        tuple_insert_before((c2_tuple *)pos,(scope->continuation_label->u32).label_tuple);
        seh_scope_stack_pop();
        tuple_unlink_free((c2_tuple *)pos);
        scope->flags = scope->flags & 0xfffffff7;
        break;
      case 0x194:
        scope = ((c2_tuple_u20 *)&pos->finally_resume_label)->seh_scope;
        scope->marker_op = 0x194;
        scope->flags = scope->flags | 8;
        pcVar4 = tuple_new_pseudo(0x193,0x1004);
        tuple_insert_before((c2_tuple *)pos,pcVar4);
        (pcVar4->u20).seh_scope = scope;
        if (g_opt_basic == 0) {
          tuple_insert_before((c2_tuple *)pos,(scope->handler_label->u32).label_tuple);
          pcVar4 = (scope->finally_resume_label->u32).label_tuple;
          tuple_insert_after((c2_tuple *)pos,pcVar4);
          pcVar4 = tuple_new_branch(0x188,'\0',(c2_node *)pcVar4,(c2_operand *)0x0,(c2_tuple *)0x0,
                                    tuple_insert_before,(scope->handler_label->u32).label_tuple);
          finally_cell = arena_alloc(1,8);
          finally_cell->tuple = pcVar4;
          scope->finally_calls = finally_cell;
        }
        else {
          tuple_new_branch(0x186,'\0',(c2_node *)g_seh_try_end_label,(c2_operand *)0x0,
                           (c2_tuple *)0x0,tuple_insert_before,(c2_tuple *)pos);
          if (g_opt_global != 0) {
            seh_add_finally_entry_edge(fn,(c2_tuple *)pos);
          }
        }
        break;
      case 0x198:
        scope = ((c2_tuple_u20 *)&pos->finally_resume_label)->seh_scope;
        scope->marker_op = 0x196;
        scope->flags = scope->flags | 4;
        pcVar4 = tuple_new_pseudo(0x193,0x1004);
        tuple_insert_before((c2_tuple *)pos,pcVar4);
        (pcVar4->u20).seh_scope = scope;
        tuple_new_branch(0x186,'\0',(c2_node *)(scope->continuation_label->u32).label_tuple,
                         (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,(c2_tuple *)pos);
        tuple_insert_before((c2_tuple *)pos,(scope->filter_label->u32).label_tuple);
        break;
      case 0x199:
        tuple_insert_before(next_t,(scope->body_end_label->u32).label_tuple);
        pcVar4 = tuple_new_pseudo(0x19a,0x1004);
        tuple_insert_before(next_t,pcVar4);
        (pcVar4->u20).seh_scope = scope;
        tuple_new_branch(0x18b,'\0',(c2_node *)g_seh_exit_label,(c2_operand *)0x0,(c2_tuple *)0x0,
                         tuple_insert_before,next_t);
        tuple_insert_before(next_t,(scope->handler_label->u32).label_tuple);
        pcVar4 = tuple_new_pseudo(0x196,0x1004);
        tuple_insert_before(next_t,pcVar4);
        (pcVar4->u20).seh_scope = scope;
        seh_insert_state_store_17b(scope->nesting,next_t);
        fn->flags = fn->flags | 0x2000;
        scope->flags = scope->flags & 0xfffffffb | 8;
      }
    }
    pos = (c2_seh_try_scope *)next_t;
  }
  return;
}

