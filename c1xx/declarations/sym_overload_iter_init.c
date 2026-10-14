void __thiscall sym_overload_iter_init(c1xx_ovl_set_iter *iter,c1_u8 *entry)

{
  byte bVar1;
  
  iter->current = (c1_sym_link *)0x0;
  iter->start = (c1_sym_link *)entry;
  bVar1 = entry[-8] & 0x1f;
  if ((((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) && ((entry[-8] & 0x1f) != 0x1a)) {
    entry = *(c1_u8 **)(entry + 0xc);
  }
  iter->next = (c1_sym_link *)entry;
  return;
}

