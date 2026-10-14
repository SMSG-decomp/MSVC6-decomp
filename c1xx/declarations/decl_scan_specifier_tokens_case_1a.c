char * __fastcall decl_scan_specifier_tokens_case_1a(int *state)

{
  int iVar1;
  byte *pbVar2;
  c1_u8 *pcVar3;
  char *pcVar4;
  
code_r0x1040702f:
  iVar1 = decl_scan_class_specifier((c1_decl_spec_scan *)state);
LAB_1040707b:
  state[2] = state[2] + 1;
  if (iVar1 != 0) {
    if (iVar1 != 2) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)*state);
      if ((*(short *)((int)state + 0x42) != 0) || (state[0xc] == 0)) {
        decl_check_type_unexpected((int)state);
      }
      pcVar3 = decl_scan_make_specifier_token((c1_decl_spec_scan *)state,'$');
      return (char *)pcVar3;
    }
    return (char *)*state;
  }
  pbVar2 = token_next((c1_token_reader *)&g_token_position);
  *state = (int)pbVar2;
  pbVar2 = (byte *)*state;
  switch(g_token_class[*pbVar2]) {
  default:
decl_check_typename_outside_template:
    iVar1 = 1;
    goto LAB_1040707b;
  case '\x0f':
  case '!':
    decl_specifiers_add_modifier(state,(int)state);
    goto LAB_1040707b;
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
    goto code_r0x1040702f;
  case '\x1e':
    decl_specifier_set_class_type(state);
    goto LAB_1040707b;
  case '\x1f':
    decl_combine_type_specifiers(state);
    goto LAB_1040707b;
  case ' ':
    decl_specifiers_add_storage_class(state,(int)state);
    goto LAB_1040707b;
  case '\"':
    iVar1 = iterator_begin_from_record((c1_decl_spec_scan *)state);
    goto LAB_1040707b;
  case '(':
    iVar1 = decl_specifier_add_qualifier(state,pbVar2);
    goto LAB_1040707b;
  case 0x95:
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar2);
    pbVar2 = lex_compose_qualified_name((char *)0x0,0);
    *state = (int)pbVar2;
    if (*pbVar2 != 0x96) goto decl_check_typename_outside_template;
  case '\x06':
  case 0x96:
    iVar1 = decl_check_type_before_constructor(state);
    goto LAB_1040707b;
  case 0xab:
    *(byte *)((int)state + 0x17) = *(byte *)((int)state + 0x17) | 0x40;
    goto LAB_1040707b;
  case 0xba:
    decl_parse_declspec((byte *)(state + 5),0);
    *(undefined1 *)(state + 0xb) = 1;
    goto LAB_1040707b;
  case 0xe6:
    break;
  }
  if (((((g_compile_flags_c8 & 0x10000000) == 0) && ((g_compile_flags_cc & 0x300000) == 0)) &&
      ((g_compile_flags_c8 & 0x42000000) == 0)) && ((g_compile_flags_cc & 8) == 0)) {
    diag_error(899);
  }
  else if ((g_compile_flags_c8 & 0x10000000) != 0) {
    pcVar4 = decl_scan_specifier_tokens_case_1a(state);
    return pcVar4;
  }
  goto LAB_1040707b;
}

