byte * asm_yylex(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  c1xx_token *pcVar5;
  void *pvVar6;
  int iVar7;
  c1xx_token *pcVar8;
  
  do {
    while( true ) {
      pbVar4 = token_next((c1_token_reader *)&g_token_position);
      if (pbVar4 == (byte *)0x0) {
        diag_fatal_simple(4);
      }
      if (*pbVar4 != 0x7f) break;
      lex_line_comment_copy_or_skip();
    }
    if (g_asm_at_block_start == 0) goto LAB_1045596e;
  } while (*pbVar4 == 0xf2);
  g_asm_at_block_start = 0;
LAB_1045596e:
  pcVar5 = (c1xx_token *)arena_or_pool_alloc(0x30,g_token_arena_index);
  if (pcVar5 == (c1xx_token *)0x0) {
    pcVar5 = (c1xx_token *)0x0;
  }
  else {
    pcVar8 = pcVar5;
    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      bVar1 = pbVar4[1];
      bVar2 = pbVar4[2];
      bVar3 = pbVar4[3];
      pcVar8->code = pbVar4[0];
      pcVar8->unk01[0] = bVar1;
      pcVar8->unk01[1] = bVar2;
      pcVar8->unk01[2] = bVar3;
      pbVar4 = pbVar4 + 4;
      pcVar8 = (c1xx_token *)(pcVar8->unk01 + 3);
    }
  }
  bVar1 = pcVar5->code;
  bVar2 = g_token_op_flags[bVar1];
  bVar3 = bVar2 & 0x3f;
  if (bVar3 == 0x2c) {
    if (bVar1 != 6) {
      pvVar6 = name_intern(g_token_spelling[bVar1]);
      pcVar5->code = ',';
      pcVar5->value = pvVar6;
      pcVar5 = asm_classify_name(pcVar5);
      return &pcVar5->code;
    }
    pcVar5->code = ',';
    pcVar5 = asm_classify_name(pcVar5);
    return &pcVar5->code;
  }
  if ((bVar1 == 0x11) && (g_asm_operands_begun == 0)) {
    pcVar5->code = '0';
    *(undefined2 *)&pcVar5->value = 7;
    return &pcVar5->code;
  }
  if (bVar3 == 0x22) {
    pcVar5->code = '\"';
    *(byte *)&pcVar5->value = bVar1;
    return &pcVar5->code;
  }
  if (bVar3 == 0x21) {
    do {
      while( true ) {
        pbVar4 = token_next((c1_token_reader *)&g_token_position);
        if (*pbVar4 != 0x7f) break;
        lex_line_comment_copy_or_skip();
      }
    } while (*pbVar4 != 0xf2);
    bVar1 = g_token_op_flags[*pbVar4];
    *(undefined2 *)&pcVar5->value = 0xf2;
    pcVar5->code = bVar1 & 0x3f;
    return &pcVar5->code;
  }
  if (0x25 < bVar3) {
    pcVar5->code = bVar3;
    return &pcVar5->code;
  }
  pcVar5->code = bVar3;
  *(ushort *)&pcVar5->value = bVar2 & 0xff3f;
  return &pcVar5->code;
}

