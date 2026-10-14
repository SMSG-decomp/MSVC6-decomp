void __cdecl pp_macro_begin_replacement(void)

{
  int iVar1;
  
  g_input_ptr = (g_macro_expansion_frames[g_macro_expansion_depth].macro)->def->text;
  if ((g_ms_extensions == '\0') &&
     (iVar1 = (int)(g_macro_expansion_frames[g_macro_expansion_depth].macro)->def->kind, 0 < iVar1))
  {
    do {
      g_input_ptr = g_input_ptr + *g_input_ptr;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  g_macro_expansion_frames[g_macro_expansion_depth].active = 1;
  return;
}

