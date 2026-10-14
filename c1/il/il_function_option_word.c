uint __cdecl il_function_option_word(void)

{
  uint uVar1;
  char **ppcVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0x80000000;
  ppcVar2 = g_option_flag_pointers;
  do {
    if ((*ppcVar2 != (char *)0x0) && (**ppcVar2 != '\0')) {
      uVar1 = uVar1 | uVar3;
    }
    ppcVar2 = ppcVar2 + 1;
    uVar3 = uVar3 >> 1;
  } while ((int)ppcVar2 < 0x1065e510);
  if ((g_current_function != (c1_symbol *)0x0) &&
     (((g_current_function->storage & 0x10) != 0 ||
      ((g_current_function->name->flags >> 0x1e & 1) != 0)))) {
    uVar1 = uVar1 | 0x100;
  }
  return uVar1;
}

