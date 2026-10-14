void __cdecl pp_macro_check_nesting(fe_macro *macro)

{
  int iVar1;
  byte *saved_input_ptr;
  byte *saved_input_ptr_2;
  char saved_arg_count;
  
  saved_input_ptr = g_macro_arg_start;
  iVar1 = g_macro_expansion_depth + 1;
  g_macro_expansion_depth = iVar1;
  if (iVar1 < 0x100) {
    g_macro_rescan_level = g_macro_rescan_level + 1;
    g_macro_expansion_frames[iVar1].macro = macro;
    saved_arg_count = (char)g_macro_arg_count;
    g_macro_expansion_frames[iVar1].args = (short *)saved_input_ptr;
    saved_input_ptr_2 = g_input_ptr;
    g_macro_expansion_frames[iVar1].arg_count = saved_arg_count;
    g_macro_text_cursor = g_macro_expansion_text_start;
    g_macro_expansion_frames[iVar1].next_arg = '\0';
    g_macro_expansion_frames[iVar1].saved_input = saved_input_ptr_2;
    g_macro_expansion_frames[iVar1].text = g_macro_text_cursor;
    return;
  }
  diag_fatal_simple(9);
}

