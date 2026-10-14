c1xx_decl_specifiers * __cdecl decl_specifiers_default(void *mods)

{
  c1xx_decl_specifiers *pcVar1;
  byte bVar2;
  int iVar3;
  c1xx_decl_specifiers *pcVar4;
  uint *dst;
  uint mods_copy [6];
  
  iVar3 = g_paren_depth;
  g_paren_level_declspecs[g_paren_depth].type = g_type_int;
  g_paren_level_declspecs[iVar3].spec[0] = g_paren_level_declspecs[iVar3].spec[0] & 0xf8;
  bVar2 = g_paren_level_declspecs[g_paren_depth].spec[0];
  pcVar1 = g_paren_level_declspecs + g_paren_depth;
  pcVar4 = pcVar1;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar4->spec[0] = '\0';
    pcVar4->spec[1] = '\0';
    pcVar4->spec[2] = '\0';
    pcVar4->spec[3] = '\0';
    pcVar4 = (c1xx_decl_specifiers *)(pcVar4->spec + 4);
  }
  pcVar1->spec[0] = (pcVar1->spec[0] ^ bVar2 & 7) & 7 ^ pcVar1->spec[0];
  iVar3 = g_paren_depth;
  pcVar1 = g_paren_level_declspecs + g_paren_depth;
  pcVar1->spec[0] = g_paren_level_declspecs[g_paren_depth].spec[0] | 0x30;
  if (mods != (void *)0x0) {
    dst = mods_copy;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *dst = *(uint *)mods;
      mods = (uint *)((int)mods + 4);
      dst = dst + 1;
    }
    decl_specifiers_merge_modifiers(pcVar1->spec,mods_copy[0]);
    iVar3 = g_paren_depth;
  }
  g_paren_level_flags[iVar3] = g_paren_level_flags[iVar3] | 1;
  return g_paren_level_declspecs + iVar3;
}

