c1_symbol * __thiscall decl_check_old_style_formal(c1_declaration *decl,c1_decl_specifiers *spec)

{
  c1_scope_lookup *found;
  c1_symbol *pcVar1;
  
  found = scope_stack_lookup(g_current_scope,(int)decl->name);
  if (found == (c1_scope_lookup *)0x0) {
    pcVar1 = (c1_symbol *)0x0;
  }
  else {
    pcVar1 = found->sym;
  }
  if (pcVar1 == (c1_symbol *)0x0) {
    diag_error(0x55,decl->name);
    return (c1_symbol *)0x0;
  }
  if ((pcVar1->storage & 7) != 0) {
    diag_error(0x52,decl->name);
    return (c1_symbol *)0x0;
  }
  decl->context = 5;
  decl_abstract_declarator(decl);
  if ((decl->type->code & 0xfff) != 0x26) {
    pcVar1->type = decl->type;
    return pcVar1;
  }
  pcVar1->type = g_type_double;
  return pcVar1;
}

