int __cdecl text_buffers_grow(int count,int *table)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *fill;
  int *piVar5;
  
  if (table == (int *)0x0) {
    g_text_buffers = mem_xmalloc(0x500);
  }
  else {
    g_text_buffers = mem_xrealloc(table,(count * 5 + 0x140) * 4);
  }
  if (g_text_buffers != (int *)0x0) {
    piVar5 = g_text_buffers + g_text_buffer_count * 5;
    for (iVar4 = 0x140; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    iVar4 = g_text_buffer_count + 0x40;
    piVar5 = g_text_buffers + g_text_buffer_count * 5;
    g_text_buffer_count = iVar4;
    if (piVar5[1] == 0) {
      piVar5[4] = 0x80;
      pvVar1 = mem_xmalloc(0x80);
      piVar5[1] = (int)pvVar1;
    }
    *piVar5 = g_format_buffer_next_handle;
    g_format_buffer_next_handle = g_format_buffer_next_handle + 1;
    uVar3 = piVar5[4];
    piVar5[2] = 0x40;
    piVar5[3] = 0x41;
    fill = (uint *)piVar5[1];
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *fill = 0;
      fill = fill + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)fill = 0;
      fill = (uint *)((int)fill + 1);
    }
    return *piVar5;
  }
  diag_fatal_simple(0x3c);
}

