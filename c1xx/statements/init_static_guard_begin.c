void __cdecl init_static_guard_begin(void)

{
  c1_symbol *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  uint jump_if_true;
  
  g_static_guard_current = &g_static_guard_record;
  if (g_static_guard_record.guard == (c1_symbol *)0x0) {
    g_static_guard_count = g_static_guard_count + 1;
    pcVar1 = decl_new_compiler_variable
                       ((((byte)g_compile_flags_c4 & 0x20) != 0) + 3,g_type_unsigned_char);
    g_static_guard_current->guard = pcVar1;
    g_static_guard_current->mask = '\x01';
  }
  g_static_guard_skip_label = label_new(0x1e);
  g_constant_value = (uint)g_static_guard_current->mask;
  jump_if_true = 1;
  g_constant_value_high = 0;
  pcVar4 = g_static_guard_skip_label;
  pcVar2 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
  pcVar3 = tree_new_symbol_ref(g_static_guard_current->guard,'\0');
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar2 = expr_build_builtin_binary('1',pcVar3,pcVar2);
  stmt_emit_condition(pcVar2,pcVar4,jump_if_true);
  g_constant_value = (uint)g_static_guard_current->mask;
  g_constant_value_high = 0;
  pcVar4 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
  pcVar2 = tree_new_symbol_ref(g_static_guard_current->guard,'\0');
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar4 = expr_build_builtin_binary('N',pcVar2,pcVar4);
  stmt_emit_expression(pcVar4);
  g_static_guard_current->mask = g_static_guard_current->mask << 1;
  if (g_static_guard_current->mask == '\0') {
    g_static_guard_current->guard = (c1_symbol *)0x0;
  }
  return;
}

