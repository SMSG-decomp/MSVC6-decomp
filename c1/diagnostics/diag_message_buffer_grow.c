char __fastcall diag_message_buffer_grow(fe_message_buffer *buf)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *dst;
  
  puVar1 = g_arenas[6].cur;
  if ((buf->flags & 1) != 0) {
    uVar4 = (int)buf->cur - (int)buf->start;
    iVar2 = buf->room + uVar4;
    g_arenas[6].cur = g_arenas[6].cur + (iVar2 * 2 + 3U & 0xfffffffc);
    if (g_arenas[6].end < g_arenas[6].cur) {
      arena_grow(g_arenas + 6);
    }
    puVar5 = (uint *)buf->start;
    dst = (uint *)puVar1;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *dst = *puVar5;
      puVar5 = puVar5 + 1;
      dst = dst + 1;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)dst = (char)*puVar5;
      puVar5 = (uint *)((int)puVar5 + 1);
      dst = (uint *)((int)dst + 1);
    }
    buf->room = buf->room + iVar2;
    buf->start = (char *)puVar1;
    buf->cur = (char *)(puVar1 + uVar4);
    return '\x01';
  }
  buf->flags = buf->flags | 2;
  return '\0';
}

