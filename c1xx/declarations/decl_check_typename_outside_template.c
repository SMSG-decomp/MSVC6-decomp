char * decl_check_typename_outside_template(c1_decl_spec_scan *state)

{
  byte *pbVar1;
  c1_u8 *pcVar2;
  char *pcVar3;
  int iVar4;
  
code_r0x104070c5:
  iVar4 = 1;
LAB_1040707b:
  state->ntokens = state->ntokens + 1;
  if (iVar4 != 0) {
    if (iVar4 != 2) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)state->token);
      if ((state->cv != 0) || (state->named_type == (c1_type *)0x0)) {
        decl_check_type_unexpected((int)state);
      }
      pcVar2 = decl_scan_make_specifier_token(state,'$');
      return (char *)pcVar2;
    }
    return (char *)state->token;
  }
  pbVar1 = token_next((c1_token_reader *)&g_token_position);
  state->token = pbVar1;
  pbVar1 = state->token;
  switch(g_token_class[*pbVar1]) {
  case '\x06':
  case 0x96:
    goto switchD_104070b5_caseD_6;
  default:
    goto code_r0x104070c5;
  case '\x0f':
  case '!':
    decl_specifiers_add_modifier((int *)state,(int)state);
    goto LAB_1040707b;
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
    iVar4 = decl_scan_class_specifier(state);
    goto LAB_1040707b;
  case '\x1e':
    decl_specifier_set_class_type((int *)state);
    goto LAB_1040707b;
  case '\x1f':
    decl_combine_type_specifiers(&state->token);
    goto LAB_1040707b;
  case ' ':
    decl_specifiers_add_storage_class((int *)state,(int)state);
    goto LAB_1040707b;
  case '\"':
    iVar4 = iterator_begin_from_record(state);
    goto LAB_1040707b;
  case '(':
    iVar4 = decl_specifier_add_qualifier(&state->token,pbVar1);
    goto LAB_1040707b;
  case 0x95:
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar1);
    pbVar1 = lex_compose_qualified_name((char *)0x0,0);
    state->token = pbVar1;
    if (*pbVar1 != 0x96) goto code_r0x104070c5;
switchD_104070b5_caseD_6:
    iVar4 = decl_check_type_before_constructor((int *)state);
    goto LAB_1040707b;
  case 0xab:
    state->spec[3] = state->spec[3] | 0x40;
    goto LAB_1040707b;
  case 0xba:
    decl_parse_declspec(state->spec,0);
    state->has_declspec = '\x01';
    goto LAB_1040707b;
  case 0xe6:
    break;
  }
  if (((((g_compile_flags_c8 & 0x10000000) == 0) && ((g_compile_flags_cc & 0x300000) == 0)) &&
      ((g_compile_flags_c8 & 0x42000000) == 0)) && ((g_compile_flags_cc & 8) == 0)) {
    diag_error(899);
  }
  else if ((g_compile_flags_c8 & 0x10000000) != 0) {
    pcVar3 = decl_scan_specifier_tokens_case_1a((int *)state);
    return pcVar3;
  }
  goto LAB_1040707b;
}

