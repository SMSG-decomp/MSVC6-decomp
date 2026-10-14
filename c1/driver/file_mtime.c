uint __cdecl file_mtime(char *file)

{
  int iVar1;
  _stat stat_buf;
  
  iVar1 = stat(file,&stat_buf);
  return ~-(uint)(iVar1 != 0) & stat_buf.st_mtime;
}

