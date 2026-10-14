c1xx_block_scope * __thiscall tmpl_binding_scope_new(c1_scope_stack *stack,c1_sym_list *symbols)

{
  c1_u8 *scope;
  
  scope = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x18;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (scope != (c1_u8 *)0x0) {
    scope[4] = '\0';
    scope[5] = '\0';
    scope[6] = '\0';
    scope[7] = '\0';
    scope[0xc] = '\0';
    scope[0xd] = '\0';
    scope[0xe] = '\0';
    scope[0xf] = '\0';
    scope[0x10] = '\0';
    scope[0x11] = '\0';
    scope[0x12] = '\0';
    scope[0x13] = '\0';
    scope[8] = 0xfa;
    *(c1_sym_list **)(scope + 0x14) = symbols;
    *(undefined ***)scope = &PTR_block_scope_has_entries_104bcac0;
    scope_push_child(stack,(c1xx_scope *)scope);
    return (c1xx_block_scope *)scope;
  }
  scope_push_child(stack,(c1xx_scope *)0x0);
  return (c1xx_block_scope *)0x0;
}

