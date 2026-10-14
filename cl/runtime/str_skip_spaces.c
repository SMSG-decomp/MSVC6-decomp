char * __cdecl str_skip_spaces(char *s)

{
  int space;
  
  while( true ) {
    if (*s == 0) {
      return (char *)(byte *)s;
    }
    space = _ismbcspace((uint)(byte)*s);
    if (space == 0) break;
    s = (char *)_mbsinc((uchar *)s);
  }
  return (char *)(byte *)s;
}

