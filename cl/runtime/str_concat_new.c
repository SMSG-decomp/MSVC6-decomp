char * __cdecl str_concat_new(char *a,char *b)

{
  size_t a_len;
  size_t b_len;
  char *s;
  
  a_len = strlen(a);
  b_len = strlen(b);
  s = xmalloc(a_len + 1 + b_len);
  strcpy(s,a);
  strcat(s,b);
  return s;
}

