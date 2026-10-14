int __cdecl pp_macro_formal_is_pasted(void)

{
  uint local_4;
  
  local_4 = (uint)*g_input_ptr;
  if ((g_char_class[local_4] != '&') && ((g_char_flags[local_4] & 3) == 0)) {
    return 0;
  }
  return 1;
}

