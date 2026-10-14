void __cdecl decl_abstract_declarator_fragment_3(c1_declaration *decl)

{
  char *pcStack00000004;
  int ice_line;
  
  (decl->spec).storage = (decl->spec).storage & 0xf9 | 1;
  if (((decl->spec).storage & 7) == 3) {
    if (((decl->spec).declspec & 0xc) != 0) {
      decl_check_export_linkage(decl);
      return;
    }
  }
  else if ((((decl->spec).declspec & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
    decl_abstract_declarator_fragment_5(decl);
    return;
  }
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

