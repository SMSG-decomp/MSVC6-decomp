int __cdecl format_vsnprintf(char *buf,char *fmt,int size,char *args)

{
  char cVar1;
  c1_message_buffer local_58;
  int fmt_args [18];
  
  format_args_init((c1_message *)fmt_args,fmt,(int *)&args);
  local_58.cur = buf;
  local_58.start = buf;
  local_58.room = size;
  local_58.flags = local_58.flags & 0xfc;
  diag_format_message((c1_message *)fmt_args,&local_58);
  if ((local_58.room != 0) || (cVar1 = diag_message_buffer_grow(&local_58), cVar1 != '\0')) {
    *local_58.cur = '\0';
    local_58.cur = local_58.cur + 1;
  }
  if ((local_58.flags & 2) != 0) {
    strncpy(local_58.cur + -4,"...",4);
  }
  return (int)(local_58.cur + (-1 - (int)local_58.start));
}

