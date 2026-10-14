void __cdecl init_emit_data(int sym)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  fe_il_buffer *buf;
  
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    buf = &g_il_in;
    pcVar1 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
    init_emit_initializer((c1_symbol *)sym,pcVar1,buf);
    if (sym == 0) {
      g_init_offset = g_init_offset + g_constant_value;
      return;
    }
    return;
  }
  if (sym == 0) {
    init_emit_zero_fill();
    return;
  }
  if (g_static_guard_variable != (c1_symbol *)0x0) {
    pcVar1 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
    pcVar2 = tree_new_symbol_ref(g_static_guard_variable);
    pcVar2 = tree_new_rvalue(pcVar2);
    pcVar1 = expr_build_binary('M',pcVar2,pcVar1);
    init_emit_runtime_element((c1_symbol *)sym,pcVar1);
    g_bitfield_word_needs_reset = 1;
    return;
  }
  pcVar1 = tree_new_constant(g_type_int,(c1_u32 *)&g_constant_value,g_expr_arena_index);
  init_emit_runtime_element((c1_symbol *)sym,pcVar1);
  init_emit_data_fragment();
  return;
}

