void __fastcall decl_specifiers_add_storage_class(c1_specifier_state *spec)

{
  int unaff_ESI;
  
  if (((byte)g_compile_flags_c8 & 8) == 0) {
    decl_specifiers_merge(&spec->words,(byte)g_tree_op_to_il_op[spec->token->code],'\x01',unaff_ESI)
    ;
    spec->storage_given = '\x01';
    return;
  }
  diag_error(0x2d1,(uint)spec->token->code);
  (spec->words).storage = (spec->words).storage | 8;
  return;
}

