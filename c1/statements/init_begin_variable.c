void __cdecl init_begin_variable(c1_symbol *sym)

{
  byte bVar1;
  
  g_init_runtime_bitfield_allowed = 0;
  if (((g_block_depth == '\0') || (bVar1 = sym->storage & 7, bVar1 < 4)) || (6 < bVar1)) {
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffebffff;
  }
  else {
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffbffff | 0x100000;
  }
  g_init_symbol = sym;
  g_init_offset = 0;
  g_init_pending_flag = '\0';
  g_init_pending_value = 0;
  g_init_pending_value_high = 0;
  return;
}

