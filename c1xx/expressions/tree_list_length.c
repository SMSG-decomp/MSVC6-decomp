int __cdecl tree_list_length(int item)

{
  int iVar1;
  
  iVar1 = 0;
  for (; item != 0; item = *(int *)(item + 0x14)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

