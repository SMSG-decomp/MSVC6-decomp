void __cdecl func_body_begin_emit(void)

{
  byte bVar1;
  c1_node *pcVar2;
  c1_node *left;
  c1_sym_link *pcVar3;
  c1_node *right;
  
  g_current_function->flags2 = g_current_function->flags2 | 4;
  g_function_formal_count = 0;
  g_current_function->flags4 = g_current_function->flags4 & 0xef;
  if (g_opt_Zg == '\0') {
    il_begin_function_body(0);
    if (g_ilstore_status != 4) {
      g_function_exit_label = label_new(0x1f);
      il_emit_tuple(0x53,(node *)0x0);
      il_emit_tuple(0x53,(node *)0x0);
      if (((g_current_function->flags1 & 4) == 0) ||
         ((*(byte *)((int)&g_current_function->tail + 8) & 1) == 0)) {
        right = (c1_node *)0x0;
        pcVar2 = tree_new_symbol_ref(g_current_function,'\x01');
      }
      else {
        right = (c1_node *)0x0;
        pcVar2 = expr_build_this((c1_symbol *)0x0);
        left = tree_new_symbol_ref(g_current_function,'\x01');
        pcVar2 = tree_new_binary(0x99,left,pcVar2);
      }
      pcVar2 = tree_new_binary('l',pcVar2,right);
      il_emit_expression_tree(pcVar2);
    }
    if (g_function_parameter_scope == (c1_sym_list *)0x0) {
      pcVar3 = (c1_sym_link *)0x0;
    }
    else {
      pcVar3 = g_function_parameter_scope->head;
    }
    for (; pcVar3 != (c1_sym_link *)0x0; pcVar3 = pcVar3->next) {
      bVar1 = (byte)pcVar3[1].position & 7;
      if (((4 < bVar1) && (bVar1 < 7)) && (g_ilstore_status != 4)) {
        eh_register_local_destructor((c1_symbol *)&pcVar3[-1].position);
      }
      if (((pcVar3->type).type != (c1_type *)0x0) && ((pcVar3->type).type != g_type_void)) {
        g_function_formal_count = g_function_formal_count + 1;
      }
      if (pcVar3 == (c1_sym_link *)0x0) {
        return;
      }
    }
  }
  return;
}

