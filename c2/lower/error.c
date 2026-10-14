void __cdecl error(int id)

{
  char *fmt;
  
  fmt = format_message(id + 2000);
  print_diagnostic(2000,id,fmt,&stack0x00000008);
  g_error_count = g_error_count + 1;
  if (100 < g_error_count) {
    fatal_error(3,100);
  }
  return;
}

