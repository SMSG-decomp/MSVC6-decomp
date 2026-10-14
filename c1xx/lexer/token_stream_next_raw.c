int __fastcall token_stream_next_raw(c1xx_token_stream *token_stream)

{
  int iVar1;
  c1xx_token *pcVar2;
  c1_token_chunk *pcVar3;
  
  pcVar3 = (token_stream->read).chunk;
  if ((token_stream->read).index == 0x1f) {
    if (pcVar3->next == (c1_token_chunk *)0x0) {
      (token_stream->read).index = 0x1f;
      return 0;
    }
    (token_stream->read).index = 4;
    pcVar3 = pcVar3->next;
  }
  if (pcVar3 != (c1_token_chunk *)0x0) {
    (token_stream->read).chunk = pcVar3;
    iVar1 = (token_stream->read).index;
    pcVar2 = pcVar3->slots[iVar1];
    (token_stream->read).index = iVar1 + 1;
    return (int)pcVar2;
  }
  return 0;
}

