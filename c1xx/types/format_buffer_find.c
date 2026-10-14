c1_text_buffer * __cdecl format_buffer_find(int handle)

{
  uint uVar1;
  c1_text_buffer *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (g_text_buffer_count < 1) {
    return (c1_text_buffer *)0x0;
  }
  uVar1 = 0;
  do {
    if (g_text_buffers[uVar1 * 5] == handle) {
      return (c1_text_buffer *)(g_text_buffers + (uVar3 & 0xffff) * 5);
    }
    uVar3 = uVar3 + 1;
    uVar1 = uVar3 & 0xffff;
  } while ((int)uVar1 < g_text_buffer_count);
  pcVar2 = (c1_text_buffer *)format_buffer_find_miss();
  return pcVar2;
}

