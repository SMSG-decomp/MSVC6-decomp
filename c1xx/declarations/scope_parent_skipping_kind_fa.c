int __fastcall scope_parent_skipping_kind_fa(void *holder)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)holder + 4);
  iVar1 = *(int *)(iVar2 + 4);
  if ((iVar1 != 0) && (iVar2 = iVar1, *(char *)(iVar1 + 8) == -6)) {
    return *(int *)(iVar1 + 4);
  }
  return iVar2;
}

