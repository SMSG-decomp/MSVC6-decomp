void __cdecl lex_put_string_byte(byte c,int *buf)

{
  byte *pbVar1;
  
  if (buf != (int *)0x0) {
    pbVar1 = (byte *)buf[1];
    if (0x7f7 < *buf) {
      pbVar1 = *(byte **)(buf[2] + 0x7f8);
      if (pbVar1 == (byte *)0x0) {
        pbVar1 = mem_xmalloc(0x800);
        pbVar1[0x7f8] = 0;
        pbVar1[0x7f9] = 0;
        pbVar1[0x7fa] = 0;
        pbVar1[0x7fb] = 0;
        *(byte **)(buf[2] + 0x7f8) = pbVar1;
      }
      buf[2] = (int)pbVar1;
      pbVar1[0x7fc] = 0;
      pbVar1[0x7fd] = 0;
      pbVar1[0x7fe] = 0;
      pbVar1[0x7ff] = 0;
      *buf = 0;
    }
    *pbVar1 = c;
    *buf = *buf + 1;
    buf[1] = (int)(pbVar1 + 1);
    return;
  }
  if ((char *)0x104de253 < g_string_literal_cur) {
    diag_fatal_simple(0x40);
  }
  *g_string_literal_cur = c;
  g_string_literal_cur = g_string_literal_cur + 1;
  return;
}

