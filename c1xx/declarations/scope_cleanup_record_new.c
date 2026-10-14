void __fastcall scope_cleanup_record_new(c1_scope_stack *stack)

{
  c1xx_scope *pcVar1;
  c1_u8 *scope;
  
  scope = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x20;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  if (scope != (c1_u8 *)0x0) {
    pcVar1 = stack->current;
    scope[8] = g_block_depth;
    scope[4] = '\0';
    scope[5] = '\0';
    scope[6] = '\0';
    scope[7] = '\0';
    *(c1xx_scope **)(scope + 0xc) = pcVar1;
    scope[0x10] = '\0';
    scope[0x11] = '\0';
    scope[0x12] = '\0';
    scope[0x13] = '\0';
    scope[0x18] = '\x0f';
    scope[0x19] = '\0';
    scope[0x1a] = '\0';
    scope[0x1b] = '\0';
    scope[0x1c] = '\0';
    scope[0x1d] = '\0';
    scope[0x1e] = '\0';
    scope[0x1f] = '\0';
    *(undefined ***)scope = &PTR_hash_scope_has_entries_104bd894;
    scope_push_child(stack,(c1xx_scope *)scope);
    return;
  }
  scope_push_child(stack,(c1xx_scope *)0x0);
  return;
}

