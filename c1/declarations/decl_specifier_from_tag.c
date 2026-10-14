c1_token * __cdecl decl_specifier_from_tag(c1_token *token)

{
  c1_specifier_state *pcVar1;
  c1_token *pcVar2;
  int iVar3;
  c1_specifier_state local_3c;
  
  pcVar1 = &local_3c;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar1->token = 0;
    pcVar1 = (c1_specifier_state *)((int)pcVar1 + 4);
  }
  local_3c.token = token;
  pcVar2 = decl_parse_declaration_specifiers(&local_3c);
  if ((pcVar2->code == '$') && ((g_compile_flags_c4 & 0x10000000) == 0)) {
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
  }
  return pcVar2;
}

