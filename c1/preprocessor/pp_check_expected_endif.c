int __cdecl pp_check_expected_endif(int group_kind)

{
  c1_u8 cVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    cVar2 = '\v';
    cVar1 = pp_skip_to_directive();
    switch(cVar1) {
    case '\0':
    case '\x04':
    case '\x05':
      iVar3 = iVar3 + 1;
      break;
    case '\x02':
      cVar2 = '\x02';
    case '\x01':
      if (iVar3 == 0) {
        if (group_kind == 6) {
          diag_fatal_simple(0x16);
        }
        if (cVar2 != '\x02') {
          return 2;
        }
        if (g_ms_extensions == '\0') {
          pp_warn_extra_tokens("#else");
          return 3;
        }
        lex_skip_whitespace();
        return 3;
      }
      break;
    case '\x03':
      if (iVar3 == 0) {
        pp_warn_extra_tokens("#endif");
        return 4;
      }
      iVar3 = iVar3 + -1;
      break;
    default:
      break;
    }
  } while( true );
}

