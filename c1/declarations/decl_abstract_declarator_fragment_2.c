void __cdecl decl_abstract_declarator_fragment_2(c1_u8 class_bits,c1_declaration *decl)

{
  byte bVar1;
  char *pcStack00000004;
  int ice_line;
  
  diag_extension_warning_or_error(0xcd,0x10b,decl->sym);
  bVar1 = (decl->spec).storage & 0xf9 | 1;
  (decl->spec).storage = bVar1;
  (decl->spec).storage = bVar1 | class_bits;
  if (decl->type != (c1_type *)0x0) {
    return;
  }
  pcStack00000004 = ".\\typesym.c";
  diag_fatal(1);
}

