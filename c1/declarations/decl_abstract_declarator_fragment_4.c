void __cdecl decl_abstract_declarator_fragment_4(c1_specifier_words *spec,c1_declaration *decl)

{
  byte bVar1;
  c1_symbol *pcVar2;
  char *pcStack00000004;
  int ice_line;
  
  pcVar2 = decl->sym;
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = sym_new_from_declarator(decl,3);
  }
  diag_warning(1,0x2a,pcVar2);
  bVar1 = spec->storage;
  spec->storage = '\0';
  spec->inlining = '\0';
  spec->declspec = '\0';
  spec->allocate = '\0';
  spec->segment = (void *)0x0;
  spec->flags8 = '\0';
  spec->pad09[0] = '\0';
  spec->pad09[1] = '\0';
  spec->pad09[2] = '\0';
  spec->storage = (spec->storage ^ bVar1 & 7) & 7 ^ spec->storage;
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

