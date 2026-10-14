void __cdecl decl_check_export_linkage(c1_declaration *decl)

{
  byte bVar1;
  c1_symbol *pcVar2;
  char *pcStack00000004;
  int ice_line;
  
  pcVar2 = decl->sym;
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = sym_new_from_declarator(decl,3);
  }
  diag_error(0xc9,pcVar2);
  bVar1 = (decl->spec).declspec;
  (decl->spec).declspec = bVar1 & 0xfb;
  (decl->spec).declspec = bVar1 & 0xf3;
  (decl->spec).storage = (decl->spec).storage | 8;
  if ((((decl->spec).declspec & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
    decl_abstract_declarator_fragment_5(decl);
    return;
  }
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

