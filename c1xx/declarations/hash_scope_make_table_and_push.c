void __fastcall hash_scope_make_table_and_push(void *scope)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  c1_u8 *pcVar3;
  
  if (*(int *)((int)scope + 0x14) != 0) {
    return;
  }
  if ((g_compile_flags_c8 & 0x50000000) == 0) {
    pcVar1 = g_arenas[4].cur + *(int *)((int)scope + 0x18) * 4 + 4;
    pcVar3 = g_arenas[4].cur;
    pcVar2 = g_arenas[0].cur;
    if (pcVar1 <= g_arenas[4].end) goto LAB_10492593;
    a = g_arenas + 4;
    g_arenas[4].cur = pcVar1;
  }
  else {
    pcVar2 = g_arenas[0].cur + *(int *)((int)scope + 0x18) * 4 + 4;
    pcVar3 = g_arenas[0].cur;
    pcVar1 = g_arenas[4].cur;
    if (pcVar2 <= g_arenas[0].end) goto LAB_10492593;
    a = g_arenas;
    g_arenas[0].cur = pcVar2;
  }
  arena_grow(a);
  pcVar2 = g_arenas[0].cur;
  pcVar1 = g_arenas[4].cur;
LAB_10492593:
  g_arenas[4].cur = pcVar1;
  g_arenas[0].cur = pcVar2;
  *(c1_u8 **)((int)scope + 0x14) = pcVar3;
  scope_push_block(g_current_scope,scope);
  return;
}

