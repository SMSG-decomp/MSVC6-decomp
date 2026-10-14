char * __cdecl format_buffer_text(int handle)

{
  c1_text_buffer *pcVar1;
  
  pcVar1 = format_buffer_find(handle);
  if (pcVar1 != (c1_text_buffer *)0x0) {
    return pcVar1->data + pcVar1->front + 1;
  }
  return (char *)0x0;
}

