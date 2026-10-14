void __thiscall token_stream_append(c1xx_token_stream *this,int token)

{
  int iVar1;
  c1_token_chunk *pcVar2;
  c1_token_chunk *pcVar3;
  c1_arena *a;
  c1_token_chunk *pcVar4;
  
  iVar1 = (this->write).arena;
  pcVar4 = (this->write).chunk;
  if ((this->write).index == 0x1f) {
    if (pcVar4->next == (c1_token_chunk *)0x0) {
      if (iVar1 == 10) {
        (this->write).index = 0x1f;
        pcVar4 = (c1_token_chunk *)0x0;
      }
      else {
        a = g_arenas + iVar1;
        pcVar2 = (c1_token_chunk *)a->cur;
        pcVar3 = (c1_token_chunk *)g_arenas[iVar1].end;
        a->cur = (c1_u8 *)(pcVar2 + 1);
        if (pcVar3 < pcVar2 + 1) {
          arena_grow(a);
        }
        if (pcVar2 == (c1_token_chunk *)0x0) {
          pcVar4->next = (c1_token_chunk *)0x0;
          (this->write).index = 4;
          pcVar4 = pcVar4->next;
        }
        else {
          pcVar2->next = (c1_token_chunk *)0x0;
          pcVar4->next = pcVar2;
          (this->write).index = 4;
          pcVar4 = pcVar4->next;
        }
      }
    }
    else {
      (this->write).index = 4;
      pcVar4 = pcVar4->next;
    }
  }
  (this->write).chunk = pcVar4;
  pcVar4->slots[(this->write).index] = (c1xx_token *)token;
  (this->write).index = (this->write).index + 1;
  return;
}

