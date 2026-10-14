int __cdecl pp_check_expected_endif_pragma_tail(byte last,int mode,int depth)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = token_next((c1_token_reader *)&g_token_position);
  if (((pbVar2 != (byte *)0x0) && (*pbVar2 == 6)) &&
     (iVar3 = pragma_lookup_name(*(char **)(*(int *)(pbVar2 + 8) + 4)), iVar3 == 0x31)) {
    return 7;
  }
switchD_1040f1bc_caseD_6:
  cVar1 = pp_skip_to_next_directive();
  switch(cVar1) {
  case '\0':
  case '\x04':
  case '\x05':
    depth = depth + 1;
    goto switchD_1040f1bc_caseD_6;
  case '\x02':
    last = 2;
    break;
  case '\x03':
    if (depth == 0) {
      pp_warn_extra_tokens("#endif");
      return 4;
    }
    depth = depth + -1;
  default:
    goto switchD_1040f1bc_caseD_6;
  case '\b':
    goto switchD_1040f1bc_caseD_8;
  }
  if (depth == 0) {
    if (mode == 6) {
      diag_fatal_simple(0x16);
    }
    if (last == 2) {
      if (g_ms_extensions != '\0') {
        lex_skip_whitespace();
        return 3;
      }
      pp_warn_extra_tokens("#else");
      return 3;
    }
    return 2;
  }
  last = 0xb;
  goto switchD_1040f1bc_caseD_6;
switchD_1040f1bc_caseD_8:
  if (mode == 8) {
    iVar3 = pp_check_expected_endif_pragma_tail(last,8,depth);
    return iVar3;
  }
  goto switchD_1040f1bc_caseD_6;
}

