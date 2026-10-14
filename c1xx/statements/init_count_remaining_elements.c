int __cdecl init_count_remaining_elements(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (-1 < g_init_brace_depth) {
    bVar1 = g_init_level->flags;
    while ((bVar1 & 1) == 0) {
      uVar2 = init_partial_array_remainder();
      iVar3 = iVar3 + uVar2;
      init_advance_member();
      bVar1 = g_init_level->flags;
    }
    return iVar3;
  }
  return 0;
}

