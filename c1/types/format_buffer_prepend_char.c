void __cdecl format_buffer_prepend_char(int buf,char c)

{
  char *pcVar1;
  
  pcVar1 = (char *)format_buffer_reserve(buf,0,1);
  *pcVar1 = c;
  return;
}

