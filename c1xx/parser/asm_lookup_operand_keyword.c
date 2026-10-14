short __cdecl asm_lookup_operand_keyword(fe_name *name)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  int iVar4;
  char **ppcVar5;
  
  pcVar3 = name->text;
  cVar1 = *pcVar3;
  if (cVar1 != '$') {
    iVar4 = tolower((int)cVar1);
    sVar2 = *(short *)((int)g_asm_keyword_names + iVar4 * 2 + 0x94);
    for (ppcVar5 = g_asm_keyword_names + *(short *)((int)g_asm_keyword_names + iVar4 * 2 + 0x92);
        ppcVar5 != g_asm_keyword_names + sVar2; ppcVar5 = ppcVar5 + 1) {
      iVar4 = str_compare_nocase(*ppcVar5,pcVar3 + 1);
      if (iVar4 == 0) {
        return g_asm_keyword_codes[(int)(ppcVar5 + -0x413263a) >> 2].code;
      }
    }
  }
  return -1;
}

