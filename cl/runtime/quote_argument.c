char * __cdecl quote_argument(char *out,char *s)

{
  char *pcVar1;
  int rc;
  int rc_2;
  uchar *dst;
  int rc_3;
  byte *in;
  uchar *dst_2;
  char *copies;
  bool has_space;
  
  in = (byte *)s;
  has_space = false;
  s = (char *)0x0;
  dst = (uchar *)out;
  if (*in != '\0') {
    do {
      rc = _ismbcspace((uint)*in);
      if (rc != 0) {
        has_space = true;
      }
      rc_2 = _mbsncmp(in,(uchar *)"\"",1);
      pcVar1 = s;
      if ((rc_2 == 0) && (pcVar1 = s + -1, -1 < (int)s)) {
        copies = s + 1;
        s = s + -1;
        do {
          _mbccpy(dst,(uchar *)"\\");
          dst = _mbsinc(dst);
          copies = copies + -1;
          s = s + -1;
          pcVar1 = s;
        } while (copies != (char *)0x0);
      }
      s = pcVar1;
      rc_3 = _mbsncmp(in,(uchar *)"\\",1);
      s = (char *)(~-(uint)(rc_3 != 0) & (uint)(s + 1));
      _mbccpy(dst,in);
      dst = _mbsinc(dst);
      in = _mbsinc(in);
    } while (*in != 0);
    if (has_space) {
      memmove(out + 1,out,(int)dst - (int)out);
      _mbccpy((uchar *)out,(uchar *)"\"");
      dst_2 = _mbsinc(dst);
      if (0 < (int)s) {
        do {
          _mbccpy(dst_2,(uchar *)"\\");
          dst_2 = _mbsinc(dst_2);
          s = s + -1;
        } while (s != (char *)0x0);
      }
      _mbccpy(dst_2,(uchar *)"\"");
      dst = _mbsinc(dst_2);
    }
  }
  *dst = '\0';
  return out;
}

