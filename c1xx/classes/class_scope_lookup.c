c1_u8 * __thiscall class_scope_lookup(c1xx_class_scope *class_scope,int name,int kind)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  c1_lookup_result *pcVar4;
  
  pcVar2 = class_scope->cls;
  if ((pcVar2->kind & 0x1f) == 0x19) {
    pcVar3 = (c1_u8 *)(**(code **)(**(int **)pcVar2->type + 0xc))(name,kind);
    return pcVar3;
  }
  if (g_class_depth < 0) {
    pcVar4 = (*class_scope->outer->vtbl->lookup)(class_scope->outer,(void *)name,kind);
    return (c1_u8 *)pcVar4;
  }
  pcVar2 = scope_lookup_skip_type_aliases(((pcVar2->x28).members)->head,(void *)name);
  pcVar3 = g_arenas[5].cur;
  if (pcVar2 == (c1_symbol *)0x0) {
    return (c1_u8 *)0x0;
  }
  g_arenas[5].cur = g_arenas[5].cur + 8;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar1 = g_arenas[5].cur;
  if (pcVar3 != (c1_u8 *)0x0) {
    g_arenas[5].cur = g_arenas[5].cur + 0xc;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar1 != (c1_u8 *)0x0) {
      *(c1_symbol **)pcVar1 = pcVar2;
      *(c1xx_class_scope **)(pcVar1 + 4) = class_scope;
      pcVar1[8] = '\0';
      pcVar1[9] = '\0';
      pcVar1[10] = '\0';
      pcVar1[0xb] = '\0';
      *(c1_u8 **)pcVar3 = pcVar1;
      *(c1_u8 **)(pcVar3 + 4) = pcVar1;
      return pcVar3;
    }
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3[4] = '\0';
    pcVar3[5] = '\0';
    pcVar3[6] = '\0';
    pcVar3[7] = '\0';
    return pcVar3;
  }
  return (c1_u8 *)0x0;
}

