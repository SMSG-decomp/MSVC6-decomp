int __cdecl file_mtime_of_handle(int fd,int *mtime)

{
  int iVar1;
  char stat_buf [28];
  int local_8;
  
  iVar1 = fstat(fd,stat_buf);
  if (iVar1 == 0) {
    *mtime = local_8;
    return 1;
  }
  return 0;
}

