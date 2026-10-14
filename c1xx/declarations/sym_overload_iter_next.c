char __fastcall sym_overload_iter_next(c1xx_ovl_set_iter *iter)

{
  c1_sym_link *pcVar1;
  byte bVar2;
  
  if ((iter->start != (c1_sym_link *)0x0) && (iter->next != (c1_sym_link *)0x0)) {
    bVar2 = (byte)iter->next[-1].position;
    while( true ) {
      if ((bVar2 & 0x1f) != 0x1a) {
        iter->current = iter->next;
        bVar2 = (byte)iter->start[-1].position & 0x1f;
        if (((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) {
          iter->next = iter->next->next;
          return '\x01';
        }
        iter->next = (c1_sym_link *)0x0;
        return '\x01';
      }
      pcVar1 = iter->next->next;
      iter->next = pcVar1;
      if (pcVar1 == (c1_sym_link *)0x0) break;
      bVar2 = (byte)pcVar1[-1].position;
    }
  }
  return '\0';
}

