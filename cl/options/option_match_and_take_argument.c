optrec * __cdecl option_match_and_take_argument(optdesc *desc,char **argv,int *index)

{
  bool bVar1;
  optrec *rec_2;
  optrec *rec;
  int *dash_ok;
  int *next_ok;
  char *p;
  char *pat;
  char *p_2;
  char *arg;
  char value_buf [1024];
  char name [32];
  int optional;
  cl_u8 rec_flags;
  cl_u8 flags;
  char c;
  char *pat_2;
  char c_2;
  char c_3;
  char c_4;
  
  p = name;
  arg = argv[*index] + 1;
  pat = desc->pattern;
  if (*pat != '^') goto LAB_00401334;
  while( true ) {
    pat = pat + 1;
LAB_00401334:
    c = *pat;
    if (((c == '\0') || (c == ':')) || (c == '!')) break;
    if (c != *arg) {
      cl_error(0);
    }
    *p = *arg;
    p = p + 1;
    arg = arg + 1;
  }
  *p = '\0';
  c_2 = *pat;
  if (c_2 == '\0') {
    *index = *index + 1;
    flags = '\0';
    pat_2 = (char *)0x0;
    goto LAB_00401494;
  }
  p_2 = pat + 1;
  dash_ok = (int *)0x1;
  if (c_2 == '!') {
    bVar1 = false;
  }
  else {
    if (c_2 != ':') {
      cl_error(0);
    }
    bVar1 = true;
  }
  flags = 0;
  if (*p_2 == '?') {
    flags = 2;
    p_2 = pat + 2;
    memmove(name + 1,name,0x1f);
    name[0] = *argv[*index];
  }
  if (*p_2 == '>') {
    flags = flags | 0x40;
    p_2 = p_2 + 1;
  }
  c_3 = *p_2;
  if (c_3 == '#') {
    next_ok = (int *)0x0;
  }
  else {
    if (c_3 == '$') {
      dash_ok = (int *)0x0;
    }
    else if (c_3 != '*') {
      next_ok = dash_ok;
      if ((c_3 != '+') && (next_ok = index, dash_ok = index, c_3 == '@')) {
        rec_2 = (optrec *)(*desc->handler)(argv,index);
        return rec_2;
      }
      goto LAB_00401418;
    }
    next_ok = dash_ok;
    dash_ok = (int *)0x0;
  }
LAB_00401418:
  *index = *index + 1;
  if ((next_ok != (int *)0x0) && (*arg == '\0')) {
    arg = argv[*index];
    *index = *index + 1;
  }
  if (((arg == (char *)0x0) || (c_4 = *arg, c_4 == '\0')) ||
     ((dash_ok == (int *)0x0 && ((c_4 == '-' || (c_4 == '/')))))) {
    if (!bVar1) {
      cl_error(0x7d4,name);
    }
    pat_2 = (char *)0x0;
  }
  else {
    pat_2 = value_buf;
    strcpy(value_buf,arg);
  }
  if ((pat_2 != (char *)0x0) && (p_2[1] != '\0')) {
    option_check_numeric_range(name,pat_2,p_2 + 1);
  }
LAB_00401494:
  rec = optrec_new(name,pat_2,(char *)0x0,flags);
  return rec;
}

