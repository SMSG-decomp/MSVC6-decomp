void __cdecl pp_line_after_pch_options(void)

{
  int iVar1;
  byte *token;
  
  iVar1 = pch_read_options();
  if (iVar1 != 1) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
    token = pp_line_directive();
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
    if (*token == 0xf4) {
      pragma_process_saved_tokens(token);
    }
  }
  return;
}

