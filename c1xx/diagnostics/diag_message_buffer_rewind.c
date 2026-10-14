void __fastcall diag_message_buffer_rewind(c1_message_buffer *buf)

{
  char *pcVar1;
  
  pcVar1 = buf->cur;
  buf->cur = buf->start;
  buf->room = (c1_u32)(pcVar1 + (buf->room - (int)buf->start));
  buf->flags = buf->flags & 0xfd;
  return;
}

