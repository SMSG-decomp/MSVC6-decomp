char * __cdecl strcpy_end(char *dst,char *src)

{
  size_t len;
  
  if (src != (char *)0x0) {
    strcpy(dst,src);
  }
  len = strlen(dst);
  return dst + len;
}

