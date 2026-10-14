void * __cdecl lex_source_input_ptr(void)

{
  byte *pbVar1;
  
  pbVar1 = g_macro_expansion_frames[1].saved_input;
  if (g_macro_expansion_depth == 0) {
    pbVar1 = g_input_ptr;
  }
  return pbVar1;
}

