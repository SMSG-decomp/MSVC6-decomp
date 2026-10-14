int __fastcall list_length(c2_link *list)

{
  int iVar1;
  
  iVar1 = 0;
  for (; list != (c2_link *)0x0; list = list->next) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

