char ** __cdecl opt_check_switch_count(void)

{
  char *pcVar1;
  char **ppcVar2;
  char **ppcVar3;
  
  if (g_switch_words != (char **)0x0) {
    pcVar1 = *g_option_argv_cursor;
    ppcVar2 = g_option_argv_cursor;
    while (pcVar1 != (char *)0x0) {
      ppcVar3 = ppcVar2 + 1;
      ppcVar2 = ppcVar2 + 1;
      pcVar1 = *ppcVar3;
    }
    return ppcVar2;
  }
  ppcVar2 = mem_xmalloc(800);
  ppcVar3 = g_option_argv_cursor;
  pcVar1 = *g_option_argv_cursor;
  g_switch_words = ppcVar2;
  *ppcVar2 = pcVar1;
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      g_option_argv_cursor = g_switch_words;
      return ppcVar2;
    }
    ppcVar3 = ppcVar3 + 1;
    ppcVar2 = ppcVar2 + 1;
    if (799 < (int)((int)ppcVar2 - (int)g_switch_words & 0xfffffffcU)) break;
    pcVar1 = *ppcVar3;
    *ppcVar2 = pcVar1;
  }
  diag_fatal(0x4d,200);
}

