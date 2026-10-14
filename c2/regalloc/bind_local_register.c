c2_register_descriptor * __fastcall bind_local_register(int regno,c2_symbol *temp)

{
  g_register_holders[regno] = temp;
  mark_register_used(regno);
  g_reg_symbols[regno].u34.refs = 0x1000000;
  return g_reg_symbols + regno;
}

