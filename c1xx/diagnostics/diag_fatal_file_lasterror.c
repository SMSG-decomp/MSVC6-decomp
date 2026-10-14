void __cdecl diag_fatal_file_lasterror(int n,int what,char *file)

{
  DWORD err;
  
  err = GetLastError();
  diag_fatal_file(err,n,what,file);
  return;
}

