void __cdecl token_static_records_init(void)

{
  int iVar1;
  void **slot;
  c1_u8 *next_rec;
  c1_u8 *rec;
  
  iVar1 = 1;
  slot = (void **)&g_token_newline;
  do {
    if ((&g_token_has_static_record)[iVar1] == '\0') {
      *slot = (void *)0x0;
    }
    else {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      rec = g_pool_default;
      g_pool_default_left = g_pool_default_left - 0x30;
      if (g_pool_default == (c1_u8 *)0x0) {
        g_pool_default = g_pool_default + 0x30;
        *slot = (void *)0x0;
      }
      else {
        next_rec = g_pool_default + 0x30;
        *g_pool_default = (c1_u8)iVar1;
        g_pool_default = next_rec;
        rec[8] = (c1_u8)iVar1;
        *slot = rec;
      }
    }
    slot = slot + 1;
    iVar1 = iVar1 + 1;
  } while ((int)slot < 0x104d1b00);
  return;
}

