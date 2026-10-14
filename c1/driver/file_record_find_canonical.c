int __thiscall file_record_find_canonical(void *scope,int name)

{
  int iVar1;
  
  iVar1 = *(int *)((int)scope + 0x214);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 0x10) == name) break;
    iVar1 = *(int *)(iVar1 + 0x14);
  }
  return iVar1;
}

