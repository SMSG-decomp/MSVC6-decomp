void dynamic_init_token_position(void)

{
  g_token_source = (c1_token_source_frame *)0x0;
  g_token_position = g_lex_position;
  return;
}

