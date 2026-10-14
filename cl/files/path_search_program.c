char * __cdecl path_search_program(char *cl_dir,char *name,uint *where)

{
  char *p;
  int rc;
  char *p_2;
  int rc_2;
  int rc_3;
  int rc_4;
  char *p_3;
  char candidate [1024];
  byte dir [256];
  
  _splitpath(name,(char *)0x0,(char *)dir,(char *)0x0,(char *)0x0);
  if ((dir[0] != 0) && (p = strchr("\\/",(uint)dir[0]), p != (char *)0x0)) {
    rc = _access(name,4);
    *where = (uint)(rc == 0);
    p_2 = xstrdup(name);
    return p_2;
  }
  strcpy(candidate,cl_dir);
  strcat(candidate,name);
  rc_2 = _access(candidate,4);
  if (rc_2 == 0) {
    *where = 2;
  }
  else {
    candidate[0] = '.';
    candidate[1] = '\\';
    candidate[2] = '\0';
    strcat(candidate,name);
    rc_3 = _access(candidate,4);
    if (rc_3 == 0) {
      *where = 3;
    }
    else {
      rc_4 = path_search_PATH(name,candidate,0x400);
      if (rc_4 == 0) {
        *where = 0;
        goto LAB_004035f8;
      }
      *where = rc_4 + 3;
    }
  }
  name = candidate;
LAB_004035f8:
  p_3 = xstrdup(name);
  return p_3;
}

