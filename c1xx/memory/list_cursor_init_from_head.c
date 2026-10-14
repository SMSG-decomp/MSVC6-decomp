void __thiscall list_cursor_init_from_head(c1_list_cursor *cursor,c1_sym_list *head)

{
  c1_sym_link *pcVar1;
  
  if (head != (c1_sym_list *)0x0) {
    pcVar1 = head->head;
    cursor->current = pcVar1;
    cursor->valid = pcVar1 != (c1_sym_link *)0x0;
    return;
  }
  cursor->current = (void *)0x0;
  cursor->valid = '\0';
  return;
}

