char __fastcall ovl_set_iter_next(c1xx_ovl_set_iter *iter)

{
  c1_sym_link *pcVar1;
  c1_sym_link *pcVar2;
  byte bVar3;
  
  pcVar1 = iter->start;
  if ((pcVar1 == (c1_sym_link *)0x0) || (pcVar2 = iter->next, pcVar2 == (c1_sym_link *)0x0)) {
    return '\0';
  }
  iter->current = pcVar2;
  bVar3 = (byte)pcVar1[-1].position & 0x1f;
  if ((bVar3 != 7) && (((bVar3 != 8 && (bVar3 != 6)) && ((pcVar1[-1].position & 0x1f) != 0x1a)))) {
    iter->next = pcVar2->next;
    return '\x01';
  }
  iter->next = (c1_sym_link *)0x0;
  return '\x01';
}

