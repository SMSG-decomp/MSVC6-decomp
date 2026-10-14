int _DllMainCRTStartup(void *hinst,int reason,void *reserved)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = reason;
  iVar2 = __proc_attached;
  if (reason != 0) {
    if ((reason != 1) && (reason != 2)) goto LAB_10617d1f;
    if ((_pRawDllMain != (code *)0x0) &&
       (iVar2 = (*_pRawDllMain)(hinst,reason,reserved), iVar2 == 0)) {
      return 0;
    }
    iVar2 = _CRT_INIT(hinst,reason,reserved);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_10617d1f:
  iVar2 = DllMain(hinst,reason,reserved);
  if (reason == 1) {
    if (iVar2 == 0) {
      _CRT_INIT(hinst,0,reserved);
      iVar2 = _DllMainCRTStartup_chunk(hinst,reserved,1,(int *)&stack0xfffffffc);
      return iVar2;
    }
  }
  else if ((reason == 0) || (reason == 3)) {
    iVar3 = _CRT_INIT(hinst,reason,reserved);
    reason = iVar2;
    if (iVar3 == 0) {
      reason = 0;
    }
    iVar2 = reason;
    if ((reason != 0) && (_pRawDllMain != (code *)0x0)) {
      iVar2 = (*_pRawDllMain)(hinst,iVar1,reserved);
    }
  }
  return iVar2;
}

