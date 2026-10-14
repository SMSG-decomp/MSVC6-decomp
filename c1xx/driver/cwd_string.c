c1_u8 * __cdecl cwd_string(void)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x100;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (g_opt_Brepro == 0) {
    pcVar1 = (c1_u8 *)_getcwd((char *)pcVar1,0x100);
    return pcVar1;
  }
  *pcVar1 = '.';
  pcVar1[1] = '\0';
  return pcVar1;
}

