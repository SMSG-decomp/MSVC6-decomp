uint __cdecl file_mtime_or_zero(int fd)

{
  int iVar1;
  char stat_buf [28];
  uint local_8;
  
  iVar1 = fstat(fd,stat_buf);
  return ~-(uint)(iVar1 != 0) & local_8;
}

