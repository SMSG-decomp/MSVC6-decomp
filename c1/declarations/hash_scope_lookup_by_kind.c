c1_scope_lookup * __thiscall hash_scope_lookup_by_kind(c1_scope_object *hash_scope,void *name)

{
  int *piVar1;
  uchar *puVar2;
  
  puVar2 = g_arenas[3].cur;
  piVar1 = (hash_scope->entries).buckets[*(uint *)((int)name + 8) & hash_scope->mask & 0xffff];
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (c1_scope_lookup *)0x0;
    }
    if ((name == (void *)*piVar1) && ((*(byte *)(piVar1 + -2) & 0x1f) != 4)) break;
    piVar1 = (int *)piVar1[1];
  }
  g_arenas[3].cur = g_arenas[3].cur + 8;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (puVar2 == (uchar *)0x0) {
    return (c1_scope_lookup *)0x0;
  }
  *(int **)puVar2 = piVar1 + -2;
  *(c1_scope_object **)(puVar2 + 4) = hash_scope;
  return (c1_scope_lookup *)puVar2;
}

