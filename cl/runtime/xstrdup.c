char * __cdecl xstrdup(char *s)

{
  char *copy;
  
  if (s == (char *)0x0) {
    return (char *)0x0;
  }
  copy = _strdup(s);
  if (copy == (char *)0x0) {
    cl_error(0);
  }
  return copy;
}

