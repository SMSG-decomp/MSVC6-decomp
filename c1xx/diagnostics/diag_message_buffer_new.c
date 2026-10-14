c1_message_buffer * __fastcall diag_message_buffer_new(c1_message_buffer *buf)

{
  byte bVar1;
  c1_u8 *pcVar2;
  
  pcVar2 = g_arenas[9].cur;
  if (g_compile_phase == 3) {
    g_arenas[9].cur = g_arenas[9].cur + 0x800;
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    bVar1 = buf->flags;
    buf->start = (char *)pcVar2;
    buf->cur = (char *)pcVar2;
    buf->flags = bVar1 | 1;
    buf->room = 0x800;
    buf->flags = bVar1 & 0xfd | 1;
    return buf;
  }
  bVar1 = buf->flags;
  buf->start = g_diag_static_buffer;
  buf->cur = g_diag_static_buffer;
  buf->flags = bVar1 & 0xfe;
  buf->room = 0x800;
  buf->flags = bVar1 & 0xfc;
  return buf;
}

