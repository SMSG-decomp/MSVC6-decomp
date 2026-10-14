void __cdecl decl_abstract_declarator_fragment_5(c1_declaration *decl)

{
  c1_symbol *pcVar1;
  char *pcStack00000004;
  int ice_line;
  
  if (((decl->spec).storage & 7) != 1) {
    pcVar1 = decl->sym;
    if (pcVar1 == (c1_symbol *)0x0) {
      pcVar1 = sym_new_from_declarator(decl,3);
    }
    diag_error(0x47,pcVar1);
  }
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

