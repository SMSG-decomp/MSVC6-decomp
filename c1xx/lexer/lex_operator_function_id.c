c1_u8 * __cdecl lex_operator_function_id(void)

{
  c1_u8 *pcVar1;
  void *pvVar2;
  byte *pbVar3;
  char *pcVar4;
  c1_u8 *pcVar5;
  uint uVar6;
  c1_arena *a;
  int iVar7;
  uint *yylval_words;
  uint *yylval_words_2;
  uint uVar8;
  uint *puVar9;
  int letter;
  
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe | 0x80000010;
  g_compile_flags_c8 = g_compile_flags_c8 | 8;
  pbVar3 = yylex_cpp();
  uVar8 = g_compile_flags_c4 & 0x7fffffef;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffff7;
  switch(*pbVar3) {
  case 0x1f:
  case 0x24:
    g_compile_flags_c4 = uVar8 | 4;
    if (g_token_arena_index == 0) {
      pcVar5 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar5 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (pcVar5 == (c1_u8 *)0x0) {
      return (c1_u8 *)0x0;
    }
    *pcVar5 = 0x8f;
    yylval_words = &g_yylval;
    puVar9 = (uint *)(pcVar5 + 8);
    for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *yylval_words;
      yylval_words = yylval_words + 1;
      puVar9 = puVar9 + 1;
    }
    return pcVar5;
  default:
    uVar6 = (uint)*pbVar3;
    if ((g_token_op_flags[uVar6] & 0x40) == 0) {
      if (*pbVar3 == 6) {
        uVar6 = *(uint *)(pbVar3 + 8);
        letter = 0x49;
      }
      else {
        letter = 0x4c;
      }
      g_compile_flags_c4 = uVar8;
      diag_error(0x341,letter,uVar6);
      return g_token_newline;
    }
    g_compile_flags_c4 = uVar8;
    g_yylval_word1 = name_intern(g_token_spelling[uVar6]);
    g_yylval._0_1_ = pbVar3[8];
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar5 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      a = g_arenas + g_token_arena_index;
      pcVar5 = a->cur;
      pcVar1 = g_arenas[g_token_arena_index].end;
      a->cur = pcVar5 + 0x30;
      if (pcVar1 < pcVar5 + 0x30) {
        arena_grow(a);
      }
    }
    if (pcVar5 == (c1_u8 *)0x0) {
      return (c1_u8 *)0x0;
    }
    goto LAB_1042ea48;
  case 0x34:
    g_yylval._0_1_ = 0x34;
    g_compile_flags_c4 = uVar8;
    g_yylval_word1 = name_intern(g_token_spelling[*pbVar3]);
    break;
  case 0x41:
    g_compile_flags_c4 = uVar8;
    pbVar3 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar3 != 0x7a) {
      diag_error(0x21f);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
    }
    g_yylval_word1 = name_intern("[]");
    g_yylval._0_1_ = 0x41;
    break;
  case 0x59:
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffee;
    pcVar5 = lex_make_operator_name_token(pbVar3);
    return pcVar5;
  case 0x76:
    g_compile_flags_c4 = uVar8;
    pbVar3 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar3 != 0x7e) {
      diag_error(0x220);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
    }
    g_yylval_word1 = name_intern("()");
    g_yylval._0_1_ = 0x76;
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    break;
  case 0x8c:
    g_compile_flags_c4 = uVar8;
    pcVar4 = lex_peek_token((uint *)&g_token_position);
    if (*pcVar4 == 'A') {
      token_next((c1_token_reader *)&g_token_position);
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar3 != 0x7a) {
        diag_error(0x21f);
      }
      if (g_token_arena_index == 0) {
        pcVar5 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar5 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      pvVar2 = g_name_array_new;
      if (pcVar5 == (c1_u8 *)0x0) {
        return (c1_u8 *)0x0;
      }
      *pcVar5 = 0x8e;
      pcVar5[8] = 0x8c;
      *(void **)(pcVar5 + 0xc) = pvVar2;
      return pcVar5;
    }
    if (g_token_arena_index == 0) {
      pcVar5 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar5 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    pvVar2 = g_name_new;
    if (pcVar5 == (c1_u8 *)0x0) {
      return (c1_u8 *)0x0;
    }
    *pcVar5 = 0x8e;
    pcVar5[8] = 0x8c;
    *(void **)(pcVar5 + 0xc) = pvVar2;
    return pcVar5;
  case 0x8d:
    g_compile_flags_c4 = uVar8;
    pcVar4 = lex_peek_token((uint *)&g_token_position);
    if (*pcVar4 == 'A') {
      token_next((c1_token_reader *)&g_token_position);
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar3 != 0x7a) {
        diag_error(0x21f);
      }
      pcVar5 = arena_or_pool_alloc(0x30,g_token_arena_index);
      pvVar2 = g_name_array_delete;
      if (pcVar5 != (c1_u8 *)0x0) {
        *pcVar5 = 0x8e;
        pcVar5[8] = 0x8d;
        *(void **)(pcVar5 + 0xc) = pvVar2;
        return pcVar5;
      }
    }
    else {
      pcVar5 = arena_or_pool_alloc(0x30,g_token_arena_index);
      pvVar2 = g_name_delete;
      if (pcVar5 != (c1_u8 *)0x0) {
        *pcVar5 = 0x8e;
        pcVar5[8] = 0x8d;
        *(void **)(pcVar5 + 0xc) = pvVar2;
        return pcVar5;
      }
    }
    return (c1_u8 *)0x0;
  }
  if (g_token_arena_index == 0) {
    pcVar5 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    pcVar5 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (pcVar5 == (c1_u8 *)0x0) {
    pcVar5 = lex_operator_function_id_fail();
    return pcVar5;
  }
LAB_1042ea48:
  *pcVar5 = 0x8e;
  yylval_words_2 = &g_yylval;
  puVar9 = (uint *)(pcVar5 + 8);
  for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *yylval_words_2;
    yylval_words_2 = yylval_words_2 + 1;
    puVar9 = puVar9 + 1;
  }
  return pcVar5;
}

