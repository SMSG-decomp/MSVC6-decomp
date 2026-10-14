void __cdecl format_buffer_free(int handle)

{
  c1_text_buffer *pcVar1;
  
  pcVar1 = format_buffer_find(handle);
  pcVar1->handle = 0;
  return;
}

