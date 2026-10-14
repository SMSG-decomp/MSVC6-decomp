fe_message_buffer * __fastcall diag_message_buffer_new(fe_message_buffer *buf)

{
  byte bVar1;
  uchar *puVar2;
  
  puVar2 = g_arenas[6].cur;
  if (g_compile_phase == 3) {
    g_arenas[6].cur = g_arenas[6].cur + 0x800;
    if (g_arenas[6].end < g_arenas[6].cur) {
      arena_grow(g_arenas + 6);
    }
    bVar1 = buf->flags;
    buf->start = (char *)puVar2;
    buf->cur = (char *)puVar2;
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

