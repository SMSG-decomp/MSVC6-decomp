void __cdecl init_set_array_dimension(c1_symbol *align_member)

{
  g_constant_value = (align_member->detail).cls;
  g_constant_value_high = (int)g_constant_value >> 0x1f;
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    init_emit_data((c1_symbol *)0x0);
    return;
  }
  g_init_offset = (int)&g_constant_value->size + g_init_offset;
  return;
}

