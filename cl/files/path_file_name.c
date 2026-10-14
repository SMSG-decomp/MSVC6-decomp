char * __cdecl path_file_name(char *out,char *path)

{
  char fname [256];
  char ext [256];
  
  _splitpath(path,(char *)0x0,(char *)0x0,fname,ext);
  _makepath(out,"","",fname,ext);
  return out;
}

