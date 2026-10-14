void __cdecl pp_macro_next_text_segment(void)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  uint local_4;
  
  iVar2 = g_macro_expansion_depth;
  bVar1 = g_macro_expansion_frames[g_macro_expansion_depth].next_arg;
  if (g_macro_expansion_frames[g_macro_expansion_depth].arg_count <= (char)bVar1) {
    pp_macro_begin_replacement();
    return;
  }
  g_macro_expansion_frames[g_macro_expansion_depth].next_arg = bVar1 + 1;
  psVar3 = g_macro_expansion_frames[iVar2].args;
  local_4 = (uint)bVar1;
  if (bVar1 != 0) {
    do {
      psVar3 = (short *)((int)psVar3 + (int)*psVar3);
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  g_input_ptr = (byte *)(psVar3 + 1);
  return;
}

