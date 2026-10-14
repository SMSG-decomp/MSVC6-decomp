int __cdecl str_has_prefix(char *prefix,char *s)

{
  char prefix_c;
  char c;
  
  prefix_c = *prefix;
  while( true ) {
    if (prefix_c == '\0') {
      return 1;
    }
    c = *s;
    s = s + 1;
    prefix = prefix + 1;
    if (prefix_c != c) break;
    prefix_c = *prefix;
  }
  return 0;
}

