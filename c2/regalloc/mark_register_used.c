void __fastcall mark_register_used(int regno)

{
  g_reg_symbols[regno].flags5 = g_reg_symbols[regno].flags5 | 0x10;
  return;
}

