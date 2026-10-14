char * __cdecl str_last_of(char *s,char *set)

{
  uchar *hit;
  uchar *last;
  
  last = (uchar *)0x0;
  for (; *set != 0; set = (char *)_mbsinc((uchar *)set)) {
    hit = _mbsrchr((uchar *)s,(uint)(byte)*set);
    if ((hit != (uchar *)0x0) && ((last == (uchar *)0x0 || (last < hit)))) {
      last = hit;
    }
  }
  return (char *)last;
}

