short __cdecl asm_lookup_instruction(fe_name *name)

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
    sVar2 = *(short *)((int)g_asm_mnemonic_names + iVar4 * 2 + 0x648);
    for (ppcVar5 = g_asm_mnemonic_names + *(short *)((int)g_asm_mnemonic_names + iVar4 * 2 + 0x646);
        ppcVar5 != g_asm_mnemonic_names + sVar2; ppcVar5 = ppcVar5 + 1) {
      iVar4 = str_compare_nocase(*ppcVar5,pcVar3 + 1);
      if (iVar4 == 0) {
        return g_asm_mnemonic_codes[(int)(ppcVar5 + -0x4131de5) >> 2].code;
      }
    }
  }
  return -1;
}

