void __cdecl pragma_message_indent(int indent,char *file)

{
  char *fmt;
  int size;
  char *pcVar1;
  char local_a68 [1028];
  char local_664 [1636];
  
  if (0x400 < indent) {
    indent = 0x400;
  }
  sprintf(local_a68,"%*c",indent,0x20);
  pcVar1 = local_a68;
  size = 0x664;
  fmt = misc_string_get(0x198);
  format_snprintf(local_664,fmt,size,pcVar1,file);
  diag_write_stderr(local_664);
  return;
}

