c1_node * __cdecl expr_build_this(c1_symbol *this_param)

{
  c1_sym_link *pcVar1;
  char cVar2;
  c1_node *pcVar3;
  
  if ((this_param != (c1_symbol *)0x0) ||
     (((g_function_parameter_scope != (c1_sym_list *)0x0 &&
       (((pcVar1 = g_function_parameter_scope->head, (pcVar1->type).type != g_type_void ||
         ((pcVar1 != (c1_sym_link *)0x0 && (pcVar1 = pcVar1->next, pcVar1 != (c1_sym_link *)0x0))))
        && (this_param = (c1_symbol *)&pcVar1[-1].position, this_param != (c1_symbol *)0x0)))) &&
      (pcVar1->name == g_name_this)))) {
    pcVar3 = tree_new_symbol_ref(this_param,'\0');
    pcVar3 = (c1_node *)expr_build_unary(0xa0,pcVar3);
    pcVar3->type = (c1_type *)
                   **(undefined4 **)
                     (((uint)g_current_function->type &
                      -(uint)((g_current_function->type->code & 0x80) != 0)) + 8);
    cVar2 = decl_check_default_argument_expression(this_param);
    if (cVar2 == '\0') {
      return (c1_node *)0x0;
    }
    pcVar3->kind = pcVar3->kind | 0x20;
    return pcVar3;
  }
  if ((g_current_function->flags1 & 4) == 0) {
    diag_error(0x2a1,g_current_function);
    return (c1_node *)0x0;
  }
  if ((g_current_function->storage & 7) != 3) {
    diag_error(0x2a0,g_current_function);
    return (c1_node *)0x0;
  }
  diag_error(0x29f,g_current_function);
  return (c1_node *)0x0;
}

