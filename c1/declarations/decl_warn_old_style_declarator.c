void __fastcall decl_warn_old_style_declarator(c1_declaration *decl)

{
  c1_type *pcVar1;
  c1_symbol *pcVar2;
  uint *params;
  
  params = decl->declarator->params;
  pcVar1 = decl->declarator->type;
  decl->flags2d = decl->flags2d | 8;
  g_pending_parameter_scope = (c1_scope_symbol_list *)*params;
  g_pending_function_word = params[1];
  if ((pcVar1->flags & 0x4000) == 0) {
    if (g_pending_function_word == 2) {
      pcVar2 = decl->sym;
      if (pcVar2 == (c1_symbol *)0x0) {
        pcVar2 = sym_new_from_declarator(decl,3);
      }
      diag_warning(4,0x83,pcVar2);
      decl->flags2d = decl->flags2d | 0x10;
      return;
    }
  }
  else {
    g_pending_function_word = 5;
  }
  decl->flags2d = decl->flags2d & 0xef;
  return;
}

