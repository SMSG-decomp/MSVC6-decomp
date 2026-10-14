c1_token * asm_yylex(void)

{
  byte bVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  byte bVar6;
  c1_token *pcVar7;
  c1_token *token;
  fe_name *pfVar8;
  int iVar9;
  c1_token *pcVar10;
  
  do {
    while( true ) {
      pcVar7 = token_next(&g_token_position);
      if (pcVar7 == (c1_token *)0x0) {
        diag_fatal_simple(4);
      }
      if (pcVar7->code != '\x7f') break;
      lex_line_comment_copy_or_skip();
    }
    if (g_asm_statement_start == 0) goto LAB_10622f61;
  } while (pcVar7->code == 0xf2);
  g_asm_statement_start = 0;
LAB_10622f61:
  token = (c1_token *)arena_or_pool_alloc(0x20,g_token_arena_index);
  if (token == (c1_token *)0x0) {
    token = (c1_token *)0x0;
  }
  else {
    pcVar10 = token;
    for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
      cVar3 = pcVar7->pad01[0];
      cVar4 = pcVar7->pad01[1];
      cVar5 = pcVar7->pad01[2];
      pcVar10->code = pcVar7->code;
      pcVar10->pad01[0] = cVar3;
      pcVar10->pad01[1] = cVar4;
      pcVar10->pad01[2] = cVar5;
      pcVar7 = (c1_token *)&pcVar7->unk04;
      pcVar10 = (c1_token *)&pcVar10->unk04;
    }
  }
  bVar1 = token->code;
  bVar2 = (&g_token_attributes)[bVar1];
  bVar6 = bVar2 & 0x3f;
  if (bVar6 == 0x2c) {
    if (bVar1 != 6) {
      pfVar8 = name_intern(g_token_spelling[bVar1]);
      token->code = ',';
      (token->value).name = pfVar8;
      pcVar7 = asm_classify_name(token);
      return pcVar7;
    }
    token->code = ',';
    pcVar7 = asm_classify_name(token);
    return pcVar7;
  }
  if ((bVar1 == 0x11) && (g_asm_operands_begun == 0)) {
    token->code = '0';
    (token->value).half = 7;
    return token;
  }
  if (bVar6 == 0x22) {
    token->code = '\"';
    (token->value).spec.words.storage = bVar1;
    return token;
  }
  if (bVar6 == 0x21) {
    do {
      while( true ) {
        pcVar7 = token_next(&g_token_position);
        if (pcVar7->code != '\x7f') break;
        lex_line_comment_copy_or_skip();
      }
    } while (pcVar7->code != 0xf2);
    bVar1 = (&g_token_attributes)[pcVar7->code];
    (token->value).half = 0xf2;
    token->code = bVar1 & 0x3f;
    return token;
  }
  if (0x25 < bVar6) {
    token->code = bVar6;
    return token;
  }
  token->code = bVar6;
  (token->value).half = bVar2 & 0xff3f;
  return token;
}

