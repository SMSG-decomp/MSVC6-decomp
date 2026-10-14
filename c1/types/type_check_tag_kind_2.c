c1_token * __thiscall type_check_tag_kind_2(c1_tag_record *tag,c1_token *token)

{
  void *name;
  c1_token *pcVar1;
  c1_tag_symbol *pcVar2;
  fe_arena *a;
  c1_token *pcVar3;
  char *pcVar4;
  int iVar5;
  uint *puVar6;
  char *tag_name;
  c1_yystype *pcVar7;
  
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
  pcVar2 = tag->tag;
  if (pcVar2 == (c1_tag_symbol *)0x0) {
    name = tag->name;
    if (name == (void *)0x0) {
      tag_name = (char *)0x0;
    }
    else {
      tag_name = *(char **)((int)name + 4);
    }
    pcVar2 = decl_tag_definition_lookup((int)name,tag->kind,&tag->insert);
  }
  else {
    tag_name = pcVar2->name->text;
    pcVar2 = esu_check_tag_and_begin_enum(pcVar2,tag->kind);
  }
  tag->tag = pcVar2;
  if (pcVar2 == (c1_tag_symbol *)0x0) {
    pcVar4 = type_keyword_text(tag->kind);
    diag_error(0x289,tag_name,pcVar4);
    return g_token_newline;
  }
  if ((pcVar2->flags2 & 1) != 0) {
    return g_token_newline;
  }
  g_yylval_word5 = tag->insert;
  tag->tag->position = g_token_position;
  if ((tag->kind & 0x100) == 0) {
    g_yylval_word4 = (c1_specifier_symbol)tag->tag;
    if (g_token_arena_index == 0) {
      if (g_pool_default.left < 0x20) {
        pool_reserve(&g_pool_default,0x20);
      }
      g_pool_default.left = g_pool_default.left - 0x20;
      pcVar3 = (c1_token *)g_pool_default.cur;
      g_pool_default.cur = g_pool_default.cur + 0x20;
    }
    else {
      a = g_arenas + g_token_arena_index;
      pcVar3 = (c1_token *)a->cur;
      pcVar1 = (c1_token *)g_arenas[g_token_arena_index].end;
      a->cur = &pcVar3[1].code;
      if (pcVar1 < pcVar3 + 1) {
        arena_grow(a);
      }
    }
    if (pcVar3 != (c1_token *)0x0) {
      pcVar3->code = '\"';
      puVar6 = &g_yylval;
      pcVar7 = &pcVar3->value;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar7->words[0] = *puVar6;
        puVar6 = puVar6 + 1;
        pcVar7 = (c1_yystype *)((int)pcVar7 + 4);
      }
      return pcVar3;
    }
  }
  else {
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    g_yylval_word4 = (c1_specifier_symbol)tag->tag;
    if (g_token_arena_index == 0) {
      if (g_pool_default.left < 0x20) {
        pool_reserve(&g_pool_default,0x20);
      }
      g_pool_default.left = g_pool_default.left - 0x20;
      pcVar3 = (c1_token *)g_pool_default.cur;
      g_pool_default.cur = g_pool_default.cur + 0x20;
    }
    else {
      pcVar3 = arena_alloc(g_arenas + g_token_arena_index,0x20);
    }
    if (pcVar3 != (c1_token *)0x0) {
      pcVar3->code = '#';
      puVar6 = &g_yylval;
      pcVar7 = &pcVar3->value;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        pcVar7->words[0] = *puVar6;
        puVar6 = puVar6 + 1;
        pcVar7 = (c1_yystype *)((int)pcVar7 + 4);
      }
      return pcVar3;
    }
  }
  return (c1_token *)0x0;
}

