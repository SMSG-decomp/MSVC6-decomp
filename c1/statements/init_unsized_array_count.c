int __cdecl init_unsized_array_count(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (g_init_levels[0].count == 0) {
    iVar2 = 0x1066b928;
    do {
      piVar1 = (int *)(iVar2 + 0x14);
      iVar2 = iVar2 + 0x14;
      iVar3 = iVar3 + 1;
    } while (*piVar1 == 0);
  }
  return g_init_levels[iVar3].count;
}

