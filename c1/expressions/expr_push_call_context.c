void __cdecl expr_push_call_context(c1_type *type)

{
  int iVar1;
  uchar *puVar2;
  byte bVar3;
  
  puVar2 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x24;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  *(c1_call_context **)puVar2 = g_call_context;
  *(c1_type **)(puVar2 + 0x10) = type;
  iVar1 = ((type->extra).params)->count;
  *(int *)(puVar2 + 0x14) = iVar1;
  *(c1_type ***)(puVar2 + 4) = ((type->extra).params)->types;
  if (iVar1 == 0) {
    bVar3 = puVar2[0x20] & 0xf7;
  }
  else {
    bVar3 = puVar2[0x20] | 8;
  }
  puVar2[0x20] = bVar3;
  if ((type->flags & 0x4000) == 0) {
    if ((type->flags & 0x8000) != 0) {
      puVar2[0x20] = puVar2[0x20] | 4;
    }
    g_call_context = (c1_call_context *)puVar2;
    return;
  }
  puVar2[0x20] = bVar3 | 2;
  g_call_context = (c1_call_context *)puVar2;
  return;
}

