int __cdecl argv_count(char **v)

{
  int n;
  
  if (v == (char **)0x0) {
    n = 0;
  }
  else {
    n = 0;
    for (; *v != (char *)0x0; v = v + 1) {
      n = n + 1;
    }
  }
  return n;
}

