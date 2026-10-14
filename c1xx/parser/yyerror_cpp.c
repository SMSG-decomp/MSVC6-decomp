void __cdecl yyerror_cpp(char *msg)

{
  byte *tok;
  c1xx_token *pcVar1;
  byte *tok_3;
  byte *tok_4;
  byte *tok_2;
  
  g_flow_analysis_active = g_flow_analysis_active + 1;
  if (-1 < g_class_depth) {
    g_class_syntax_error_count = g_class_syntax_error_count + 1;
  }
  if (*msg == 'y') {
    diag_fatal_simple(0x1a);
  }
  tok = &parse_lookahead_token()->code;
  switch(*tok) {
  case 0:
  case 5:
    diag_fatal_simple(4);
  default:
    tok_2 = &parse_lookahead_token()->code;
    diag_error(0x3b,0x4c,*tok_2);
    break;
  case 6:
    pcVar1 = parse_lookahead_token();
    if (pcVar1->value != (void *)0x0) {
      pcVar1 = parse_lookahead_token();
      diag_error(0x3d,pcVar1->value);
      return;
    }
    break;
  case 0x1e:
  case 0x1f:
  case 0x24:
    pcVar1 = parse_lookahead_token();
    if (pcVar1->type_symbol != (c1_symbol *)0x0) {
      pcVar1 = parse_lookahead_token();
      diag_error(0xe2,pcVar1->type_symbol);
      return;
    }
    pcVar1 = parse_lookahead_token();
    if (((uint)pcVar1->value & 0x10) == 0) {
      pcVar1 = parse_lookahead_token();
      diag_error(0x3e,pcVar1->type_value);
      return;
    }
    pcVar1 = parse_lookahead_token();
    parse_report_specifier_error(0x3b,(c1_u32 *)&pcVar1->value);
    return;
  case 0x96:
    pcVar1 = parse_lookahead_token();
    diag_error(0x141,*(undefined4 *)pcVar1->value);
    return;
  case 0x98:
    pcVar1 = parse_lookahead_token();
    if ((pcVar1->value != (void *)0x0) &&
       (pcVar1 = parse_lookahead_token(), (**(ushort **)((int)pcVar1->value + 4) & 0x800) == 0)) {
      pcVar1 = parse_lookahead_token();
      diag_error(0x275,*(undefined4 *)((int)pcVar1->value + 4));
      return;
    }
    pcVar1 = parse_lookahead_token();
    diag_error(0x3b,0x4c,pcVar1->code);
    return;
  case 0xd9:
    pcVar1 = parse_lookahead_token();
    if (*(int *)(*(int *)pcVar1->value + 8) != 0) {
      pcVar1 = parse_lookahead_token();
      diag_error(0x3d,*(undefined4 *)(*(int *)pcVar1->value + 8));
      return;
    }
    break;
  case 0xe4:
    tok_3 = &parse_lookahead_token()->code;
    if (**(int **)(tok_3 + 8) != 0) {
      tok_4 = &parse_lookahead_token()->code;
      diag_error(0x3d,**(undefined4 **)(tok_4 + 8));
      return;
    }
  }
  return;
}

