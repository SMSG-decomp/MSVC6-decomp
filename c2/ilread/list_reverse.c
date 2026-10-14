c2_link * __fastcall list_reverse(c2_link *head)

{
  c2_link *pcVar1;
  c2_link *pcVar2;
  
  if (head->next != (c2_link *)0x0) {
    pcVar2 = (c2_link *)0x0;
    while (head != (c2_link *)0x0) {
      pcVar1 = head->next;
      head->next = pcVar2;
      pcVar2 = head;
      head = pcVar1;
    }
    return pcVar2;
  }
  return head;
}

