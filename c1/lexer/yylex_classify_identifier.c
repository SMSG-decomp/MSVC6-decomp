c1_token * __cdecl yylex_classify_identifier(c1_token *token)

{
  c1_token *pcVar1;
  c1_scope_lookup *found;
  fe_arena *a;
  c1_token *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  uint *puVar5;
  uint *dst_words;
  
  pcVar3 = (c1_symbol *)token;
  if ((g_compile_flags_c4 & 0x80000000) == 0) {
    if ((g_compile_flags_c4 & 1) != 0) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return token;
    }
    if ((g_paren_level_flags[g_paren_depth] & 2) != 0) {
      return token;
    }
    if (g_current_scope->unk209 != '\0') {
      return token;
    }
    found = scope_stack_lookup(g_current_scope,(token->value).words[0]);
    if (found == (c1_scope_lookup *)0x0) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = found->sym;
    }
    if (pcVar3 == (c1_symbol *)0x0) {
      return token;
    }
  }
  if ((pcVar3->flags1 & 4) == 0) {
    return token;
  }
  if ((((pcVar3->kind & 0x1f) == 4) && ((g_paren_level_flags[g_paren_depth] & 1) != 0)) &&
     (((byte)g_compile_flags_c8 & 8) == 0)) {
    return token;
  }
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->reference_symbol)(pcVar3);
  }
  g_yylval = (uint)pcVar3;
  if (g_token_arena_index == 0) {
    if (g_pool_default.left < 0x20) {
      pool_reserve(&g_pool_default,0x20);
    }
    g_pool_default.left = g_pool_default.left - 0x20;
    pcVar2 = (c1_token *)g_pool_default.cur;
    g_pool_default.cur = g_pool_default.cur + 0x20;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar2 = (c1_token *)a->cur;
    pcVar1 = (c1_token *)g_arenas[g_token_arena_index].end;
    a->cur = &pcVar2[1].code;
    if (pcVar1 < pcVar2 + 1) {
      arena_grow(a);
    }
  }
  if (pcVar2 == (c1_token *)0x0) {
    return (c1_token *)0x0;
  }
  pcVar2->code = '\x1e';
  puVar5 = &g_yylval;
  dst_words = (uint *)&pcVar2->value;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *dst_words = *puVar5;
    puVar5 = puVar5 + 1;
    dst_words = dst_words + 1;
  }
  return pcVar2;
}

