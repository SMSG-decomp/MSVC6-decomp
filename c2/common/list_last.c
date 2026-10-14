c2_link * __fastcall list_last(c2_link *list)

{
  c2_link *pcVar1;
  
  pcVar1 = (c2_link *)0x0;
  for (; list != (c2_link *)0x0; list = list->next) {
    pcVar1 = list;
  }
  return pcVar1;
}

