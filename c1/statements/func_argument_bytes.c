int __cdecl func_argument_bytes(int scope)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (scope == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(scope + 4);
  }
  while( true ) {
    if (iVar2 == 0) {
      return iVar3;
    }
    iVar1 = type_argument_size(*(c1_type **)(iVar2 + 0xc),'\0');
    iVar3 = iVar3 + (iVar1 + 3U & 0xfffffffc);
    if (iVar2 == 0) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  return iVar3;
}

