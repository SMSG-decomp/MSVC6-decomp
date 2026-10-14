char * __cdecl strcat_double_percent(char *dst,char *src)

{
  size_t len;
  int rc;
  uchar *end;
  uchar c;
  
  len = strlen(dst);
  end = (uchar *)(dst + len);
  if (src != (char *)0x0) {
    c = *src;
    while (c != '\0') {
      _mbccpy(end,(uchar *)src);
      end = _mbsinc(end);
      rc = _mbsncmp((uchar *)src,(uchar *)"%",1);
      if (rc == 0) {
        _mbccpy(end,(uchar *)src);
        end = _mbsinc(end);
      }
      src = (char *)_mbsinc((uchar *)src);
      c = *src;
    }
    *end = '\0';
  }
  return (char *)end;
}

