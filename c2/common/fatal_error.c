void __cdecl fatal_error(int id,...)

{
  char *fmt;
  
  _fcloseall();
  fmt = format_message(id + 1000);
  print_diagnostic(1000,id,fmt,&stack0x00000008);
  g_error_count = g_error_count + 1;
  backend_cleanup(0);
  RaiseException(0xe0005032,0xc0000025,1,(ULONG_PTR *)&stack0xfffffffc);
  return;
}

