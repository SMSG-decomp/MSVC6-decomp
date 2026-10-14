int __fastcall decl_check_tag_specifier(c1_specifier_state *spec)

{
  c1_symbol *sym;
  c1_token *pcVar1;
  c1_type *pcVar2;
  
  g_compile_flags_c4 = g_compile_flags_c4 | 0x80000;
  pcVar1 = decl_new_tag_record((ushort)g_tree_op_to_il_op[spec->token->code],&spec->words);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfff7ffff;
  if (pcVar1 == (c1_token *)0x0) {
    return 0;
  }
  if (pcVar1->code != '\x01') {
    if ((spec->named_type != (c1_type *)0x0) || (spec->basic_type != 0)) {
      diag_error(0xec,0x4c,(uint)spec->token->code,(pcVar1->value).words[4]);
      spec->basic_type = 0;
    }
    sym = (pcVar1->value).spec.named.sym;
    (spec->named).sym = sym;
    spec->tag_insert = (pcVar1->value).spec.tag_insert;
    pcVar2 = sym_type_for_specifier(sym);
    spec->named_type = pcVar2;
    if (pcVar1->code != '\"') {
      if (pcVar1->code != '#') {
        return 0;
      }
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
    }
    decl_parse_pointer_qualifiers(spec);
    if (((spec->words).inlining & 4) != 0) {
      diag_error(0x187,(spec->named).sym);
    }
    pcVar1 = decl_specifier_token(spec,pcVar1->code);
    spec->token = pcVar1;
    return 2;
  }
  pcVar1 = token_next(&g_token_position);
  spec->token = pcVar1;
  pcVar1 = parse_skip_to_token_in_set(pcVar1,0x7f,1);
  spec->token = pcVar1;
  return 2;
}

