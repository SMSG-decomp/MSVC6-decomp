void text_buffers_free(void)

{
  void *p;
  int *p_00;
  int iVar1;
  int iVar2;
  
  if (g_text_buffers != (int *)0x0) {
    iVar2 = 0;
    p_00 = g_text_buffers;
    if (0 < g_text_buffer_count) {
      iVar1 = 0;
      do {
        p = *(void **)(iVar1 + 4 + (int)p_00);
        if (p != (void *)0x0) {
          mem_free(p);
          p_00 = g_text_buffers;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x14;
      } while (iVar2 < g_text_buffer_count);
    }
    mem_free(p_00);
    g_text_buffers = (int *)0x0;
    g_text_buffer_count = 0;
  }
  return;
}

