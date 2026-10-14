DWORD DelayLoad_GetFileVersionInfoSizeA(LPSTR lptstrFilename,LPDWORD lpdwHandle)

{
  DWORD extraout_EAX;
  
  delayload_thunk_dispatch();
  return extraout_EAX;
}

