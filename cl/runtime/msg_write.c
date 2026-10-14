void __cdecl msg_write(int fd,char *fmt,...)

{
  char *text;
  int len;
  
  text = msg_format(&len,fmt,&stack0x0000000c);
  _write(fd,text,len);
  return;
}

