BOOL DelayLoad_VerQueryValueA(LPVOID pBlock,LPSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen)

{
  BOOL extraout_EAX;
  
  delayload_thunk_dispatch();
  return extraout_EAX;
}

