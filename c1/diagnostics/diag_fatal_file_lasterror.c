void __cdecl diag_fatal_file_lasterror(int n)

{
  DWORD err;
  
  err = GetLastError();
  diag_fatal_file(err,n);
  return;
}

