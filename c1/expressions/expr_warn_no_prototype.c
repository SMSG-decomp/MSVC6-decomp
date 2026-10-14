c1_node * __cdecl expr_warn_no_prototype(int level,c1_symbol *sym,c1_node *callee)

{
  c1_node *pcVar1;
  byte bVar2;
  c1_node *right;
  
  diag_error(0x1ea,0x53,sym);
  right = (c1_node *)0x0;
  pcVar1 = tree_new_int_constant((uint)*(ushort *)&sym->detail);
  pcVar1 = tree_new_binary('w',pcVar1,right);
  bVar2 = (byte)level;
  g_call_context->flags = g_call_context->flags | bVar2;
  g_call_context->name = sym->name->text;
  g_call_context->call_depth = g_callee_call_depth;
  if ((sym->name == g_name_setjmp) || (sym->name == g_name_Catch)) {
    if ((g_current_function->flags22 & bVar2) == 0) {
      g_current_function->flags4 = g_current_function->flags4 | 2;
    }
    else {
      diag_error(0x1ea,0x53,sym);
    }
  }
  if (((g_call_context->formal == (c1_type **)0x0) && ((g_call_context->flags & 2) == 0)) &&
     ((sym == (c1_symbol *)0x0 || ((sym->flags3 & bVar2) == 0)))) {
    if ((g_call_context->type->flags & 7) == 3) {
      diag_warning(level,0x48,g_call_context->name,0x26);
    }
    else {
      diag_warning(2,0x47,g_call_context->name);
    }
    if (sym != (c1_symbol *)0x0) {
      sym->flags3 = sym->flags3 | bVar2;
    }
  }
  if (pcVar1 == (c1_node *)0x0) {
    pcVar1 = tree_new_binary('p',callee,(c1_node *)0x0);
  }
  pcVar1->type = g_call_context->type->base;
  return pcVar1;
}

