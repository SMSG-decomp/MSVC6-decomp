void __cdecl diag_message_from_format(ushort *fe_message,char *format,...)

{
  va_list local_4;
  
  local_4 = &stack0x0000000c;
  *(char **)(fe_message + 2) = format;
  *fe_message = 0;
  fe_message[1] = 0;
  diag_message_collect_args((fe_message *)fe_message,&local_4);
  return;
}

