void dynamic_init_token_save_frame(void)

{
  g_token_save_frame = (c1_token_source_frame *)0x0;
  g_token_record_position = g_lex_position;
  return;
}

