BOOL DelayLoad_GetFileVersionInfoA(LPSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData)

{
  BOOL extraout_EAX;
  
  delayload_thunk_dispatch();
  return extraout_EAX;
}

