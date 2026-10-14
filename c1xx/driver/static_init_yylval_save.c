void __cdecl static_init_yylval_save(void)

{
  int iVar1;
  uint *src;
  uint *dst;
  
  g_asm_empty_token.code = '\x01';
  src = &g_yylval;
  dst = (uint *)&g_asm_empty_token.value;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  return;
}

