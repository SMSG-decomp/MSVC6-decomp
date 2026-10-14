c1_symbol * __thiscall decl_check_redefinition(c1_declaration *decl,c1_symbol *sym)

{
  char cVar1;
  c1_symbol *pcVar2;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((((g_ms_extensions != '\0') && ((sym->storage & 7) == 7)) && (((decl->spec).storage & 7) == 7)
      ) && (sym->type == decl->type)) {
    return sym;
  }
  if (g_block_depth == '\0') {
    cVar1 = decl_check_redeclaration(decl,sym);
    if (cVar1 == '\0') {
      decl_merge_redeclaration(decl,sym);
      return sym;
    }
  }
  else if (((sym->storage & 7) == 1) && (((decl->spec).storage & 7) == 1)) {
    cVar1 = decl_check_redeclaration(decl,sym);
    if (cVar1 == '\0') {
      return sym;
    }
  }
  else {
    cVar1 = decl_check_redeclaration(decl,sym);
    if (cVar1 == '\0') {
      pcVar2 = decl->sym;
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = sym_new_from_declarator(decl,3);
      }
      diag_error(0x56,pcVar2);
    }
  }
  decl->flags2c = decl->flags2c | 0x40;
  pcVar2 = sym_new_from_declarator(decl,-1);
  return pcVar2;
}

