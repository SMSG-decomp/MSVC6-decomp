FARPROC delayload_helper(void *desc,FARPROC *slot)

{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  HMODULE hLibModule;
  HMODULE pHVar4;
  undefined4 *puVar5;
  int *piVar6;
  FARPROC pFVar7;
  uint32_t dli_cb;
  void *dli_desc;
  FARPROC *dli_slot;
  LPCSTR dll_name;
  int import_by_name;
  LPCSTR proc_name;
  HMODULE module;
  FARPROC proc;
  DWORD last_error;
  
  pvVar2 = desc;
  pFVar7 = (FARPROC)0x0;
  dll_name = *(LPCSTR *)((int)desc + 4);
  dli_cb = 0x24;
  dli_desc = desc;
  dli_slot = slot;
  module = (HMODULE)0x0;
  proc = (FARPROC)0x0;
  last_error = 0;
  hLibModule = (HMODULE)**(int **)((int)desc + 8);
  piVar6 = (int *)((int)desc + 0x10);
  desc = (void *)(((int)slot - *(int *)((int)desc + 0xc) >> 2) * 4);
  puVar3 = (uint *)(*piVar6 + (int)desc);
  import_by_name = -((int)~*puVar3 >> 0x1f);
  uVar1 = *puVar3;
  if (import_by_name == 0) {
    proc_name = (LPCSTR)(uVar1 & 0xffff);
  }
  else {
    proc_name = (LPCSTR)(uVar1 + 2);
  }
  if ((__pfnDliNotifyHook == (code *)0x0) ||
     (pFVar7 = (FARPROC)(*__pfnDliNotifyHook)(0,&dli_cb), pFVar7 == (FARPROC)0x0)) {
    if (hLibModule == (HMODULE)0x0) {
      if ((((__pfnDliNotifyHook == (code *)0x0) ||
           (hLibModule = (HMODULE)(*__pfnDliNotifyHook)(1,&dli_cb), hLibModule == (HMODULE)0x0)) &&
          (hLibModule = LoadLibraryA(dll_name), hLibModule == (HMODULE)0x0)) &&
         ((last_error = GetLastError(), __pfnDliFailureHook == (code *)0x0 ||
          (hLibModule = (HMODULE)(*__pfnDliFailureHook)(3,&dli_cb), hLibModule == (HMODULE)0x0)))) {
        slot = (FARPROC *)&dli_cb;
        RaiseException(0xc06d007e,0,1,(ULONG_PTR *)&slot);
        return proc;
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
    module = hLibModule;
    if (__pfnDliNotifyHook != (code *)0x0) {
      pFVar7 = (FARPROC)(*__pfnDliNotifyHook)(2,&dli_cb);
    }
    if (pFVar7 == (FARPROC)0x0) {
      if ((((*(int **)((int)pvVar2 + 0x14) != (int *)0x0) && (*(int *)((int)pvVar2 + 0x1c) != 0)) &&
          (piVar6 = (int *)((int)&hLibModule->unused + hLibModule[0xf].unused), *piVar6 == 0x4550))
         && ((piVar6[2] == *(int *)((int)pvVar2 + 0x1c) && (hLibModule == (HMODULE)piVar6[0xd])))) {
        copy_until_zero(*(int **)((int)pvVar2 + 0xc),*(int **)((int)pvVar2 + 0x14));
        pFVar7 = *(FARPROC *)((int)desc + *(int *)((int)pvVar2 + 0xc));
        goto LAB_10797d5f;
      }
      pFVar7 = GetProcAddress(hLibModule,proc_name);
      if (pFVar7 == (FARPROC)0x0) {
        last_error = GetLastError();
        if (__pfnDliFailureHook != (code *)0x0) {
          pFVar7 = (FARPROC)(*__pfnDliFailureHook)(4,&dli_cb);
        }
        if (pFVar7 == (FARPROC)0x0) {
          desc = &dli_cb;
          RaiseException(0xc06d007f,0,1,(ULONG_PTR *)&desc);
          pFVar7 = proc;
        }
      }
    }
    *slot = pFVar7;
  }
LAB_10797d5f:
  if (__pfnDliNotifyHook != (code *)0x0) {
    last_error = 0;
    module = hLibModule;
    proc = pFVar7;
    (*__pfnDliNotifyHook)(5,&dli_cb);
  }
  return pFVar7;
}

