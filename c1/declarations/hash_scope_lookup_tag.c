c1_tag_lookup * __thiscall hash_scope_lookup_tag(c1_scope_object *hash_scope,void *name)

{
  int *piVar1;
  uchar *puVar2;
  c1_tag_lookup *pcVar3;
  
  puVar2 = g_arenas[3].cur;
  if ((hash_scope->entries).buckets != (void **)0x0) {
    for (piVar1 = (hash_scope->entries).buckets
                  [*(uint *)((int)name + 8) & hash_scope->mask & 0xffff]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[1]) {
      if (((void *)*piVar1 == name) && ((*(byte *)(piVar1 + -2) & 0x1f) == 4)) {
        if (piVar1 + -2 != (int *)0x0) {
          g_arenas[3].cur = g_arenas[3].cur + 8;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          if (puVar2 == (uchar *)0x0) {
            return (c1_tag_lookup *)0x0;
          }
          *(int **)puVar2 = piVar1 + -2;
          *(c1_scope_object **)(puVar2 + 4) = hash_scope;
          return (c1_tag_lookup *)puVar2;
        }
        break;
      }
    }
  }
  if (hash_scope->level == '\x02') {
    pcVar3 = (*hash_scope->parent->vtbl->lookup_tag)(hash_scope->parent,(int)name);
    return pcVar3;
  }
  return (c1_tag_lookup *)0x0;
}

