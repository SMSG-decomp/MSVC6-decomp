void __cdecl token_static_records_init(void)

{
  uchar *puVar1;
  uchar *puVar2;
  int iVar3;
  c1_u8 **slot;
  
  iVar3 = 1;
  slot = (c1_u8 **)&g_token_newline;
  do {
    if ((&UNK_106548bc)[iVar3] == '\0') {
      *slot = (c1_u8 *)0x0;
    }
    else {
      if (g_pool_default.left < 0x20) {
        pool_reserve(&g_pool_default,0x20);
      }
      puVar1 = g_pool_default.cur;
      g_pool_default.left = g_pool_default.left - 0x20;
      if (g_pool_default.cur == (uchar *)0x0) {
        g_pool_default.cur = g_pool_default.cur + 0x20;
        *slot = (c1_u8 *)0x0;
      }
      else {
        puVar2 = g_pool_default.cur + 0x20;
        *g_pool_default.cur = (uchar)iVar3;
        g_pool_default.cur = puVar2;
        puVar1[8] = (uchar)iVar3;
        *slot = puVar1;
      }
    }
    slot = slot + 1;
    iVar3 = iVar3 + 1;
  } while ((int)slot < 0x1065d9ac);
  return;
}

