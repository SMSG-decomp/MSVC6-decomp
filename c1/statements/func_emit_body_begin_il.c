void func_emit_body_begin_il(void)

{
  byte bVar1;
  c1_node *pcVar2;
  int *piVar3;
  c1_node *right;
  
  g_current_function->flags1 = g_current_function->flags1 | 1;
  g_function_formal_count = 0;
  g_current_function->flags3 = g_current_function->flags3 & 0xef;
  if (g_opt_Zg == '\0') {
    il_begin_function_body(0);
    if (g_ilstore_status != 4) {
      PTR_106692b4 = label_new(0x1f);
      il_emit_tuple(0x53,(c1_node *)0x0);
      il_emit_tuple(0x53,(c1_node *)0x0);
      right = (c1_node *)0x0;
      pcVar2 = tree_new_symbol_ref(g_current_function);
      pcVar2 = tree_new_binary('l',pcVar2,right);
      il_emit_expression_tree(pcVar2);
    }
    if (g_function_parameter_scope == (c1_scope_symbol_list *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = g_function_parameter_scope->first;
    }
    for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
      if (((*(byte *)(piVar3 + -2) & 0x1f) == 0xb) || ((*(byte *)(piVar3 + -2) & 0x1f) == 0xc)) {
        bVar1 = *(byte *)(piVar3 + 6) & 7;
        if ((bVar1 < 5) || (6 < bVar1)) {
          if (bVar1 == 0) {
            *(byte *)(piVar3 + 6) = *(byte *)(piVar3 + 6) & 0xf8 ^ 4;
          }
        }
        else if (g_ilstore_status != 4) {
          func_emit_register_parameter((c1_symbol *)(piVar3 + -2));
        }
        if (((c1_type *)piVar3[3] != (c1_type *)0x0) && ((c1_type *)piVar3[3] != g_type_void)) {
          g_function_formal_count = g_function_formal_count + 1;
        }
      }
      if (piVar3 == (int *)0x0) {
        return;
      }
    }
  }
  return;
}

