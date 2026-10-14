void dynamic_init_token_position_table(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = g_token_position_table;
  iVar2 = 7;
  do {
    *piVar1 = g_lex_position;
    piVar1[1] = 0;
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

