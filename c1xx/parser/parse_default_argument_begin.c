void __cdecl parse_default_argument_begin(c1_type *param_type)

{
  char cVar1;
  c1xx_token *token;
  byte bVar2;
  
  lex_record_paren_run((char *)0x0);
  g_compile_flags_c4 = g_compile_flags_c4 | 0x8000008;
  if (param_type != (c1_type *)0x0) {
    bVar2 = (byte)param_type->code;
    if (((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) {
      param_type = type_base(param_type);
    }
    if ((((param_type->code & 0x200) != 0) && ((param_type->extra).cls != (c1_symbol *)0x0)) &&
       ((((((param_type->extra).cls)->detail).cls)->flags3e >> 2 & 1) != 0)) goto LAB_1041ccfa;
  }
  cVar1 = parse_default_argument_needs_saving();
  if (cVar1 == '\0') {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xf7ffffff;
    g_compile_flags_cc = g_compile_flags_cc | 0x10;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    return;
  }
LAB_1041ccfa:
  token = parse_save_default_argument_tokens();
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  return;
}

