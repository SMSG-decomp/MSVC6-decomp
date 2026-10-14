int __fastcall decl_specifier_try_typedef_name(c1_specifier_state *spec)

{
  c1_token *pcVar1;
  
  if ((spec->named_type == (c1_type *)0x0) && (spec->basic_type == 0)) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x400;
    pcVar1 = yylex_classify_identifier(spec->token);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffbff;
    spec->token = pcVar1;
    if (pcVar1->code == '\x1e') {
      decl_specifier_set_type_name(spec);
      return 0;
    }
    return 2 - (uint)(spec->unk08 != 0);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 1;
  return 1;
}

