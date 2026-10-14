c1_token_cursor * __thiscall token_buffer_init(c1_token_cursor *buffer,int arena)

{
  c1_token_block *pcVar1;
  c1_token_block *pcVar2;
  fe_arena *a;
  
  a = g_arenas + arena;
  buffer->index = 4;
  pcVar1 = (c1_token_block *)a->cur;
  pcVar2 = (c1_token_block *)g_arenas[arena].end;
  a->cur = (uchar *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  if (pcVar1 != (c1_token_block *)0x0) {
    pcVar1->next = (c1_token_block *)0x0;
    buffer->block = pcVar1;
    buffer->arena = arena;
    return buffer;
  }
  buffer->arena = arena;
  buffer->block = (c1_token_block *)0x0;
  return buffer;
}

