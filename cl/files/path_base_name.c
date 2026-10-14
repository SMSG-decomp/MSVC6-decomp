char * __cdecl path_base_name(char *out,char *path)

{
  _splitpath(path,(char *)0x0,(char *)0x0,out,(char *)0x0);
  return out;
}

