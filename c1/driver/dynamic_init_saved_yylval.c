void dynamic_init_saved_yylval(void)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  g_asm_no_lookahead = 1;
  puVar2 = &g_yylval;
  puVar3 = g_saved_yylval;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

