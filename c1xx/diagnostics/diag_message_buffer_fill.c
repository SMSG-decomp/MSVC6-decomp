void __thiscall diag_message_buffer_fill(int *buf,char c,uint n)

{
  char cVar1;
  
  while (((uint)buf[1] < n &&
         (cVar1 = diag_message_buffer_grow((c1_message_buffer *)buf), cVar1 == '\0'))) {
    n = buf[1];
  }
  for (; n != 0; n = n - 1) {
    *(char *)*buf = c;
    *buf = *buf + 1;
  }
  return;
}

