char __fastcall class_member_iter_next(c1_member_iter *iter)

{
  void *pvVar1;
  byte bVar2;
  
  do {
    iter->current = iter->next;
    if (iter->next == (void *)0x0) {
      return '\0';
    }
    pvVar1 = (iter->cursor).current;
    if (pvVar1 == (void *)0x0) {
LAB_104303f0:
      iter->next = (void *)0x0;
    }
    else {
      pvVar1 = *(void **)((int)pvVar1 + 4);
      (iter->cursor).current = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_104303f0;
      iter->next = pvVar1;
    }
    switch(iter->filter) {
    case 0:
      return '\x01';
    case 1:
      bVar2 = *(byte *)((int)iter->current + -8) & 0x1f;
      if (((bVar2 == 3) || (bVar2 == 2)) && ((*(byte *)((int)iter->current + -5) & 1) == 0)) {
        return '\x01';
      }
      break;
    case 2:
      bVar2 = *(byte *)((int)iter->current + -8) & 0x1f;
      if (bVar2 == 0x11) {
        return '\x01';
      }
      if (bVar2 == 8) {
        return '\x01';
      }
      break;
    case 3:
      if ((*(byte *)((int)iter->current + -8) & 0x1f) == 4) {
        return '\x01';
      }
      break;
    case 5:
      bVar2 = *(byte *)((int)iter->current + -8) & 0x1f;
      if (((bVar2 == 0x11) || (bVar2 == 8)) && ((*(byte *)((int)iter->current + -7) & 0x40) != 0)) {
        return '\x01';
      }
    }
  } while( true );
}

