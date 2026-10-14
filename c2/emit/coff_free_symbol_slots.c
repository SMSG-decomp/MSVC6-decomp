void coff_free_symbol_slots(void)

{
  if (g_coff_symbol_slots != (c2_coff_slot **)0x0) {
    free(g_coff_symbol_slots);
  }
  return;
}

