void __thiscall scope_new_block_record(c1_scope_stack *stack,c1_sym_list *params)

{
  c1xx_scope *scope;
  
  scope = (c1xx_scope *)g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x18;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  if (scope == (c1xx_scope *)0x0) {
    scope = (c1xx_scope *)0x0;
  }
  else {
    *(c1_u8 *)((int)scope + 4) = '\0';
    *(c1_u8 *)((int)scope + 5) = '\0';
    *(c1_u8 *)((int)scope + 6) = '\0';
    *(c1_u8 *)((int)scope + 7) = '\0';
    *(c1_u8 *)((int)scope + 8) = '\x01';
    *(c1_u8 *)((int)scope + 0xc) = '\0';
    *(c1_u8 *)((int)scope + 0xd) = '\0';
    *(c1_u8 *)((int)scope + 0xe) = '\0';
    *(c1_u8 *)((int)scope + 0xf) = '\0';
    *(c1_u8 *)((int)scope + 0x10) = '\0';
    *(c1_u8 *)((int)scope + 0x11) = '\0';
    *(c1_u8 *)((int)scope + 0x12) = '\0';
    *(c1_u8 *)((int)scope + 0x13) = '\0';
    *(c1_sym_list **)((int)scope + 0x14) = params;
    *(undefined ***)scope = &PTR_block_scope_has_entries_104bcac0;
  }
  if (params != (c1_sym_list *)0x0) {
    g_function_parameter_scope = params;
  }
  scope_push_child(stack,scope);
  return;
}

