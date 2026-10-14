c1xx_token * __cdecl asm_classify_name(c1xx_token *token)

{
  byte bVar1;
  short sVar2;
  c1_lookup_entry *pcVar3;
  c1_symbol *pcVar4;
  int iVar5;
  uint *puVar6;
  void **ppvVar7;
  c1_u16 alias_code;
  
  if (g_asm_operands_begun == 0) {
    sVar2 = asm_lookup_instruction(token->value);
    if (sVar2 != -1) {
      if ((-1 < sVar2) && (sVar2 < 0x10d)) {
        if ((0xb4 < sVar2) && (sVar2 < 0xb9)) {
          g_asm_mnemonic_code = sVar2;
          *(short *)&token->value = sVar2;
          token->code = '/';
          return token;
        }
        g_asm_mnemonic_code = sVar2;
        *(short *)&token->value = sVar2;
        token->code = '0';
        return token;
      }
      if ((sVar2 < 0x10d) || (0x1be < sVar2)) {
        *(short *)&token->value = sVar2;
        token->code = '1';
        return token;
      }
      alias_code = *(c1_u16 *)("\n//\n// Cross-referenced type libraries:\n//\n" + sVar2 * 4 + 0x14)
      ;
      if ((0x10c < sVar2) && (sVar2 < 0x10f)) {
        g_asm_mnemonic_code = sVar2;
        token->code = '/';
        *(c1_u16 *)&token->value = alias_code;
        return token;
      }
      g_asm_mnemonic_code = sVar2;
      token->code = '0';
      *(c1_u16 *)&token->value = alias_code;
      return token;
    }
    sVar2 = asm_lookup_operand_keyword(token->value);
    if (sVar2 != -1) {
      diag_warning(1,0x195,token->value);
    }
  }
  else {
    if (g_asm_period_seen != 0) {
      return token;
    }
    ppvVar7 = &token->value;
    sVar2 = asm_lookup_operand_keyword(token->value);
    if (sVar2 != -1) {
      if ((-1 < sVar2) && (sVar2 < 0x36)) {
        *(short *)ppvVar7 = sVar2;
        token->code = '\'';
        return token;
      }
      if ((0x35 < sVar2) && (sVar2 < 0x3c)) {
        *(short *)ppvVar7 = sVar2;
        token->code = '(';
        return token;
      }
      if ((0x3b < sVar2) && (sVar2 < 0x3f)) {
        *(short *)ppvVar7 = sVar2;
        token->code = ')';
        return token;
      }
      bVar1 = (char)sVar2 - 0x3e;
      token->code = bVar1;
      *(ushort *)ppvVar7 = (ushort)bVar1;
      return token;
    }
    sVar2 = asm_lookup_instruction(*ppvVar7);
    if (sVar2 != -1) {
      diag_warning(1,0x195,*ppvVar7);
    }
    pcVar3 = lookup_name_in_context(g_current_scope,*ppvVar7,0x132);
    if (pcVar3 == (c1_lookup_entry *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = pcVar3->sym;
    }
    if ((pcVar4 != (c1_symbol *)0x0) && ((pcVar4->kind & 0x1f) == 5)) {
      _g_yylval_word2 = (pcVar4->x28).members;
      _g_yylval_word3 = (int)_g_yylval_word2 >> 0x1f;
      token->code = '.';
      puVar6 = &g_yylval;
      for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppvVar7 = (void *)*puVar6;
        puVar6 = puVar6 + 1;
        ppvVar7 = ppvVar7 + 1;
      }
      return token;
    }
  }
  return token;
}

