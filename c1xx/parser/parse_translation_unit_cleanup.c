void __cdecl parse_translation_unit_cleanup(c1_parse_translation_unit_frame *frame)

{
  c1_yy_parser *pcVar1;
  
  pcVar1 = g_yy_parser;
  if (g_yy_parser != (c1_yy_parser *)0x0) {
    parser_stack_destruct();
    __3_YAXPAX_Z(pcVar1);
  }
  g_yy_parser = frame[-1].saved_parser;
  return;
}

