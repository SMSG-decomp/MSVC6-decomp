void __cdecl parse_paren_depth_push(int context)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = g_paren_depth + 1;
  if (0x3b < iVar2) {
    g_paren_depth = iVar2;
    diag_fatal_simple(0xd);
  }
  pbVar1 = g_paren_level_flags + g_paren_depth + 1;
  g_paren_depth = iVar2;
  *pbVar1 = 0;
  if (context == 1) {
    *pbVar1 = *pbVar1 | 0x10;
  }
  else if (context == 2) {
    *pbVar1 = *pbVar1 | 0x40;
    return;
  }
  return;
}

