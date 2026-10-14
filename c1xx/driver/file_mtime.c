uint __cdecl file_mtime(char *file)

{
  int iVar1;
  byte stat_buf [28];
  uint local_8;
  
  iVar1 = stat(file,stat_buf);
  return ~-(uint)(iVar1 != 0) & local_8;
}

