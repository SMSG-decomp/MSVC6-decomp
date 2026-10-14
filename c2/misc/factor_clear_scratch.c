void factor_clear_scratch(void)

{
  int iVar1;
  c2_factor_term **ppcVar2;
  
  ppcVar2 = g_factor_terms;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppcVar2 = (c2_factor_term *)0x0;
    ppcVar2 = ppcVar2 + 1;
  }
  return;
}

