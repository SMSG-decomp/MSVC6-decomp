int __cdecl func_parameter_bytes(c1_type *fntype)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = *(int *)fntype->debug_index;
  piVar3 = (int *)fntype->debug_index + 2;
  if (iVar2 == 0) {
    return 0;
  }
  do {
    iVar1 = type_argument_size((c1_type *)*piVar3,'\0');
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + (iVar1 + 3U & 0xfffffffc);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar4;
}

