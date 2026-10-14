c1_token * __fastcall token_stream_next_raw(c1_saved_token_stream *stream)

{
  int iVar1;
  c1_token *pcVar2;
  c1_token_block *pcVar3;
  
  pcVar3 = (stream->read).block;
  if ((stream->read).index == 0x1f) {
    if (pcVar3->next == (c1_token_block *)0x0) {
      (stream->read).index = 0x1f;
      return (c1_token *)0x0;
    }
    (stream->read).index = 4;
    pcVar3 = pcVar3->next;
  }
  if (pcVar3 != (c1_token_block *)0x0) {
    (stream->read).block = pcVar3;
    iVar1 = (stream->read).index;
    pcVar2 = (c1_token *)pcVar3->slot[iVar1];
    (stream->read).index = iVar1 + 1;
    return pcVar2;
  }
  return (c1_token *)0x0;
}

