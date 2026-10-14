c2_register_descriptor * __fastcall find_register_holding_temp(c2_symbol *temp)

{
  uint32_t uVar1;
  uint32_t *puVar2;
  
  puVar2 = g_local_register_order;
  uVar1 = g_local_register_order[0];
  while( true ) {
    puVar2 = puVar2 + 1;
    if (uVar1 == 0) {
      return g_reg_symbols;
    }
    if (g_register_holders[uVar1] == temp) break;
    uVar1 = *puVar2;
  }
  return g_reg_symbols + uVar1;
}

