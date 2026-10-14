void __cdecl asm_check_parser_stack(char *message)

{
  int iVar1;
  undefined *puVar2;
  
  if (*message != 'y') {
    if (((*g_asm_lookahead != 0x2c) ||
        (puVar2 = *(undefined **)(*(int *)(g_asm_lookahead + 8) + 4), puVar2 == (undefined *)0x0))
       || (*message == '\0')) {
      puVar2 = (&PTR_s_no_token_1065b868)[*g_asm_lookahead];
    }
    iVar1 = asm_operand_description_id();
    diag_error(400,iVar1,puVar2);
    g_asm_operands_begun = 1;
    return;
  }
  diag_fatal_simple(0x1a);
}

