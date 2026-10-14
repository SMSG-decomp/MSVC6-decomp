c1_tag_lookup * __thiscall block_scope_lookup_tag(c1_scope_object *block_scope,int name)

{
  uchar *puVar1;
  int *piVar2;
  
  if ((block_scope->entries).buckets != (void **)0x0) {
    piVar2 = sym_list_find_tag((block_scope->entries).buckets,name);
    puVar1 = g_arenas[3].cur;
    if (piVar2 != (int *)0x0) {
      g_arenas[3].cur = g_arenas[3].cur + 8;
      if (g_arenas[3].end < g_arenas[3].cur) {
        arena_grow(g_arenas + 3);
      }
      if (puVar1 != (uchar *)0x0) {
        *(int **)puVar1 = piVar2;
        *(c1_scope_object **)(puVar1 + 4) = block_scope;
        return (c1_tag_lookup *)puVar1;
      }
      return (c1_tag_lookup *)0x0;
    }
  }
  return (c1_tag_lookup *)0x0;
}

