c1_arg_item * __cdecl
tmpl_evaluate_default_argument
          (c1_symbol *tmpl,c1_sym_list *params,c1_arg_list *args,c1_node *saved_default,
          int known_count)

{
  c1_arg_item *pcVar1;
  c1_scope_stack *stack;
  c1_u8 *rec;
  c1_decl_state *pcVar2;
  c1xx_scope *scope;
  c1_arg_list *parsed_args;
  
  rec = g_arenas[8].cur;
  stack = g_current_scope;
  g_arenas[8].cur = g_arenas[8].cur + 0x1c;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (rec == (c1_u8 *)0x0) {
    pcVar2 = (c1_decl_state *)0x0;
  }
  else {
    pcVar2 = decl_state_snapshot((c1_decl_state *)rec,stack,stack->saved,'\0');
  }
  stack->saved = pcVar2;
  if (tmpl->scope_index != 0) {
    scope_enter_symbol_scope(g_scope_vector->entries[(short)tmpl->scope_index]);
  }
  if (args != (c1_arg_list *)0x0) {
    scope = (c1xx_scope *)tmpl_bind_arguments(params,args,tmpl,'\0','\x01',known_count);
    scope_push_child(g_current_scope,scope);
  }
  parsed_args = parse_reparse_template_arguments(saved_default->left);
  if (parsed_args == (c1_arg_list *)0x0) {
    return (c1_arg_item *)0x0;
  }
  pcVar1 = parsed_args->first;
  decl_state_restore(g_current_scope,'\0');
  decl_state_pop(g_current_scope);
  return pcVar1;
}

