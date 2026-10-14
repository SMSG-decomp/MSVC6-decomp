int __cdecl type_size_checked(c1_type *type)

{
  int iVar1;
  
  iVar1 = type_size_derived(type);
  if (iVar1 == 0) {
    type_check_size_known(type);
  }
  return iVar1;
}

