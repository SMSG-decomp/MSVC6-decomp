void __cdecl asm_report_syntax_error(char *message,int state)

{
  int iVar1;
  char *pcVar2;
  undefined *puVar3;
  
  if (message == (char *)0x0) {
    diag_error(0x3c);
    return;
  }
  if (((*g_asm_lookahead == 0x2c) &&
      (pcVar2 = *(char **)(*(int *)(g_asm_lookahead + 8) + 4), pcVar2 != (char *)0x0)) &&
     (*pcVar2 != '\0')) {
    iVar1 = asm_operand_description_id();
    diag_error(400,iVar1,pcVar2);
    return;
  }
  puVar3 = (&PTR_s_no_token_1065b868)[*g_asm_lookahead];
  iVar1 = asm_operand_description_id();
  diag_error(400,iVar1,puVar3);
  return;
}

