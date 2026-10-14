c1_token * __fastcall token_stream_peek_non_marker(c1_saved_token_stream *stream)

{
  int iVar1;
  c1_token_block *pcVar2;
  int iVar3;
  c1_token_block *pcVar4;
  c1_token *pcVar5;
  
  iVar1 = (stream->read).index;
  pcVar2 = (stream->read).block;
  while (pcVar4 = (stream->read).block, (stream->read).index != 0x1f) {
LAB_1062806c:
    if (pcVar4 == (c1_token_block *)0x0) goto LAB_10628096;
    (stream->read).block = pcVar4;
    iVar3 = (stream->read).index;
    pcVar5 = (c1_token *)pcVar4->slot[iVar3];
    (stream->read).index = iVar3 + 1;
    if ((pcVar5 == (c1_token *)0x0) || (pcVar5->code != 0xf2)) goto LAB_10628086;
  }
  if (pcVar4->next != (c1_token_block *)0x0) {
    (stream->read).index = 4;
    pcVar4 = pcVar4->next;
    goto LAB_1062806c;
  }
  (stream->read).index = 0x1f;
LAB_10628096:
  pcVar5 = (c1_token *)0x0;
LAB_10628086:
  (stream->read).block = pcVar2;
  (stream->read).index = iVar1;
  return pcVar5;
}

