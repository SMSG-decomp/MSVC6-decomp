void __cdecl pch_relocate_line_map(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (g_line_map.count != 0) {
    iVar1 = 0;
    do {
      pch_relocate_slot_once(&g_pch_image,(int)&(g_line_map.rows)->file + iVar1);
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0xc;
    } while (uVar2 < g_line_map.count);
  }
  return;
}

