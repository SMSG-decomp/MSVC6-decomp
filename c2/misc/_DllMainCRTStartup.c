int _DllMainCRTStartup(void *hinst,int reason,void *reserved)

{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  
  iVar1 = reason;
  iVar3 = __proc_attached;
  if (reason != 0) {
    if ((reason != 1) && (reason != 2)) goto LAB_10750020;
    if ((_pRawDllMain != (code *)0x0) &&
       (iVar3 = (*_pRawDllMain)(hinst,reason,reserved), iVar3 == 0)) {
      return 0;
    }
    iVar3 = crt_init(hinst,reason,reserved);
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_10750020:
  uVar2 = DllMain(hinst,reason,reserved);
  if (reason == 1) {
    if (uVar2 != 0) {
      return uVar2;
    }
    crt_init(hinst,0,reserved);
  }
  if ((reason == 0) || (reason == 3)) {
    iVar3 = crt_init(hinst,reason,reserved);
    reason = uVar2;
    if (iVar3 == 0) {
      reason = 0;
    }
    uVar2 = reason;
    if ((reason != 0) && (_pRawDllMain != (code *)0x0)) {
      uVar2 = (*_pRawDllMain)(hinst,iVar1,reserved);
    }
  }
  return uVar2;
}

