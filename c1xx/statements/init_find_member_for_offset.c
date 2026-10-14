int * __cdecl init_find_member_for_offset(int offset,int *member,c1_member_walk *walk)

{
  byte bVar1;
  byte bVar2;
  
  if ((member != (int *)0x0) && ((void *)*member != g_name_alignment_member)) {
    while (((((bVar2 = *(byte *)(member + -2) & 0x1f, bVar2 == 0x10 ||
              (((bVar2 == 7 || (bVar2 == 6)) || (bVar2 == 0x11)))) ||
             ((bVar2 == 8 || (bVar2 == 0x1b)))) ||
            ((bVar2 == 0x1a &&
             (((bVar1 = **(byte **)member[3] & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) ||
              ((bVar1 == 6 || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))))) ||
           (bVar2 == 4))) {
      if (walk->link != (int *)0x0) {
        walk->link = (int *)walk->link[1];
      }
      member = (int *)member[1];
      if (member == (int *)0x0) {
        return (int *)0x0;
      }
    }
    if ((member != (int *)0x0) && (offset == member[7])) {
      return member;
    }
  }
  return (int *)0x0;
}

