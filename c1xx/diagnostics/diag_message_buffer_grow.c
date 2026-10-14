char __fastcall diag_message_buffer_grow(c1_message_buffer *buf)

{
  c1_u8 *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  c1_u32 *pcVar5;
  c1_u32 *dst;
  
  pcVar1 = g_arenas[9].cur;
  if ((buf->flags & 1) != 0) {
    uVar4 = (int)buf->cur - (int)buf->start;
    iVar2 = buf->room + uVar4;
    g_arenas[9].cur = g_arenas[9].cur + (iVar2 * 2 + 3U & 0xfffffffc);
    if (g_arenas[9].end < g_arenas[9].cur) {
      arena_grow(g_arenas + 9);
    }
    pcVar5 = (c1_u32 *)buf->start;
    dst = (c1_u32 *)pcVar1;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *dst = *pcVar5;
      pcVar5 = pcVar5 + 1;
      dst = dst + 1;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)dst = (char)*pcVar5;
      pcVar5 = (c1_u32 *)((int)pcVar5 + 1);
      dst = (c1_u32 *)((int)dst + 1);
    }
    buf->room = buf->room + iVar2;
    buf->start = (char *)pcVar1;
    buf->cur = (char *)(pcVar1 + uVar4);
    return '\x01';
  }
  buf->flags = buf->flags | 2;
  return '\0';
}

