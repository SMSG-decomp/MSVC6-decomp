void __thiscall class_conversion_iter_init(c1_member_iter *iter,c1_symbol *cls)

{
  c1_sym_link *pcVar1;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar1 = (c1_sym_link *)0x0;
  }
  else {
    pcVar1 = ((cls->x28).members)->head;
  }
  iter->cls = &cls->name;
  (iter->cursor).current = pcVar1;
  (iter->cursor).valid = pcVar1 != (c1_sym_link *)0x0;
  iter->current = (void *)0x0;
  iter->next = (void *)0x0;
  iter->filter = 5;
  if (pcVar1 != (c1_sym_link *)0x0) {
    iter->next = pcVar1;
  }
  return;
}

