int __cdecl path_search_PATH(char *name,char *out,int size)

{
  char c;
  size_t name_len;
  char *p;
  int len_2;
  char *dst;
  int len;
  int entry;
  char c_2;
  
  entry = 0;
  name_len = strlen(name);
  p = getenv("PATH");
  if (p == (char *)0x0) {
LAB_004036a3:
    *out = '\0';
    entry = 0;
  }
  else {
    do {
      do {
        do {
          if (*p == '\0') goto LAB_004036a3;
          for (; (c = *p, c == ' ' || (c == ';')); p = p + 1) {
          }
          if (c == '\0') goto LAB_004036a3;
          entry = entry + 1;
          len = 0;
          dst = out;
          do {
            if (c == ';') break;
            len = len + 1;
            if (len < size) {
              *dst = c;
              dst = dst + 1;
            }
            c = p[1];
            p = p + 1;
          } while (c != '\0');
        } while ((len == 0) || (size <= len));
        c_2 = dst[-1];
        if ((c_2 != '\\') && ((c_2 != ':' && (c_2 != '/')))) {
          len = len + 1;
          *dst = '\\';
          dst = dst + 1;
        }
      } while (size <= (int)(len + name_len));
      strcpy(dst,name);
      len_2 = _access(out,4);
    } while (len_2 != 0);
  }
  return entry;
}

