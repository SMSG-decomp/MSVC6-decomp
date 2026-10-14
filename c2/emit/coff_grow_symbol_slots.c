void coff_grow_symbol_slots(void)

{
  int iVar1;
  c2_coff_slot **_Memory;
  c2_coff_slot **ppcVar2;
  uint32_t uVar3;
  c2_coff_slot **ppcVar4;
  c2_coff_slot **ppcVar5;
  
  iVar1 = g_coff_symbol_slot_capacity * 2;
  ppcVar2 = malloc((iVar1 + 2) * 4);
  _Memory = g_coff_symbol_slots;
  uVar3 = g_coff_symbol_slot_count;
  ppcVar4 = g_coff_symbol_slots;
  ppcVar5 = ppcVar2;
  if (ppcVar2 == (c2_coff_slot **)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x10e3);
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *ppcVar5 = *ppcVar4;
    ppcVar4 = ppcVar4 + 1;
    ppcVar5 = ppcVar5 + 1;
  }
  free(_Memory);
  g_coff_symbol_slot_capacity = iVar1 + 1;
  g_coff_symbol_slots = ppcVar2;
  return;
}

