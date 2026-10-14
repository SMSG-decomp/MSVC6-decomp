char * __cdecl map_file_name(char *out,char *exe)

{
  char *ext;
  char dir [256];
  char ext_buf [256];
  char fname [256];
  char drive [4];
  
  if (g_map_wanted == 0) {
    return "nul.map";
  }
  if (g_Fm_name == (char *)0x0) {
    _splitpath(exe,drive,dir,fname,(char *)0x0);
  }
  else {
    _splitpath(g_Fm_name,drive,dir,fname,ext_buf);
    if (fname[0] == '\0') {
      path_base_name(fname,exe);
    }
    if (ext_buf[0] != '\0') {
      ext = ext_buf;
      goto LAB_00405263;
    }
  }
  ext = s_map;
LAB_00405263:
  _makepath(out,drive,dir,fname,ext);
  return out;
}

