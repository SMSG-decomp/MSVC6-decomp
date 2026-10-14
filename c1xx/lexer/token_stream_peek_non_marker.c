char * __fastcall token_stream_peek_non_marker(c1xx_token_stream *token_stream)

{
  int iVar1;
  c1_token_chunk *pcVar2;
  int iVar3;
  c1_token_chunk *pcVar4;
  c1xx_token *pcVar5;
  
  iVar1 = (token_stream->read).index;
  pcVar2 = (token_stream->read).chunk;
  while (pcVar4 = (token_stream->read).chunk, (token_stream->read).index != 0x1f) {
LAB_10425260:
    if (pcVar4 == (c1_token_chunk *)0x0) goto LAB_1045bbdf;
    (token_stream->read).chunk = pcVar4;
    iVar3 = (token_stream->read).index;
    pcVar5 = pcVar4->slots[iVar3];
    (token_stream->read).index = iVar3 + 1;
    if ((pcVar5 == (c1xx_token *)0x0) || (pcVar5->code != 0xf2)) goto LAB_1042527e;
  }
  if (pcVar4->next != (c1_token_chunk *)0x0) {
    (token_stream->read).index = 4;
    pcVar4 = pcVar4->next;
    goto LAB_10425260;
  }
  (token_stream->read).index = 0x1f;
LAB_1045bbdf:
  pcVar5 = (c1xx_token *)0x0;
LAB_1042527e:
  (token_stream->read).chunk = pcVar2;
  (token_stream->read).index = iVar1;
  return (char *)pcVar5;
}

