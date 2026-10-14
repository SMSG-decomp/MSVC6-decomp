void * __cdecl lex_input_base_ptr(void)

{
  byte *pbVar1;
  
  if (g_input_file != (fe_input_file *)0x0) {
    return g_input_file->buffer;
  }
  pbVar1 = g_macro_expansion_frames[1].saved_input;
  if (g_macro_expansion_depth == 0) {
    pbVar1 = g_input_ptr;
  }
  return pbVar1;
}

