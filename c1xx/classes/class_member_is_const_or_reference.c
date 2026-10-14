int __cdecl class_member_is_const_or_reference(c1_symbol *member)

{
  byte bVar1;
  c1_type *pcVar2;
  
  pcVar2 = member->type;
  while( true ) {
    bVar1 = (byte)pcVar2->code;
    if (((bVar1 & 0x8f) != 0x83) && ((bVar1 & 0x83) != 0x81)) break;
    pcVar2 = pcVar2->base;
  }
  if ((((byte)pcVar2->flags >> 5 & 1) == 0) &&
     ((bVar1 = (byte)member->type->code, -1 < (char)bVar1 || ((bVar1 & 0x8f) != 0x80)))) {
    return 0;
  }
  return 1;
}

