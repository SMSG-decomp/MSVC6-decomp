void __thiscall pch_arena_record_append(void *this,c1_arena *a)

{
  c1_u8 *segment;
  c1xx_pch_stream_reader *pcVar1;
  
  segment = g_arenas[1].cur;
  g_arenas[1].cur = g_arenas[1].cur + 0x4c;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (segment == (c1_u8 *)0x0) {
    pcVar1 = (c1xx_pch_stream_reader *)0x0;
  }
  else {
    pcVar1 = pch_arena_segment_ctor((c1xx_pch_stream_reader *)segment,a,this);
  }
  *(c1xx_pch_stream_reader **)(*(int *)((int)this + 8) + *(int *)((int)this + 0x34) * 4) = pcVar1;
  *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + 1;
  return;
}

