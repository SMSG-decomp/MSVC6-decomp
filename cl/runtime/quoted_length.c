int __cdecl quoted_length(char *s)

{
  byte c;
  int rc;
  int rc_2;
  int rc_3;
  size_t clen;
  int len;
  uint backslashes;
  bool has_space;
  
  len = 0;
  backslashes = 0;
  c = *s;
  has_space = false;
  if (c != 0) {
    do {
      rc = _ismbcspace((uint)c);
      if (rc != 0) {
        has_space = true;
      }
      rc_2 = _mbsncmp((uchar *)s,(uchar *)"\"",1);
      if (rc_2 == 0) {
        len = len + 1 + backslashes;
      }
      rc_3 = _mbsncmp((uchar *)s,(uchar *)"\\",1);
      backslashes = backslashes + 1 & ~-(uint)(rc_3 != 0);
      clen = _mbclen((uchar *)s);
      len = len + clen;
      s = (char *)_mbsinc((uchar *)s);
      c = *s;
    } while (c != 0);
    if (has_space) {
      len = len + 2 + backslashes;
    }
  }
  return len;
}

