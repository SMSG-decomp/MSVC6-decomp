c1_u8 * cwd_string(void)

{
  uchar *_DstBuf;
  c1_u8 *pcVar1;
  
  _DstBuf = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0x100;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  if (g_opt_Brepro == 0) {
    pcVar1 = (c1_u8 *)_getcwd((char *)_DstBuf,0x100);
    return pcVar1;
  }
  *_DstBuf = '.';
  _DstBuf[1] = '\0';
  return _DstBuf;
}

