void __thiscall token_stream_append(c1_saved_token_stream *stream,c1_token *token)

{
  int iVar1;
  c1_token_block *pcVar2;
  c1_token_block *pcVar3;
  c1_token_block *pcVar4;
  fe_arena *a;
  
  iVar1 = (stream->write).arena;
  pcVar4 = (stream->write).block;
  if ((stream->write).index == 0x1f) {
    if (pcVar4->next == (c1_token_block *)0x0) {
      if (iVar1 == 7) {
        (stream->write).index = 0x1f;
        pcVar4 = (c1_token_block *)0x0;
      }
      else {
        a = g_arenas + iVar1;
        pcVar2 = (c1_token_block *)a->cur;
        pcVar3 = (c1_token_block *)g_arenas[iVar1].end;
        a->cur = (uchar *)(pcVar2 + 1);
        if (pcVar3 < pcVar2 + 1) {
          arena_grow(a);
        }
        if (pcVar2 == (c1_token_block *)0x0) {
          pcVar4->next = (c1_token_block *)0x0;
          (stream->write).index = 4;
          pcVar4 = pcVar4->next;
        }
        else {
          pcVar2->next = (c1_token_block *)0x0;
          pcVar4->next = pcVar2;
          (stream->write).index = 4;
          pcVar4 = pcVar4->next;
        }
      }
    }
    else {
      (stream->write).index = 4;
      pcVar4 = pcVar4->next;
    }
  }
  (stream->write).block = pcVar4;
  pcVar4->slot[(stream->write).index] = &token->code;
  (stream->write).index = (stream->write).index + 1;
  return;
}

