void __cdecl init_emit_data(c1_symbol *sym)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_il_buffer *buf;
  c1_u8 *node2;
  
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    buf = &g_il_in;
    pcVar1 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
    init_emit_initializer(sym,pcVar1,buf);
    if (sym == (c1_symbol *)0x0) {
      g_init_offset = g_init_offset + g_constant_value;
      return;
    }
  }
  else {
    if (sym == (c1_symbol *)0x0) {
      init_emit_zero_fill();
      return;
    }
    node2 = (c1_u8 *)0x0;
    if (g_static_guard_variable != (c1_symbol *)0x0) {
      pcVar1 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
      pcVar2 = tree_new_symbol_ref(g_static_guard_variable,'\0');
      pcVar2 = tree_new_rvalue(pcVar2);
      pcVar1 = expr_build_builtin_binary('M',pcVar2,pcVar1);
      init_emit_element_store(sym,pcVar1,node2);
      g_bitfield_word_needs_reset = 1;
      return;
    }
    pcVar1 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
    init_emit_element_store(sym,pcVar1,node2);
  }
  return;
}

