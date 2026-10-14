int * __cdecl format_buffer_find(int handle)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (0 < g_text_buffer_count) {
    uVar1 = 0;
    do {
      if (g_text_buffers[uVar1 * 5] == handle) {
        return g_text_buffers + (uVar2 & 0xffff) * 5;
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar2 & 0xffff;
    } while ((int)uVar1 < g_text_buffer_count);
  }
  return (int *)0x0;
}

