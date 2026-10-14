void __cdecl format_buffer_append_char(int buf,char c)

{
  char *pcVar1;
  
  pcVar1 = (char *)format_buffer_reserve(buf,1,1);
  *pcVar1 = c;
  return;
}

