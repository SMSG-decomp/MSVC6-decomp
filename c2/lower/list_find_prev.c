c2_link * __fastcall list_find_prev(c2_link *list,c2_link *target)

{
  c2_link *pcVar1;
  
  pcVar1 = (c2_link *)0x0;
  for (; (list != (c2_link *)0x0 && (list != target)); list = list->next) {
    pcVar1 = list;
  }
  return pcVar1;
}

