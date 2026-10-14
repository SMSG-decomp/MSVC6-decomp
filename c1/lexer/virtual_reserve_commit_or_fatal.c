LPVOID __cdecl virtual_reserve_commit_or_fatal(SIZE_T reserve,SIZE_T commit)

{
  LPVOID lpAddress;
  LPVOID pvVar1;
  
  lpAddress = VirtualAlloc((LPVOID)0x0,reserve,0x2000,4);
  if (lpAddress == (LPVOID)0x0) {
    diag_fatal_simple(0x3c);
  }
  pvVar1 = VirtualAlloc(lpAddress,commit,0x1000,4);
  if (pvVar1 != (LPVOID)0x0) {
    return lpAddress;
  }
  diag_fatal_simple(0x3c);
}

