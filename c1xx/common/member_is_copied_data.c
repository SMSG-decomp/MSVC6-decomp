int __cdecl member_is_copied_data(c1_symbol *member)

{
  byte bVar1;
  
  bVar1 = member->kind & 0x1f;
  if ((bVar1 != 2) &&
     ((((bVar1 != 3 || (member->type == (c1_type *)0x0)) || ((member->flags3 & 1) != 0)) ||
      (((member->flags4 & 0x40) != 0 || ((member->flags23 & 0x80) != 0)))))) {
    return 0;
  }
  return 1;
}

