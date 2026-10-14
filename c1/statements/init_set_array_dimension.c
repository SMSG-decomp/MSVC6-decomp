void __cdecl init_set_array_dimension(c1_symbol *sym)

{
  g_constant_value = sym->detail;
  g_constant_value_high = (int)g_constant_value >> 0x1f;
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    init_emit_data(0);
    return;
  }
  g_init_offset = g_init_offset + (int)g_constant_value;
  return;
}

