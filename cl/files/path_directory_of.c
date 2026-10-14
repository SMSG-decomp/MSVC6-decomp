char * __cdecl path_directory_of(char *path)

{
  size_t len;
  char *result;
  char *result_2;
  char fname [256];
  char ext [256];
  char drive [260];
  char dir [256];
  char last;
  
  _splitpath(path,drive,dir,fname,ext);
  len = strlen(dir);
  if ((((0 < (int)len) && (last = drive[len + 0x103], last != '\\')) && (last != ':')) &&
     (last != '/')) {
    dir[len] = '\\';
    dir[len + 1] = '\0';
  }
  result = strcat(drive,dir);
  result_2 = xstrdup(result);
  return result_2;
}

