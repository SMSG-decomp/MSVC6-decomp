int _DllMainCRTStartup_chunk(void *hinst,void *reserved,int reason,int *frame)

{
  int iVar1;
  
  if ((reason == 0) || (reason == 3)) {
    iVar1 = _CRT_INIT(hinst,reason,reserved);
    if (iVar1 == 0) {
      frame[3] = 0;
    }
    if ((frame[3] != 0) && (_pRawDllMain != (code *)0x0)) {
      iVar1 = (*_pRawDllMain)(hinst,reason,reserved);
      frame[3] = iVar1;
    }
  }
  return frame[3];
}

