int __cdecl init_unsized_array_count(void)

{
  int *piVar1;
  int *entry;
  int iVar2;
  
  iVar2 = 0;
  if (g_init_levels[0].count == 0) {
    entry = &g_init_levels[0].count;
    do {
      piVar1 = entry + 6;
      entry = entry + 6;
      iVar2 = iVar2 + 1;
    } while (*piVar1 == 0);
  }
  return g_init_levels[iVar2].count;
}

