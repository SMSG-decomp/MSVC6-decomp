int __cdecl optrec_matches(optrec *a,optrec *b)

{
  int n;
  int n_3;
  int n_4;
  int n_5;
  size_t sVar1;
  int n_2;
  int iVar2;
  char *t;
  char *s;
  char *s_2;
  char *s_3;
  
  n = strcmp(a->name,"?");
  if (((n != 0) && (n_3 = strcmp(b->name,"?"), n_3 != 0)) &&
     (n_4 = strcmp(a->name,b->name), n_4 != 0)) {
    return 0;
  }
  s_3 = a->value;
  if (s_3 == (char *)0x0) {
    if ((b->value != (char *)0x0) && (n_5 = strcmp(b->value,"?"), n_5 != 0)) {
      return 0;
    }
    return 1;
  }
  if (b->value == (char *)0x0) {
    t = "?";
LAB_00401852:
    iVar2 = strcmp(s_3,t);
  }
  else {
    sVar1 = strlen(s_3);
    n_2 = strlen(b->value);
    if (((int)sVar1 < 1) || (s = a->value, s[sVar1 - 1] != '?')) {
      if ((n_2 < 1) || (s_2 = b->value, s_2[n_2 + -1] != '?')) {
        t = b->value;
        s_3 = a->value;
        goto LAB_00401852;
      }
      s = a->value;
    }
    else {
      s_2 = b->value;
      n_2 = sVar1;
    }
    iVar2 = strncmp(s,s_2,n_2 - 1);
  }
  return (uint)(iVar2 == 0);
}

