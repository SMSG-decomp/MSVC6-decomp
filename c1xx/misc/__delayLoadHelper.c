void * __delayLoadHelper(void *pidd,void **ppfnIATEntry)

{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  HMODULE hLibModule;
  HMODULE pHVar4;
  undefined4 *puVar5;
  int *piVar6;
  FARPROC pFVar7;
  void *local_28;
  void *local_24;
  void **local_20;
  LPCSTR local_1c;
  int local_18;
  LPCSTR local_14;
  HMODULE local_10;
  FARPROC local_c;
  DWORD local_8;
  
  pvVar2 = pidd;
  pFVar7 = (FARPROC)0x0;
  local_1c = *(LPCSTR *)((int)pidd + 4);
  local_28 = (void *)0x24;
  local_24 = pidd;
  local_20 = ppfnIATEntry;
  local_10 = (HMODULE)0x0;
  local_c = (FARPROC)0x0;
  local_8 = 0;
  hLibModule = (HMODULE)**(int **)((int)pidd + 8);
  piVar6 = (int *)((int)pidd + 0x10);
  pidd = (void *)(((int)ppfnIATEntry - *(int *)((int)pidd + 0xc) >> 2) * 4);
  puVar3 = (uint *)(*piVar6 + (int)pidd);
  local_18 = -((int)~*puVar3 >> 0x1f);
  uVar1 = *puVar3;
  if (local_18 == 0) {
    local_14 = (LPCSTR)(uVar1 & 0xffff);
  }
  else {
    local_14 = (LPCSTR)(uVar1 + 2);
  }
  if ((__pfnDliNotifyHook == (code *)0x0) ||
     (pFVar7 = (FARPROC)(*__pfnDliNotifyHook)(0,&local_28), pFVar7 == (FARPROC)0x0)) {
    if (hLibModule == (HMODULE)0x0) {
      if ((((__pfnDliNotifyHook == (code *)0x0) ||
           (hLibModule = (HMODULE)(*__pfnDliNotifyHook)(1,&local_28), hLibModule == (HMODULE)0x0))
          && (hLibModule = LoadLibraryA(local_1c), hLibModule == (HMODULE)0x0)) &&
         ((local_8 = GetLastError(), __pfnDliFailureHook == (code *)0x0 ||
          (hLibModule = (HMODULE)(*__pfnDliFailureHook)(3,&local_28), hLibModule == (HMODULE)0x0))))
      {
        ppfnIATEntry = &local_28;
        RaiseException(0xc06d007e,0,1,(ULONG_PTR *)&ppfnIATEntry);
        return local_c;
      }
      pHVar4 = (HMODULE)InterlockedExchange(*(LONG **)((int)pvVar2 + 8),(LONG)hLibModule);
      if (pHVar4 == hLibModule) {
        FreeLibrary(hLibModule);
      }
      else if ((*(int *)((int)pvVar2 + 0x18) != 0) &&
              (puVar5 = LocalAlloc(0x40,8), puVar5 != (undefined4 *)0x0)) {
        puVar5[1] = pvVar2;
        *puVar5 = __puiHead;
        __puiHead = puVar5;
      }
    }
    local_10 = hLibModule;
    if (__pfnDliNotifyHook != (code *)0x0) {
      pFVar7 = (FARPROC)(*__pfnDliNotifyHook)(2,&local_28);
    }
    if (pFVar7 == (FARPROC)0x0) {
      if ((((*(int **)((int)pvVar2 + 0x14) != (int *)0x0) && (*(int *)((int)pvVar2 + 0x1c) != 0)) &&
          (piVar6 = (int *)((int)&hLibModule->unused + hLibModule[0xf].unused), *piVar6 == 0x4550))
         && ((piVar6[2] == *(int *)((int)pvVar2 + 0x1c) && (hLibModule == (HMODULE)piVar6[0xd])))) {
        _OverlayIAT__YGXPAU_IMAGE_THUNK_DATA32__PBU1__Z
                  (*(int **)((int)pvVar2 + 0xc),*(int **)((int)pvVar2 + 0x14));
        pFVar7 = *(FARPROC *)((int)pidd + *(int *)((int)pvVar2 + 0xc));
        goto LAB_1044f09a;
      }
      pFVar7 = GetProcAddress(hLibModule,local_14);
      if (pFVar7 == (FARPROC)0x0) {
        local_8 = GetLastError();
        if (__pfnDliFailureHook != (code *)0x0) {
          pFVar7 = (FARPROC)(*__pfnDliFailureHook)(4,&local_28);
        }
        if (pFVar7 == (FARPROC)0x0) {
          pidd = &local_28;
          RaiseException(0xc06d007f,0,1,(ULONG_PTR *)&pidd);
          pFVar7 = local_c;
        }
      }
    }
    *ppfnIATEntry = pFVar7;
  }
LAB_1044f09a:
  if (__pfnDliNotifyHook != (code *)0x0) {
    local_8 = 0;
    local_10 = hLibModule;
    local_c = pFVar7;
    (*__pfnDliNotifyHook)(5,&local_28);
  }
  return pFVar7;
}

