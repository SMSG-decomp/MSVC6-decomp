uint __cdecl sym_new_local_key(void)

{
  uint uVar1;
  
  if (g_c9il_mode == '\0') {
    if (g_next_local_key < 0x3f0000) {
      diag_error(0x143,g_current_function);
      local_keys_reset();
      return 0;
    }
    uVar1 = g_next_local_key;
    g_next_local_key = g_next_local_key - 1;
    return uVar1;
  }
  if (g_next_entity_id < 0x7fffffff) {
    uVar1 = g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    return uVar1;
  }
  diag_fatal_simple(0x37);
}

