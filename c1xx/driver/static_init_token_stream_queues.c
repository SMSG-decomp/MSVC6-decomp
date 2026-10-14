void __cdecl static_init_token_stream_queues(void)

{
  c1_token_reader *pcVar1;
  int iVar2;
  
  pcVar1 = g_token_stream_queues;
  iVar2 = 10;
  do {
    pcVar1->position = g_lex_position;
    pcVar1->top = (c1_token_source_frame *)0x0;
    pcVar1 = pcVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

