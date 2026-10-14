char * __cdecl path_strip_extension(char *out,char *path)

{
  char dir [256];
  char fname [256];
  
  _splitpath(path,(char *)&path,dir,fname,(char *)0x0);
  _makepath(out,(char *)&path,dir,fname,"");
  return out;
}

