int __cdecl format_buffer_acquire(void)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *fill;
  
  g_format_buffer_depth = g_format_buffer_depth + 1;
  iVar1 = 0;
  piVar3 = g_text_buffers;
  if (0 < g_text_buffer_count) {
    while (*piVar3 != 0) {
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 5;
      if (g_text_buffer_count <= iVar1) {
        iVar1 = text_buffers_grow(g_text_buffer_count,g_text_buffers);
        return iVar1;
      }
    }
    if (iVar1 != -1) goto LAB_1061e53f;
  }
  if (g_text_buffers == (int *)0x0) {
    g_text_buffers = mem_xmalloc(0x500);
  }
  else {
    g_text_buffers = mem_xrealloc(g_text_buffers,(g_text_buffer_count * 5 + 0x140) * 4);
  }
  if (g_text_buffers == (int *)0x0) {
    diag_fatal_simple(0x3c);
  }
  piVar3 = g_text_buffers + g_text_buffer_count * 5;
  for (iVar1 = 0x140; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iVar1 = g_text_buffer_count;
  g_text_buffer_count = g_text_buffer_count + 0x40;
LAB_1061e53f:
  piVar3 = g_text_buffers + iVar1 * 5;
  if (piVar3[1] == 0) {
    piVar3[4] = 0x80;
    pvVar2 = mem_xmalloc(0x80);
    piVar3[1] = (int)pvVar2;
  }
  *piVar3 = g_format_buffer_next_handle;
  g_format_buffer_next_handle = g_format_buffer_next_handle + 1;
  uVar5 = piVar3[4];
  piVar3[2] = 0x40;
  piVar3[3] = 0x41;
  fill = (uint *)piVar3[1];
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *fill = 0;
    fill = fill + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)fill = 0;
    fill = (uint *)((int)fill + 1);
  }
  return *piVar3;
}

