c1_deferred_parse * __thiscall
class_default_args_parse_init(c1_deferred_parse *rec,c1_symbol *fn,c1_deferred_parse *prev)

{
  c1_type **ppcVar1;
  c1_node *pcVar2;
  c1_type_list *pcVar3;
  c1_scope_stack *stack;
  c1_u8 *rec_00;
  int iVar4;
  c1_decl_state *pcVar5;
  c1_function_params *params;
  
  rec->fn = fn;
  rec->prev = prev;
  rec->set_cc_10 = '\0';
  params = (fn->type->extra).params;
  rec->params = params;
  pcVar2 = params->defaults->link;
  rec->last_default = pcVar2;
  rec->default_arg = pcVar2;
  pcVar3 = rec->params->list;
  ppcVar1 = pcVar3->types + pcVar3->count + -1;
  rec->param_type = ppcVar1;
  if (*ppcVar1 == (c1_type *)0x0) {
    rec->param_type = ppcVar1 + -1;
  }
  iVar4 = 1;
  if (1 < rec->params->default_count) {
    do {
      rec->param_type = rec->param_type + -1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)rec->params->default_count);
  }
  if ((g_compile_flags_cc & 0x10) == 0) {
    rec->set_cc_10 = '\x01';
    g_compile_flags_cc = g_compile_flags_cc | 0x10;
  }
  rec_00 = g_arenas[8].cur;
  stack = g_current_scope;
  g_arenas[8].cur = g_arenas[8].cur + 0x1c;
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (rec_00 == (c1_u8 *)0x0) {
    pcVar5 = (c1_decl_state *)0x0;
  }
  else {
    pcVar5 = decl_state_snapshot((c1_decl_state *)rec_00,stack,stack->saved,'\0');
  }
  stack->saved = pcVar5;
  g_member_function_class = g_scope_vector->entries[(short)rec->fn->scope_index];
  if (g_member_function_class != (c1_symbol *)0x0) {
    scope_enter_class(g_current_scope,g_member_function_class);
  }
  rec->parse_pending = '\0';
  class_default_args_push_next(rec);
  return rec;
}

