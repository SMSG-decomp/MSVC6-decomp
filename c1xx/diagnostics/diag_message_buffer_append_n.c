void __thiscall diag_message_buffer_append_n(int *buf,char *s,uint n)

{
  char cVar1;
  
  do {
    if (n <= (uint)buf[1]) goto LAB_1048a1be;
    cVar1 = diag_message_buffer_grow((c1_message_buffer *)buf);
    while (cVar1 != '\0') {
LAB_1048a1be:
      if (n <= (uint)buf[1]) {
        strncpy((char *)*buf,s,n);
        *buf = *buf + n;
        buf[1] = buf[1] - n;
        return;
      }
      cVar1 = diag_message_buffer_grow((c1_message_buffer *)buf);
    }
    n = buf[1];
  } while( true );
}

