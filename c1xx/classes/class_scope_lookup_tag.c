c1_u8 * __thiscall class_scope_lookup_tag(c1xx_class_scope *class_scope,void *name)

{
  c1_sym_link *pcVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  
  pcVar2 = g_arenas[5].cur;
  pcVar1 = ((class_scope->cls->x28).members)->head;
  while( true ) {
    if (pcVar1 == (c1_sym_link *)0x0) {
      return (c1_u8 *)0x0;
    }
    if ((pcVar1->name == name) &&
       ((bVar3 = (byte)pcVar1[-1].position & 0x1f, bVar3 == 4 || (bVar3 == 0x19)))) break;
    pcVar1 = pcVar1->next;
  }
  if (&pcVar1[-1].position == (c1_u32 *)0x0) {
    return (c1_u8 *)0x0;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *(c1_u32 **)pcVar2 = &pcVar1[-1].position;
  *(c1xx_class_scope **)(pcVar2 + 4) = class_scope;
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  return pcVar2;
}

