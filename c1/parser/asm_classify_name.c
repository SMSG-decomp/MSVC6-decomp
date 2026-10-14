c1_token * __cdecl asm_classify_name(c1_token *token)

{
  byte bVar1;
  c1_u16 cVar2;
  short sVar3;
  c1_scope_lookup *found;
  c1_symbol *pcVar4;
  int iVar5;
  uint *puVar6;
  c1_yystype *pcVar7;
  c1_u16 opcode;
  
  if (g_asm_operands_begun == 0) {
    cVar2 = asm_lookup_instruction((token->value).ptr);
    if (cVar2 != 0xffff) {
      if ((-1 < (short)cVar2) && ((short)cVar2 < 0x10d)) {
        if ((0xb4 < (short)cVar2) && ((short)cVar2 < 0xb9)) {
          g_asm_mnemonic_opcode = cVar2;
          (token->value).half = cVar2;
          token->code = '/';
          return token;
        }
        g_asm_mnemonic_opcode = cVar2;
        (token->value).half = cVar2;
        token->code = '0';
        return token;
      }
      if (((short)cVar2 < 0x10d) || (0x1be < (short)cVar2)) {
        (token->value).half = cVar2;
        token->code = '1';
        return token;
      }
      opcode = *(c1_u16 *)("Table_stack" + (short)cVar2 * 4);
      if ((0x10c < (short)cVar2) && ((short)cVar2 < 0x10f)) {
        g_asm_mnemonic_opcode = cVar2;
        token->code = '/';
        (token->value).half = opcode;
        return token;
      }
      g_asm_mnemonic_opcode = cVar2;
      token->code = '0';
      (token->value).half = opcode;
      return token;
    }
    sVar3 = asm_lookup_operand_keyword((token->value).ptr);
    if (sVar3 != -1) {
      diag_warning(1,0x195,(token->value).ptr);
    }
  }
  else {
    if (g_asm_after_period != 0) {
      return token;
    }
    pcVar7 = &token->value;
    cVar2 = asm_lookup_operand_keyword((token->value).ptr);
    if (cVar2 != 0xffff) {
      if ((-1 < (short)cVar2) && ((short)cVar2 < 0x36)) {
        pcVar7->half = cVar2;
        token->code = '\'';
        return token;
      }
      if ((0x35 < (short)cVar2) && ((short)cVar2 < 0x3c)) {
        pcVar7->half = cVar2;
        token->code = '(';
        return token;
      }
      if ((0x3b < (short)cVar2) && ((short)cVar2 < 0x3f)) {
        pcVar7->half = cVar2;
        token->code = ')';
        return token;
      }
      bVar1 = (char)cVar2 - 0x3e;
      token->code = bVar1;
      *(ushort *)pcVar7 = (ushort)bVar1;
      return token;
    }
    sVar3 = asm_lookup_instruction(pcVar7->ptr);
    if (sVar3 != -1) {
      diag_warning(1,0x195,pcVar7->ptr);
    }
    found = scope_stack_lookup(g_current_scope,pcVar7->words[0]);
    if (found == (c1_scope_lookup *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = found->sym;
    }
    if ((pcVar4 != (c1_symbol *)0x0) && ((pcVar4->kind & 0x1f) == 5)) {
      _g_yylval_word2 = (pcVar4->x28).value;
      _g_yylval_word3 = _g_yylval_word2 >> 0x1f;
      token->code = '.';
      puVar6 = &g_yylval;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar7->words[0] = *puVar6;
        puVar6 = puVar6 + 1;
        pcVar7 = (c1_yystype *)((int)pcVar7 + 4);
      }
      return token;
    }
  }
  return token;
}

