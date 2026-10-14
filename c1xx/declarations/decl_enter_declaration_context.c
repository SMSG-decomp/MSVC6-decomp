void __fastcall decl_enter_declaration_context(c1_declarator *d)

{
  c1_type *pcVar1;
  uint *context;
  
  context = (uint *)d->decl->params;
  pcVar1 = d->decl->type;
  if (context != (uint *)0x0) {
    d->flags55 = d->flags55 | 8;
    g_pending_parameter_scope = (c1_sym_list *)*context;
    g_pending_function_word = context[4];
    if ((pcVar1->flags & 0x4000) != 0) {
      g_pending_function_word = 5;
    }
  }
  return;
}

