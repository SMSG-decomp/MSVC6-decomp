void __cdecl opt_T_file_handler(char *sw,char **argv,int *index,int type)

{
  char *name;
  char *p;
  char c;
  int i;
  
  i = *index;
  name = argv[i];
  *index = i + 1;
  c = *sw;
  p = sw;
  while (name = name + 1, c != '\0') {
    p = p + 1;
    c = *p;
  }
  if (*name == '\0') {
    name = argv[i + 1];
    *index = i + 2;
  }
  if ((name != (char *)0x0) && (*name != '\0')) {
    srcfile_append(name,type,1);
    return;
  }
  cl_error(0x7d4,sw);
}

