void __fastcall func_warn_must_return_value(char naked,c1_symbol *sym)

{
  if (naked == '\0') {
    diag_warning(1,0x21,sym);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x800;
  }
  il_emit_tuple(0x3a,PTR_106692b4);
  return;
}

