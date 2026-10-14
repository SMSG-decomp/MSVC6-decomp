char __cdecl lex_fetch_pending_input(void)

{
  int iVar1;
  
  if ((g_opt_Zg == '\0') && (g_current_function == (c1_symbol *)0x0)) {
    iVar1 = lex_end_of_input();
    if (iVar1 != 0) {
      if (iVar1 != 2000) {
        return '\x01';
      }
      diag_fatal_simple(0xca);
    }
  }
  return '\0';
}

