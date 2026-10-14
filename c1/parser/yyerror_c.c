void __cdecl yyerror_c(char *message)

{
  c1_token *pcVar1;
  
  if ((g_compile_flags_c8 & 0x200) == 0) {
    if (*message == 'y') {
      diag_fatal_simple(0x1a);
    }
    pcVar1 = yy_lookahead_token();
    switch((&g_token_class)[pcVar1->code]) {
    case 0:
    case 5:
      diag_fatal_simple(4);
    default:
      pcVar1 = yy_lookahead_token();
      diag_error(0x3b,0x4c,pcVar1->code);
      break;
    case 6:
      pcVar1 = yy_lookahead_token();
      if ((pcVar1->value).ptr != (void *)0x0) {
        pcVar1 = yy_lookahead_token();
        diag_error(0x3d,(pcVar1->value).ptr);
        return;
      }
      diag_error(0x84);
      return;
    case 0x1f:
      pcVar1 = yy_lookahead_token();
      if ((pcVar1->value).words[4] != 0) {
        pcVar1 = yy_lookahead_token();
        diag_error(0xe2,(pcVar1->value).words[4]);
        return;
      }
      pcVar1 = yy_lookahead_token();
      diag_error(0x3e,(pcVar1->value).spec.type);
      return;
    }
  }
  return;
}

