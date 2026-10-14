char * __cdecl action_expand_value(char *p,char *out,char *value)

{
  size_t len;
  byte *dst;
  byte *cur;
  byte *ext;
  bool is_end;
  char *alt;
  byte c;
  
  alt = (char *)0x0;
  *out = '\0';
  dst = (byte *)out;
  ext = (byte *)p;
  while (cur = ext, c = *cur, c != 0) {
    ext = cur + 1;
    if (c < 0x3b) {
      if ((c == 0x3a) || (c == 0x21)) break;
      if (c == 0x28) {
        *dst = 0;
        ext = (byte *)action_expand_alternative((char *)cur,(char *)dst,value,&alt);
        len = strlen(out);
LAB_00401660:
        dst = (byte *)(out + len);
      }
      else {
        if (c == 0x29) break;
        if (c != 0x2a) {
          is_end = c == 0x2c;
          goto LAB_00401633;
        }
        *dst = 0;
        if (g_parsing_defaults == 0) {
          dst = (byte *)strcat_double_percent(out,value);
        }
        else {
          dst = (byte *)strcat_end(out,value);
        }
      }
    }
    else {
      if (c == 0x3c) {
        ext = (byte *)path_set_default_extension((char *)ext,out,alt);
        len = strlen(out);
        goto LAB_00401660;
      }
      if (c != 0x40) {
        if (c == 0x5c) {
          *dst = *ext;
          dst = dst + 1;
          ext = cur + 2;
        }
        else {
          is_end = c == 0x7c;
LAB_00401633:
          if (is_end) break;
          *dst = *cur;
          dst = dst + 1;
        }
      }
    }
  }
  *dst = 0;
  return (char *)cur;
}

