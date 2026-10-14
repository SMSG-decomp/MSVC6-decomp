c1_node * __cdecl expr_call_begin(c1_node *callee)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  c1_symbol *sym;
  char *pcVar4;
  c1_type *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  
  pcVar6 = (c1_node *)0x0;
  if (callee == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  bVar3 = (byte)callee->type->code;
  if ((bVar3 & 0x83) == 0x81) {
    pcVar5 = type_member_pointer_checked(callee->type);
    callee->type = pcVar5;
  }
  else if ((bVar3 & 0x8f) != 0x86) {
    diag_error(0x40);
    return (c1_node *)0x0;
  }
  expr_push_call_context(callee->type->base);
  cVar1 = (&g_token_class)[callee->op];
  pcVar7 = callee;
  while (cVar1 == '=') {
    pcVar7 = pcVar7->left;
    cVar1 = (&g_token_class)[pcVar7->op];
  }
  sym = expr_lvalue_symbol_counting_calls(pcVar7);
  if (sym == (c1_symbol *)0x0) {
    pcVar4 = misc_string_get(0x17a);
    g_call_context->name = pcVar4;
  }
  else {
    g_call_context->callee = sym;
    if ((sym->kind & 0x1f) == 6) {
      sVar2 = *(short *)&sym->detail;
      if (((((sVar2 == 0xd9) && ((g_compile_flags_c4 & 0x2000000) == 0)) &&
           (g_seh_except_depth == 0)) ||
          ((sVar2 == 0xda && ((g_compile_flags_c4 & 0x2000000) == 0)))) ||
         ((sVar2 == 0xd7 && (g_seh_finally_depth == 0)))) {
        diag_error(0x2c3,sym);
      }
      if ((*(short *)&sym->detail == 0xd8) && ((g_current_function->flags22 & 1) != 0)) {
        pcVar6 = expr_warn_no_prototype(1,sym,callee);
        return pcVar6;
      }
      pcVar7 = (c1_node *)0x0;
      pcVar6 = tree_new_int_constant((uint)*(ushort *)&sym->detail);
      pcVar6 = tree_new_binary('w',pcVar6,pcVar7);
      g_call_context->flags = g_call_context->flags | 1;
    }
    g_call_context->name = sym->name->text;
    g_call_context->call_depth = g_callee_call_depth;
    if ((sym->name == g_name_setjmp) || (sym->name == g_name_Catch)) {
      if ((g_current_function->flags22 & 1) == 0) {
        g_current_function->flags4 = g_current_function->flags4 | 2;
      }
      else {
        diag_error(0x1ea,0x53,sym);
      }
    }
  }
  if (((g_call_context->formal == (c1_type **)0x0) && ((g_call_context->flags & 2) == 0)) &&
     ((sym == (c1_symbol *)0x0 || ((sym->flags3 & 1) == 0)))) {
    if ((g_call_context->type->flags & 7) == 3) {
      diag_warning(1,0x48,g_call_context->name,0x26);
    }
    else {
      diag_warning(2,0x47,g_call_context->name);
    }
    if (sym != (c1_symbol *)0x0) {
      sym->flags3 = sym->flags3 | 1;
    }
  }
  if (pcVar6 == (c1_node *)0x0) {
    pcVar6 = tree_new_binary('p',callee,(c1_node *)0x0);
  }
  pcVar6->type = g_call_context->type->base;
  return pcVar6;
}

