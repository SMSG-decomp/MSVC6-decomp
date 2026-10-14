void __fastcall seh_collect_try_scopes(c2_function *fn)

{
  c2_tuple *t;
  c2_seh_try_scope *scope;
  int32_t label_level;
  c2_fe_symbol *label_sym;
  c2_tuple *next_t;
  c2_tuple *local_8;
  c2_tuple *exit_tuple;
  c2_tuple *end;
  
  local_8 = (c2_tuple *)0x0;
  end = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  while (t != end) {
    next_t = t->next;
    switch(t->kind) {
    case '\x11':
      if ((t->src->sym->u30).globopt.live == 'G') {
        next_t = seh_move_finally_block(t,&local_8);
      }
      break;
    case '\x14':
      switch(t->op) {
      case 0x192:
        scope = seh_new_try_record();
        (t->u20).seh_scope = scope;
        break;
      case 0x193:
        scope = seh_current_scope_record();
        (t->u20).seh_scope = scope;
        seh_scope_stack_pop();
        if (((t->u20).cond_cells)->op == 2) {
          g_seh_except_nesting = g_seh_except_nesting + -1;
        }
        break;
      case 0x194:
        scope = seh_current_scope_record();
        (t->u20).seh_scope = scope;
        scope->kind = 2;
        g_seh_except_nesting = g_seh_except_nesting + 1;
        break;
      case 0x198:
        scope = seh_current_scope_record();
        (t->u20).seh_scope = scope;
        scope->kind = 1;
        break;
      case 0x199:
        scope = seh_current_scope_record();
        (t->u20).seh_scope = scope;
      }
      break;
    case '\x18':
      exit_tuple = t;
      break;
    case '\x1a':
      scope = seh_current_scope_record();
      if (scope == (c2_seh_try_scope *)0x0) {
        label_level = -1;
      }
      else {
        label_level = scope->level;
      }
      *(int32_t *)((int)&t->src[1].op + 2) = label_level;
    }
    t = next_t;
  }
  label_sym = label_symbol_new();
  g_seh_exit_label = tuple_new_label(label_sym);
  tuple_insert_before(exit_tuple,g_seh_exit_label);
  return;
}

