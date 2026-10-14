uint __cdecl file_mtime_or_zero(int fd)

{
  int iVar1;
  _stat stat_buf;
  
  iVar1 = fstat(fd,&stat_buf);
  return ~-(uint)(iVar1 != 0) & stat_buf.st_mtime;
}

