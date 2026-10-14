FARPROC __delayLoadHelper(ImgDelayDescr *pidd,FARPROC *ppfnIATEntry)

{
  int iINT;
  HMODULE hmod;
  HMODULE hmodT;
  UnloadInfo *puli;
  int *pinh;
  FARPROC pfnRet;
  DelayLoadInfo dli;
  uint entry;
  IMAGE_THUNK_DATA32 **pINT_p;
  ImgDelayDescr *descr;
  
  descr = pidd;
  pfnRet = (FARPROC)0x0;
  dli.szDll = pidd->szName;
  dli.cb = 0x24;
  dli.pidd = pidd;
  dli.ppfn = ppfnIATEntry;
  dli.hmodCur = (void *)0x0;
  dli.pfnCur = (void *)0x0;
  dli.dwLastError = 0;
  hmod = *pidd->phmod;
  iINT = (int)ppfnIATEntry - (int)pidd->pIAT >> 2;
  pINT_p = &pidd->pINT;
  pidd = (ImgDelayDescr *)(iINT * 4);
  dli.dlp.fImportByName = -((int)~(*pINT_p)[iINT].Ordinal >> 0x1f);
  entry = (*pINT_p)[iINT].Ordinal;
  if (dli.dlp.fImportByName == 0) {
    dli.dlp.u.dwOrdinal = entry & 0xffff;
  }
  else {
    dli.dlp.u.szProcName = (char *)(entry + 2);
  }
  if ((__pfnDliNotifyHook == (PfnDliHook)0x0) ||
     (pfnRet = (*__pfnDliNotifyHook)(0,&dli), pfnRet == (FARPROC)0x0)) {
    if (hmod == (HMODULE)0x0) {
      if ((((__pfnDliNotifyHook == (PfnDliHook)0x0) ||
           (hmod = (*__pfnDliNotifyHook)(1,&dli), hmod == (HMODULE)0x0)) &&
          (hmod = LoadLibraryA(dli.szDll), hmod == (HMODULE)0x0)) &&
         ((dli.dwLastError = GetLastError(), __pfnDliFailureHook == (PfnDliHook)0x0 ||
          (hmod = (*__pfnDliFailureHook)(3,&dli), hmod == (HMODULE)0x0)))) {
        ppfnIATEntry = (FARPROC *)&dli;
        RaiseException(0xc06d007e,0,1,(ULONG_PTR *)&ppfnIATEntry);
        return dli.pfnCur;
      }
      hmodT = (HMODULE)InterlockedExchange((LONG *)descr->phmod,(LONG)hmod);
      if (hmodT == hmod) {
        FreeLibrary(hmod);
      }
      else if ((descr->pUnloadIAT != (IMAGE_THUNK_DATA32 *)0x0) &&
              (puli = LocalAlloc(0x40,8), puli != (UnloadInfo *)0x0)) {
        puli->pidd = descr;
        puli->puiNext = __puiHead;
        __puiHead = puli;
      }
    }
    dli.hmodCur = hmod;
    if (__pfnDliNotifyHook != (PfnDliHook)0x0) {
      pfnRet = (*__pfnDliNotifyHook)(2,&dli);
    }
    if (pfnRet == (FARPROC)0x0) {
      if ((((descr->pBoundIAT != (IMAGE_THUNK_DATA32 *)0x0) && (descr->dwTimeStamp != 0)) &&
          (pinh = (int *)((int)&hmod->unused + hmod[0xf].unused), *pinh == 0x4550)) &&
         ((pinh[2] == descr->dwTimeStamp && (hmod == (HMODULE)pinh[0xd])))) {
        delayload_copy_iat(descr->pIAT,descr->pBoundIAT);
        pfnRet = *(FARPROC *)((int)&pidd->grAttrs + (int)descr->pIAT);
        goto LAB_004065c0;
      }
      pfnRet = GetProcAddress(hmod,dli.dlp.u.szProcName);
      if (pfnRet == (FARPROC)0x0) {
        dli.dwLastError = GetLastError();
        if (__pfnDliFailureHook != (PfnDliHook)0x0) {
          pfnRet = (*__pfnDliFailureHook)(4,&dli);
        }
        if (pfnRet == (FARPROC)0x0) {
          pidd = (ImgDelayDescr *)&dli;
          RaiseException(0xc06d007f,0,1,(ULONG_PTR *)&pidd);
          pfnRet = dli.pfnCur;
        }
      }
    }
    *ppfnIATEntry = pfnRet;
  }
LAB_004065c0:
  if (__pfnDliNotifyHook != (PfnDliHook)0x0) {
    dli.dwLastError = 0;
    dli.hmodCur = hmod;
    dli.pfnCur = pfnRet;
    (*__pfnDliNotifyHook)(5,&dli);
  }
  return pfnRet;
}

