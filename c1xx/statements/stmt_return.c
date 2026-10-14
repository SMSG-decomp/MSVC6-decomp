void __cdecl stmt_return(int kind)

{
  c1_node *node;
  byte bVar1;
  byte bVar2;
  uint uStack00000014;
  
  diag_error(0x241,g_member_function_class);
  bVar1 = g_current_function->flags22 & 1;
  if ((bVar1 != 0) && (kind != 0)) {
    diag_error(0x1ea,0x4c,0x7d);
    return;
  }
  bVar2 = (byte)g_function_return_type->code >> 6;
  uStack00000014 = bVar2 & 1;
  if ((bVar2 & 1) == 0) {
    if (((g_ms_extensions == '\0') || ((g_current_function->flags1 & 0x44) != 0)) ||
       (((g_compile_flags_c4 & 0x1000000) == 0 &&
        ((((g_current_function->name->flags & 0x40000000) == 0 ||
          (g_current_function->scope_index != 0)) || ((g_current_function->storage & 7) != 1)))))) {
      if ((kind != 2) && (bVar1 == 0)) {
        if ((g_current_function->flags5 & 0x10) == 0) {
          if (kind == 1) {
            diag_error(0x231,g_current_function);
            expr_condition_guarded((c1_node *)0x0,1);
            return;
          }
          goto LAB_1042984e;
        }
        diag_warning(3,0x23,g_current_function);
      }
      g_compile_flags_c8 = g_compile_flags_c8 | 0x800;
      goto LAB_1042984e;
    }
    if ((g_compile_flags_c8 & 2) == 0) {
      g_compile_flags_c8 = g_compile_flags_c8 | 2;
      g_function_return_type = g_type_void;
      diag_warning(1,0x1fc,g_current_function);
    }
    else {
      diag_error(0x269,g_current_function);
    }
  }
  if (kind == 0) {
    if (g_block_depth == '\x02') {
      func_flow_state_note_8();
      goto LAB_1042999b;
    }
  }
  else {
LAB_1042999b:
    node = expr_condition_guarded((c1_node *)0x0,0);
    kind = 0;
    if (node != (c1_node *)0x0) {
      kind = 0;
      stmt_emit_expression(node);
    }
  }
  il_emit_tuple(0x3a,g_function_exit_label);
LAB_1042984e:
  if (kind != 0) {
    expr_condition_guarded((c1_node *)0x0,1);
  }
  return;
}

