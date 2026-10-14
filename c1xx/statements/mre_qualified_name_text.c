char * __cdecl mre_qualified_name_text(byte *sym)

{
  int buf;
  char *pcVar1;
  
  buf = format_buffer_acquire();
  format_options_set(1);
  format_qualified_name(buf,sym);
  pcVar1 = format_buffer_text(buf);
  format_options_clear(1);
  format_buffer_leave();
  return pcVar1;
}

