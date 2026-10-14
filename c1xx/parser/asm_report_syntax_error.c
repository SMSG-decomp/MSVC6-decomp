void __cdecl asm_report_syntax_error(char *message,int state)

{
  int iVar1;
  char *pcVar2;
  
  if (message == (char *)0x0) {
    diag_error(0x3c);
    return;
  }
  if (((g_asm_yy_lookahead->code == 0x2c) &&
      (pcVar2 = *(char **)((int)g_asm_yy_lookahead->value + 4), pcVar2 != (char *)0x0)) &&
     (*pcVar2 != '\0')) {
    iVar1 = asm_operand_description_id();
    diag_error(400,iVar1,pcVar2);
    return;
  }
  pcVar2 = g_asm_token_spelling[g_asm_yy_lookahead->code];
  iVar1 = asm_operand_description_id();
  diag_error(400,iVar1,pcVar2);
  return;
}

