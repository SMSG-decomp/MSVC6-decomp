void __cdecl msg_write_va(int fd,char *fmt,va_list args)

{
  char *text;
  
  text = msg_format((int *)&args,fmt,args);
  _write(fd,text,(uint)args);
  return;
}

