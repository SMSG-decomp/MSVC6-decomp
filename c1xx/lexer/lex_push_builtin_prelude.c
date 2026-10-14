void __cdecl lex_push_builtin_prelude(void)

{
  char **ppcVar1;
  char **line;
  
  block_list_open_or_rewind(&g_injected_text_list);
  line = &g_builtin_prelude_lines;
  do {
    pragma_message_text(g_injected_text_list,0x104c6740);
    ppcVar1 = line + 1;
    line = line + 1;
  } while (*ppcVar1 != (char *)0x0);
  lex_push_injected_text(0);
  g_compile_flags_c8 = g_compile_flags_c8 | 0x20000;
  return;
}

