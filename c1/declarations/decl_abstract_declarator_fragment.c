void __cdecl decl_abstract_declarator_fragment(c1_declaration *decl)

{
  byte bVar1;
  char *pcStack00000004;
  int ice_line;
  
  bVar1 = (decl->spec).storage & 0xf9;
  (decl->spec).storage = bVar1 | 1;
  (decl->spec).storage = bVar1 | 0x21;
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

