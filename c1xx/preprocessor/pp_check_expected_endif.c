int __cdecl pp_check_expected_endif(int mode)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
switchD_1040f1bc_caseD_6:
  cVar2 = '\v';
  cVar1 = pp_skip_to_next_directive();
  switch(cVar1) {
  case '\0':
  case '\x04':
  case '\x05':
    iVar3 = iVar3 + 1;
    goto switchD_1040f1bc_caseD_6;
  case '\x02':
    cVar2 = '\x02';
    break;
  case '\x03':
    if (iVar3 == 0) {
      pp_warn_extra_tokens("#endif");
      return 4;
    }
    iVar3 = iVar3 + -1;
  default:
    goto switchD_1040f1bc_caseD_6;
  case '\b':
    goto switchD_1040f1bc_caseD_8;
  }
  if (iVar3 == 0) {
    if (mode == 6) {
      diag_fatal_simple(0x16);
    }
    if (cVar2 == '\x02') {
      if (g_ms_extensions != '\0') {
        lex_skip_whitespace();
        return 3;
      }
      pp_warn_extra_tokens("#else");
      return 3;
    }
    return 2;
  }
  goto switchD_1040f1bc_caseD_6;
switchD_1040f1bc_caseD_8:
  if (mode == 8) {
    iVar3 = pp_check_expected_endif_pragma_tail(0xb,8,iVar3);
    return iVar3;
  }
  goto switchD_1040f1bc_caseD_6;
}

