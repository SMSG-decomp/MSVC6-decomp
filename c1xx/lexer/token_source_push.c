void __thiscall
token_source_push(c1_token_reader *reader,c1xx_token_stream *owner,int arena,int kind,void *on_pop,
                 int *restore_position)

{
  c1_token_source_frame *pcVar1;
  c1_token_source_frame *pcVar2;
  c1_arena *a;
  
  if (arena == 10) {
    arena = owner->arena;
  }
  a = g_arenas + arena;
  pcVar1 = (c1_token_source_frame *)a->cur;
  pcVar2 = (c1_token_source_frame *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  if (pcVar1 != (c1_token_source_frame *)0x0) {
    pcVar1->prev = reader->top;
    pcVar1->stream = owner;
    pcVar1->position = *restore_position;
    pcVar1->kind = kind;
    pcVar1->on_pop = on_pop;
    reader->top = pcVar1;
    g_token_position = owner->start_position;
    return;
  }
  reader->top = (c1_token_source_frame *)0x0;
  g_token_position = owner->start_position;
  return;
}

