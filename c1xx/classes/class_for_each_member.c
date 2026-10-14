void __cdecl class_for_each_member(int key,void *fn,int arg)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(key + 0x28) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(key + 0x28) + 4);
  }
  for (; (iVar2 != 0 &&
         ((((*(byte *)(iVar2 + -6) & 0x10) != 0 || (cVar1 = (*fn)(iVar2 + -8,arg), cVar1 != '\0'))
          && (iVar2 != 0)))); iVar2 = *(int *)(iVar2 + 4)) {
  }
  return;
}

