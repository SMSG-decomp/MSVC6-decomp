void __thiscall diag_message_buffer_append_n(fe_message_buffer *buf,char *s,uint n)

{
  char cVar1;
  
  do {
    if (n <= buf->room) goto LAB_106436e6;
    cVar1 = diag_message_buffer_grow(buf);
    while (cVar1 != '\0') {
LAB_106436e6:
      if (n <= buf->room) {
        strncpy(buf->cur,s,n);
        buf->cur = buf->cur + n;
        buf->room = buf->room - n;
        return;
      }
      cVar1 = diag_message_buffer_grow(buf);
    }
    n = buf->room;
  } while( true );
}

