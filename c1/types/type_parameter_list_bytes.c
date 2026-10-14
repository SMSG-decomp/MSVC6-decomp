int __cdecl type_parameter_list_bytes(c1_param_list *list)

{
  int iVar1;
  int iVar2;
  c1_type **ppcVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = list->count;
  ppcVar3 = list->types;
  if (iVar2 == 0) {
    return 0;
  }
  do {
    iVar1 = type_argument_size(*ppcVar3,'\0');
    ppcVar3 = ppcVar3 + 1;
    iVar4 = iVar4 + (iVar1 + 3U & 0xfffffffc);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar4;
}

