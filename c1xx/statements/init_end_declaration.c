void init_end_declaration(c1_symbol *sym)

{
  if (g_init_turned_dynamic != 0) {
    g_constant_value = g_init_offset - g_init_dynamic_offset;
    g_constant_value_high = 0;
    if (g_constant_value == 0) {
      if (g_init_offset == 0) {
        sym->flags4 = sym->flags4 & 0xfb;
      }
    }
    else {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffefffff;
      init_emit_data((c1_symbol *)0x0);
      g_compile_flags_c4 = g_compile_flags_c4 | 0x100000;
      g_init_offset = g_init_offset - g_constant_value;
    }
  }
  if (((((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) &&
      ((sym->storage & 7) == 3)) && ((g_compile_flags_c4 & 0x100000) != 0)) {
    init_end_declaration_static_dtor_fragment(sym);
    return;
  }
  if (PTR_104e0a44 != (c1_node *)0x0) {
    label_emit_definition(PTR_104e0a44);
    PTR_104e0a44 = (c1_node *)0x0;
  }
  g_init_pending_data_symbol = (c1_symbol *)0x0;
  if ((g_compile_flags_cc & 0x4000) != 0) {
    (*g_il_emitter->vtbl->end_block)();
    g_compile_flags_cc = g_compile_flags_cc & 0xffffbfff;
  }
  if (((g_compile_flags_c4 & 0x100000) != 0) && ((g_compile_flags_c4 & 0x40000) == 0)) {
    g_init_declaration_depth = g_init_declaration_depth + -1;
    if (g_eh_array_init_symbol != (c1_symbol *)0x0) {
      g_eh_previous_state = g_eh_array_init_state;
      g_eh_context_kind = g_eh_state_stack->value;
      list_pop_head((int *)&g_eh_state_stack);
      g_eh_array_init_symbol = (c1_symbol *)0x0;
    }
    return;
  }
  il_emit_in_marker();
  eh_pop_array_init_state();
  return;
}

