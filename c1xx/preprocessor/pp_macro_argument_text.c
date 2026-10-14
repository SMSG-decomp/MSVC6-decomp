short * __cdecl pp_macro_argument_text(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  short *psVar4;
  
  bVar1 = *g_input_ptr;
  psVar4 = g_macro_expansion_frames[g_macro_expansion_depth].args;
  g_input_ptr = g_input_ptr + 1;
  if (g_macro_expansion_frames[g_macro_expansion_depth].arg_count < (char)bVar1) {
    return (short *)0x0;
  }
  cVar3 = bVar1 - 1;
  if (cVar3 != '\0') {
    iVar2 = (int)cVar3;
    do {
      psVar4 = (short *)((int)psVar4 + (int)*psVar4);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return psVar4 + 1;
}

