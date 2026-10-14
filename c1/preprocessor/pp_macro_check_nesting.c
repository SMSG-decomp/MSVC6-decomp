void __cdecl pp_macro_check_nesting(fe_macro *macro)

{
  char cVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar2 = g_macro_arg_start;
  iVar3 = g_macro_expansion_depth + 1;
  g_macro_expansion_depth = iVar3;
  if (iVar3 < 0x100) {
    g_macro_rescan_level = g_macro_rescan_level + 1;
    g_macro_expansion_frames[iVar3].macro = macro;
    cVar1 = (char)g_macro_arg_count;
    g_macro_expansion_frames[iVar3].args = (short *)pbVar2;
    pbVar2 = g_input_ptr;
    g_macro_expansion_frames[iVar3].arg_count = cVar1;
    g_macro_text_cursor = g_macro_expansion_text_start;
    g_macro_expansion_frames[iVar3].next_arg = '\0';
    g_macro_expansion_frames[iVar3].saved_input = pbVar2;
    g_macro_expansion_frames[iVar3].text = g_macro_text_cursor;
    return;
  }
  diag_fatal_simple(9);
}

