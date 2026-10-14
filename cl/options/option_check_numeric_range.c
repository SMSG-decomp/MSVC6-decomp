void __cdecl option_check_numeric_range(char *name,char *value,char *spec)

{
  ulong n;
  ulong lo;
  ulong hi2;
  ulong hi;
  char *digits;
  int radix;
  char *bracket;
  char *p;
  char c;
  char *p_2;
  
  p_2 = spec;
  radix = 10;
  bracket = spec + 1;
  digits = value;
  if ((*spec == 'x') && (*value == '0')) {
    c = value[1];
    if ((c == 'D') || (((c == 'T' || (c == 'd')) || (c == 't')))) {
      digits = value + 2;
    }
    else {
      radix = 0;
    }
  }
  n = strtoul(digits,&spec,radix);
  if (*spec != '\0') {
    cl_error(0x7e5,name,value);
  }
  p = p_2 + 2;
  if (*bracket == '[') {
    do {
      lo = strtoul(p,&spec,10);
      hi = lo;
      if ((*spec == '-') && (hi2 = strtoul(spec + 1,&spec,10), hi = hi2, hi2 < lo)) {
        hi = lo;
        lo = hi2;
      }
      if ((lo <= n) && (n <= hi)) goto LAB_004012e2;
      p = spec + 1;
    } while (*spec == ',');
    cl_warning(0xfae,n,name,lo);
    uint_to_string(lo,value,10);
  }
  else {
LAB_004012e2:
    uint_to_string(n,value,10);
  }
  return;
}

