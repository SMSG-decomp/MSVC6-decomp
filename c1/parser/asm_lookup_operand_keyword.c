short __cdecl asm_lookup_operand_keyword(void *name)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  undefined **ppuVar5;
  
  pcVar3 = *(char **)((int)name + 4);
  cVar1 = *pcVar3;
  if (cVar1 != '$') {
    iVar4 = tolower((int)cVar1);
    sVar2 = *(short *)((int)&g_asm_keyword_letter_end + iVar4 * 2);
    for (ppuVar5 = &g_asm_keywords + *(short *)(&g_asm_keyword_index_by_char + iVar4 * 2);
        ppuVar5 != &g_asm_keywords + sVar2; ppuVar5 = ppuVar5 + 1) {
      iVar4 = str_compare_nocase(*ppuVar5,pcVar3 + 1);
      if (iVar4 == 0) {
        return *(short *)(&g_asm_keyword_codes + ((int)(ppuVar5 + -0x41966ba) >> 2) * 4);
      }
    }
  }
  return -1;
}

