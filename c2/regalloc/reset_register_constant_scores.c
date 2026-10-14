void reset_register_constant_scores(void)

{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = g_int_register_order;
  uVar2 = 1;
  do {
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
    uVar1 = *puVar3;
    g_reg_symbols[uVar2].u34.refs = 0x1000000;
    uVar2 = uVar1;
  } while (uVar1 != 7);
  puVar3 = g_int_register_order + iVar4;
  uVar2 = g_int_register_order[iVar4];
  while (uVar2 != 0) {
    puVar3 = puVar3 + 1;
    g_reg_symbols[uVar2].u34.refs = 0;
    uVar2 = *puVar3;
  }
  return;
}

