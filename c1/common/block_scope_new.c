void __thiscall block_scope_new(c1_scope_stack *scopes,void *parameter_scope)

{
  c1_scope_object *scope;
  
  scope = (c1_scope_object *)g_arenas[2].cur;
  g_arenas[2].cur = g_arenas[2].cur + 0x14;
  if (g_arenas[2].end < g_arenas[2].cur) {
    arena_grow(g_arenas + 2);
  }
  if (scope == (c1_scope_object *)0x0) {
    scope = (c1_scope_object *)0x0;
  }
  else {
    *(uchar *)((int)scope + 4) = '\0';
    *(uchar *)((int)scope + 5) = '\0';
    *(uchar *)((int)scope + 6) = '\0';
    *(uchar *)((int)scope + 7) = '\0';
    *(uchar *)((int)scope + 8) = '\x01';
    *(uchar *)((int)scope + 0xc) = '\0';
    *(uchar *)((int)scope + 0xd) = '\0';
    *(uchar *)((int)scope + 0xe) = '\0';
    *(uchar *)((int)scope + 0xf) = '\0';
    *(void **)((int)scope + 0x10) = parameter_scope;
    *(undefined ***)scope = &PTR_scope_has_entries_10652c4c;
  }
  if (parameter_scope != (void *)0x0) {
    g_function_parameter_scope = parameter_scope;
  }
  scope_push_child(scopes,scope);
  return;
}

