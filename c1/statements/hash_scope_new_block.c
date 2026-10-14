void __fastcall hash_scope_new_block(c1_scope_stack *scopes)

{
  c1_scope_object *pcVar1;
  uchar *scope;
  
  scope = g_arenas[2].cur;
  g_arenas[2].cur = g_arenas[2].cur + 0x18;
  if (g_arenas[2].end < g_arenas[2].cur) {
    arena_grow(g_arenas + 2);
  }
  if (scope != (uchar *)0x0) {
    pcVar1 = scopes->current;
    scope[8] = g_block_depth;
    scope[4] = '\0';
    scope[5] = '\0';
    scope[6] = '\0';
    scope[7] = '\0';
    *(c1_scope_object **)(scope + 0xc) = pcVar1;
    scope[0x14] = '\x0f';
    scope[0x15] = '\0';
    scope[0x16] = '\0';
    scope[0x17] = '\0';
    *(undefined ***)scope = &PTR_scope_has_entries_1065389c;
    scope_push_child(scopes,(c1_scope_object *)scope);
    return;
  }
  scope_push_child(scopes,(c1_scope_object *)0x0);
  return;
}

