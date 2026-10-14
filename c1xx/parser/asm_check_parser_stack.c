void __cdecl asm_check_parser_stack(char *message)

{
  int iVar1;
  char *pcVar2;
  
  if (*message != 'y') {
    if (((g_asm_yy_lookahead->code != 0x2c) ||
        (pcVar2 = *(char **)((int)g_asm_yy_lookahead->value + 4), pcVar2 == (char *)0x0)) ||
       (*message == '\0')) {
      pcVar2 = g_asm_token_spelling[g_asm_yy_lookahead->code];
    }
    iVar1 = asm_operand_description_id();
    diag_error(400,iVar1,pcVar2);
    g_asm_operands_begun = 1;
    return;
  }
  diag_fatal_simple(0x1a);
}

