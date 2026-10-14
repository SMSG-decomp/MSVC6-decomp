char * __cdecl path_full(char *out,char *path,size_t n)

{
  uchar *copy;
  uchar *slash;
  uchar *slash_2;
  char *result;
  
  copy = xmalloc(n);
  strcpy((char *)copy,path);
  slash = _mbschr(copy,0x2f);
  while (slash != (uchar *)0x0) {
    *slash = '\\';
    slash_2 = _mbsinc(slash);
    slash = _mbschr(slash_2,0x2f);
  }
  result = _fullpath(out,(char *)copy,n);
  xfree(copy);
  return result;
}

