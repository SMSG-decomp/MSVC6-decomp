void __fastcall diag_message_buffer_rewind(fe_message_buffer *buf)

{
  char *pcVar1;
  
  pcVar1 = buf->cur;
  buf->cur = buf->start;
  buf->room = (uint)(pcVar1 + (buf->room - (int)buf->start));
  buf->flags = buf->flags & 0xfd;
  return;
}

