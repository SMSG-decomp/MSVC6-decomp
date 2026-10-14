int __cdecl file_mtime_of_handle(int fd,int *mtime)

{
  int iVar1;
  _stat stat_buf;
  
  iVar1 = fstat(fd,&stat_buf);
  if (iVar1 == 0) {
    *mtime = stat_buf.st_mtime;
    return 1;
  }
  return 0;
}

