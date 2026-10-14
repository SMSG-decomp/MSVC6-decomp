c1_symbol * __cdecl init_begin_variable(c1_symbol *sym)

{
  byte bVar1;
  
  g_init_turned_dynamic = 0;
  if (((g_block_depth == '\0') || (bVar1 = sym->storage & 7, bVar1 < 4)) || (6 < bVar1)) {
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffebffff;
  }
  else {
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffbffff | 0x100000;
  }
  eh_push_array_init_state(sym);
  g_init_symbol = sym;
  g_init_offset = 0;
  g_init_remaining_error = 0;
  g_init_remaining_offset = 0;
  g_init_remaining_count = 0;
  return sym;
}

