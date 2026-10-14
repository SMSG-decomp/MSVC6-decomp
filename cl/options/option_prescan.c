int __cdecl option_prescan(char **argv,int argc,char *name,int *value)

{
  size_t name_len;
  int diff;
  FILE *f;
  char *hit;
  char *hit_2;
  uchar *sep;
  uchar *sep_2;
  uchar *sep_3;
  int found;
  int on;
  int left;
  char line [1024];
  char c_2;
  char c;
  
  found = 0;
  name_len = strlen(name);
  on = 0;
  if (0 < argc) {
    left = argc;
    do {
      c = **argv;
      if (((c == '-') || (c == '/')) && (diff = strncmp(*argv + 1,name,name_len), diff == 0)) {
        c_2 = (*argv)[name_len + 1];
        if (c_2 == '\0') {
          found = 1;
          on = 1;
        }
        else if ((c_2 == '-') && ((*argv)[name_len + 2] == '\0')) {
          on = 0;
          found = 1;
        }
      }
      else if ((**argv == '@') && (f = fopen(*argv + 1,"r"), f != (FILE *)0x0)) {
        hit = fgets(line,0x3ff,f);
        if (hit != (char *)0x0) {
          hit_2 = line;
          while (hit_2 = strstr(hit_2 + 1,name), hit_2 != (char *)0x0) {
            if (((hit_2[-1] == '-') || (hit_2[-1] == '/')) &&
               ((hit_2 == line + 1 ||
                (sep = _mbschr((uchar *)" \t\"",(uint)(byte)hit_2[-2]), sep != (uchar *)0x0)))) {
              if ((hit_2[name_len] == 0) ||
                 (sep_2 = _mbschr((uchar *)" \t\"\n",(uint)(byte)hit_2[name_len]),
                 sep_2 != (uchar *)0x0)) {
                found = 1;
                on = 1;
              }
              else if ((hit_2[name_len] == '-') &&
                      ((hit_2[name_len + 1] == 0 ||
                       (sep_3 = _mbschr((uchar *)" \t\"\n",(uint)(byte)hit_2[name_len + 1]),
                       sep_3 != (uchar *)0x0)))) {
                on = 0;
                found = 1;
              }
            }
          }
        }
        fclose(f);
      }
      argv = argv + 1;
      left = left + -1;
    } while (left != 0);
    if (found != 0) {
      *value = on;
    }
  }
  return found;
}

