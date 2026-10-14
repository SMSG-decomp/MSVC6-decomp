int __cdecl pp_pragma_directive_to_output(void)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  fwrite("#pragma ",8,1,g_pp_output_stream);
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x10) == 0)))) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  g_opt_E_preprocess = 0;
  pbVar2 = token_next((c1_token_reader *)&g_token_position);
  g_opt_E_preprocess = 1;
  if (*pbVar2 != 6) {
    pcVar5 = g_token_spelling[*pbVar2];
    goto LAB_10460aec;
  }
  uVar4 = 0xffffffff;
  pcVar5 = *(char **)(*(int *)(pbVar2 + 8) + 4);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  fwrite(*(char **)(*(int *)(pbVar2 + 8) + 4),~uVar4 - 1,1,g_pp_output_stream);
  iVar3 = pragma_lookup_name(*(char **)(*(int *)(pbVar2 + 8) + 4));
  if (iVar3 == 0x24) {
    pragma_include_alias();
  }
  else if (iVar3 == 0x25) {
    pragma_once();
  }
switchD_10460ab6_caseD_1:
  pbVar2 = token_next((c1_token_reader *)&g_token_position);
  switch((uint)*pbVar2) {
  case 1:
  case 0x88:
    goto switchD_10460ab6_caseD_1;
  default:
    pcVar5 = g_token_spelling[*pbVar2];
LAB_10460aec:
    uVar4 = 0xffffffff;
    pcVar6 = pcVar5;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    break;
  case 0x2d:
    goto switchD_10460ab6_caseD_2d;
  case 0x65:
    uVar4 = (uint)*(ushort *)(pbVar2 + 0xc);
    pcVar5 = *(char **)(pbVar2 + 8);
  }
  fwrite(pcVar5,uVar4 - 1,1,g_pp_output_stream);
  goto switchD_10460ab6_caseD_1;
switchD_10460ab6_caseD_2d:
  if (((g_compile_flags_c8 & 0x32000000) == 0) &&
     (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)) &&
      ((((byte)g_compile_flags_cc & 0x10) == 0 &&
       (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))))))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return g_token_newline;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return g_token_newline;
}

