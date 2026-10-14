void __cdecl diag_message_from_format(ushort *msg,char *format,...)

{
  char *args;
  
  args = &stack0x0000000c;
  *(char **)(msg + 2) = format;
  *msg = 0;
  msg[1] = 0;
  diag_message_collect_args(msg,(int *)&args);
  return;
}

