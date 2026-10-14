uint32_t fe_symbol_next_id(void)

{
  uint32_t uVar1;
  
  if (g_next_fe_id != 0) {
    uVar1 = g_next_fe_id;
    g_next_fe_id = g_next_fe_id + 1;
    return uVar1;
  }
  fatal_error(0x37);
}

