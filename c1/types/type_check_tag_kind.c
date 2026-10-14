c1_token * __thiscall type_check_tag_kind(c1_tag_record *tag,c1_token *token)

{
  c1_u8 cVar1;
  c1_token *pcVar2;
  fe_arena *a;
  c1_token *pcVar3;
  fe_name *pfVar4;
  char *pcVar5;
  int iVar6;
  uint *puVar7;
  c1_tag_symbol *pcVar8;
  c1_yystype *pcVar9;
  char *pcVar10;
  
  pcVar8 = tag->tag;
  if (pcVar8 == (c1_tag_symbol *)0x0) {
    if (tag->name == (void *)0x0) {
      pfVar4 = name_new_S();
      tag->name = pfVar4;
    }
    pcVar8 = (c1_tag_symbol *)0x0;
    if (g_class_depth < 0) {
      tag->insert = scope_insert_through_object;
    }
    else {
      cVar1 = token->code;
      tag->insert = scope_insert_through_object;
      if (cVar1 != '\x7f') {
        g_yylval_word4.tag = decl_tag_reference_lookup((int)tag->name,tag->kind,&tag->insert);
        goto LAB_1060ef60;
      }
    }
    g_yylval_word4.tag = decl_tag_reference_lookup((int)tag->name,tag->kind,&tag->insert);
  }
  else {
    g_yylval_word4.tag = decl_tag_check_kind_and_browse(pcVar8,tag->kind);
  }
LAB_1060ef60:
  tag->tag = (c1_tag_symbol *)g_yylval_word4;
  if (tag->tag == (c1_tag_symbol *)0x0) {
    if (tag->name != (void *)0x0) {
      if (pcVar8 == (c1_tag_symbol *)0x0) {
        pcVar10 = "typename";
      }
      else {
        pcVar10 = pcVar8->name->text;
      }
      pcVar5 = type_keyword_text(tag->kind);
      diag_error(0x289,pcVar10,pcVar5);
    }
    return g_token_newline;
  }
  decl_tag_copy_specifier_flags(tag->tag,&tag->words);
  g_yylval_word5 = tag->insert;
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
    pcVar2 = (c1_token *)g_arenas[g_token_arena_index].end;
    a->cur = &pcVar3[1].code;
    if (pcVar2 < pcVar3 + 1) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar3->code = '$';
  puVar7 = &g_yylval;
  pcVar9 = &pcVar3->value;
  for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    pcVar9->words[0] = *puVar7;
    puVar7 = puVar7 + 1;
    pcVar9 = (c1_yystype *)((int)pcVar9 + 4);
  }
  return pcVar3;
}

