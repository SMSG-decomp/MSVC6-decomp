c1_u8 * __cdecl token_new_newline(c1_u8 *token)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (token != (c1_u8 *)0x0) {
    *token = 0xf2;
    puVar2 = &g_yylval;
    puVar3 = (uint *)(token + 8);
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return token;
  }
  return (c1_u8 *)0x0;
}

