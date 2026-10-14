wchar_t ** __cdecl import_rename_param_names(wchar_t **names,int n,int count)

{
  wchar_t **ppwVar1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  
  ppwVar1 = __2_YAPAXI_Z(n * 4);
  iVar4 = 0;
  if (0 < n) {
    iVar3 = (int)ppwVar1 - (int)names;
    do {
      if (((iVar4 < count) && (pwVar2 = *names, pwVar2 != (wchar_t *)0x0)) && (*pwVar2 != L'\0')) {
        pwVar2 = import_apply_rename(pwVar2);
        *(wchar_t **)(iVar3 + (int)names) = pwVar2;
      }
      else {
        *(undefined4 *)(iVar3 + (int)names) = 0;
      }
      iVar4 = iVar4 + 1;
      names = names + 1;
    } while (iVar4 < n);
    return ppwVar1;
  }
  return ppwVar1;
}

