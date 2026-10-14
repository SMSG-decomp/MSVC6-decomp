char * __cdecl strcat_end(char *dst,char *src)

{
  size_t len;
  
  if (src != (char *)0x0) {
    strcat(dst,src);
  }
  len = strlen(dst);
  return dst + len;
}

