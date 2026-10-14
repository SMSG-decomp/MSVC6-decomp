c1_u8 * __cdecl pp_output_pragma(void)

{
  char cVar1;
  c1_token *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  fwrite("#pragma ",8,1,g_pp_output_stream);
  g_context_arena_index = 3;
  g_expr_arena_index = 3;
  g_opt_E_preprocess = 0;
  pcVar2 = token_next(&g_token_position);
  g_opt_E_preprocess = 1;
  if (pcVar2->code != 6) {
    pcVar5 = g_token_spelling[pcVar2->code];
    goto LAB_1062c291;
  }
  pcVar5 = ((pcVar2->value).name)->text;
  uVar4 = 0xffffffff;
  pcVar6 = pcVar5;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  fwrite(pcVar5,~uVar4 - 1,1,g_pp_output_stream);
  iVar3 = pragma_lookup_name(((pcVar2->value).name)->text);
  if (iVar3 == 0x24) {
    pragma_include_alias();
  }
  else if (iVar3 == 0x25) {
    pragma_once();
  }
switchD_1062c26c_caseD_1:
  pcVar2 = token_next(&g_token_position);
  switch((uint)pcVar2->code) {
  case 1:
  case 0x88:
    goto switchD_1062c26c_caseD_1;
  default:
    pcVar5 = g_token_spelling[pcVar2->code];
LAB_1062c291:
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
    goto switchD_1062c26c_caseD_2d;
  case 0x65:
    uVar4 = (uint)(pcVar2->value).string.length;
    pcVar5 = (pcVar2->value).ptr;
  }
  fwrite(pcVar5,uVar4 - 1,1,g_pp_output_stream);
  goto switchD_1062c26c_caseD_1;
switchD_1062c26c_caseD_2d:
  g_context_arena_index = 3;
  g_expr_arena_index = 3;
  return g_token_newline;
}

