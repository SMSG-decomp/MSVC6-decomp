short * __cdecl pp_macro_formal_argument_text(char *pasted)

{
  int iVar1;
  byte bVar2;
  short *psVar3;
  
  bVar2 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  psVar3 = g_macro_expansion_frames[g_macro_expansion_depth].args;
  if ((char)bVar2 <= g_macro_expansion_frames[g_macro_expansion_depth].arg_count) {
    iVar1 = pp_macro_formal_is_pasted();
    if ((*pasted == '\0') && ((char)iVar1 == '\0')) {
      bVar2 = bVar2 + g_macro_expansion_frames[g_macro_expansion_depth].arg_count;
    }
    *pasted = (char)iVar1;
    if ((byte)(bVar2 - 1) != '\0') {
      iVar1 = (int)(char)(bVar2 - 1);
      do {
        psVar3 = (short *)((int)psVar3 + (int)*psVar3);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    return psVar3 + 1;
  }
  return (short *)0x0;
}

