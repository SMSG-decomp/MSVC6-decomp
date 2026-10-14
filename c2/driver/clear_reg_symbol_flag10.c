void clear_reg_symbol_flag10(void)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  
  puVar1 = &g_reg_symbols[0].flags5;
  do {
    puVar2 = puVar1 + 0x54;
    *puVar1 = *puVar1 & 0xef;
    puVar1 = puVar2;
  } while ((int)puVar2 < 0x107adfd1);
  return;
}

