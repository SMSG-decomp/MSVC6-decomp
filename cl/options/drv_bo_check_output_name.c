void __cdecl drv_bo_check_output_name(optrec *r)

{
  byte *pbVar1;
  uchar *sw;
  uchar *p;
  byte *next;
  byte *cur;
  byte *next_2;
  uchar *p_2;
  uchar *p_3;
  byte *name;
  byte *last;
  
  if (*r->value != '\0') {
    if (1 < g_compilable_files) {
      sw = _mbschr((uchar *)r->value,0x20);
      p = _mbschr(sw + 1,0x20);
      *p = '\0';
      name = p + 1;
      next = _mbsinc(name);
      pbVar1 = next;
      last = name;
      while ((cur = pbVar1, cur != (byte *)0x0 && (*cur != 0))) {
        next_2 = _mbsinc(cur);
        last = cur;
        pbVar1 = next_2;
      }
      p_2 = _mbsstr(name,(uchar *)"%b");
      if (p_2 == (uchar *)0x0) {
        p_3 = _mbschr((uchar *)"\\/",(uint)*last);
        if (p_3 == (uchar *)0x0) {
          cl_error(0x7f4,sw + 1,name);
        }
      }
    }
    *r->value = '\0';
  }
  return;
}

