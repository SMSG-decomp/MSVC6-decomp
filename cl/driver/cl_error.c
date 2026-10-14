void __cdecl cl_error(UINT n,...)

{
  char *fmt;
  char *fmt_00;
  UINT shown;
  
  if (n == 0) {
    n = 2000;
  }
  shown = n;
  fmt = load_message(0x12f);
  msg_write(2,fmt,shown);
  fmt_00 = load_message(n);
  msg_write_va(2,fmt_00,&stack0x00000008);
  msg_write(2,"\n");
  cl_exit(2);
}

