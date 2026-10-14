void __thiscall diag_message_buffer_fill(fe_message_buffer *buf,char c,uint n)

{
  char cVar1;
  
  while ((buf->room < n && (cVar1 = diag_message_buffer_grow(buf), cVar1 == '\0'))) {
    n = buf->room;
  }
  for (; n != 0; n = n - 1) {
    *buf->cur = c;
    buf->cur = buf->cur + 1;
  }
  return;
}

