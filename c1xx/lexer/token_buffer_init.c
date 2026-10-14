void * __thiscall token_buffer_init(c1xx_token_cursor *cursor,int arena)

{
  c1_token_chunk *pcVar1;
  c1_token_chunk *pcVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  cursor->index = 4;
  pcVar1 = (c1_token_chunk *)a->cur;
  pcVar2 = (c1_token_chunk *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  if (pcVar1 != (c1_token_chunk *)0x0) {
    pcVar1->next = (c1_token_chunk *)0x0;
    cursor->chunk = pcVar1;
    cursor->arena = arena;
    return cursor;
  }
  cursor->arena = arena;
  cursor->chunk = (c1_token_chunk *)0x0;
  return cursor;
}

