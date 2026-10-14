void __cdecl file_printf(FILE *f,char *fmt,...)

{
  char *text;
  int len;
  
  text = msg_format(&len,fmt,&stack0x0000000c);
  if (f != (FILE *)0x0) {
    _write(f->_file,text,len);
  }
  if (g_show_commands != 0) {
    _write(2,text,len);
  }
  return;
}

