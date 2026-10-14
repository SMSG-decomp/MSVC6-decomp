void __cdecl keywords_intern(void)

{
  fe_name *pfVar1;
  void **ppvVar2;
  undefined **ppuVar3;
  void **slot;
  
  ppuVar3 = &g_keyword_table;
  do {
    pfVar1 = name_intern(ppuVar3[1]);
    slot = (void **)*ppuVar3;
    ppuVar3 = ppuVar3 + 2;
    *slot = pfVar1;
  } while (*ppuVar3 != (undefined *)0x0);
  ppvVar2 = &g_name_main;
  ppuVar3 = &g_entry_point_name_slots;
  do {
    ppuVar3 = ppuVar3 + 1;
    *(uint *)((int)*ppvVar2 + 8) = *(uint *)((int)*ppvVar2 + 8) | 0x40000000;
    ppvVar2 = (void **)*ppuVar3;
  } while (ppvVar2 != (void **)0x0);
  return;
}

