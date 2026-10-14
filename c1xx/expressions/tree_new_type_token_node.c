void __cdecl tree_new_type_token_node(c1xx_token *token,c1_type *type)

{
  c1_node *pcVar1;
  c1_arena *a;
  c1_node *node;
  
  if ((g_compile_flags_c4 & 0x8000000) != 0) {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  a = g_arenas + g_expr_arena_index;
  node = (c1_node *)a->cur;
  pcVar1 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &node[1].op;
  if (pcVar1 < node + 1) {
    arena_grow(a);
  }
  node->kind = '\0';
  node->type = type;
  node->op = 0x98;
  node->left = token->type_symbol;
  token->code = 0x98;
  token->value = node;
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return;
}

