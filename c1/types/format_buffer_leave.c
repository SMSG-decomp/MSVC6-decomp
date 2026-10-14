void __cdecl format_buffer_leave(void)

{
  int iVar1;
  int iVar2;
  
  g_format_buffer_depth = g_format_buffer_depth + -1;
  if ((g_format_buffer_depth == 0) && (iVar2 = 0, 0 < g_text_buffer_count)) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar1 + (int)g_text_buffers) = 0;
      iVar1 = iVar1 + 0x14;
    } while (iVar2 < g_text_buffer_count);
  }
  return;
}

