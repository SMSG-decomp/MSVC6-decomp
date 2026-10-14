int __fastcall decl_specifier_add_qualifier(c1_specifier_state *spec)

{
  c1_u16 cVar1;
  int iVar2;
  
  if ((((byte)g_compile_flags_c8 & 8) != 0) ||
     (((iVar2 = 2, (g_paren_level_flags[g_paren_depth] & 2) == 0 &&
       (((byte)g_compile_flags_c4 & 4) == 0)) || (spec->unk08 != 0)))) {
    cVar1 = type_merge_qualifiers(spec->qualifiers,(c1_u16)g_tree_op_to_il_op[spec->token->code]);
    spec->qualifiers = cVar1;
    iVar2 = 0;
  }
  return iVar2;
}

