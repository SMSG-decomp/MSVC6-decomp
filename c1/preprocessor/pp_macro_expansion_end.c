int __cdecl pp_macro_expansion_end(void)

{
  fe_macro_frame *pfVar1;
  
  g_macro_rescan_level = g_macro_rescan_level + -1;
  if (g_macro_rescan_level != 0) {
    g_input_ptr = g_macro_expansion_frames[g_macro_expansion_depth].saved_input;
    g_macro_arg_cursor = (byte *)g_macro_expansion_frames[g_macro_expansion_depth].args;
    pfVar1 = g_macro_expansion_frames + g_macro_expansion_depth;
    g_macro_expansion_depth = g_macro_expansion_depth + -1;
    pfVar1->active = 0;
    return 0;
  }
  if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
    pp_define_check_size
              ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit)
    ;
  }
  *g_macro_text_cursor = '\0';
  g_macro_text_cursor = g_macro_text_cursor + 1;
  *g_macro_text_cursor = 'R';
  g_macro_text_cursor = g_macro_text_cursor + 1;
  g_input_ptr = g_macro_expansion_frames[g_macro_expansion_depth].text;
  g_macro_text_pending = 1;
  return 1;
}

