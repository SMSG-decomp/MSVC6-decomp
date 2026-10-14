void __cdecl import_text_printf(c1_il_buffer *buf,char *format,...)

{
  char local_104 [260];
  
  _vsnprintf(local_104,0x100,format,&stack0x0000000c);
  import_text_puts(buf,local_104);
  return;
}

