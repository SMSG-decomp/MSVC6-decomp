int __cdecl class_member_may_be_declared(c1_symbol *tag)

{
  c1_class_record *pcVar1;
  uint3 uVar2;
  
  pcVar1 = (tag->detail).cls;
  uVar2 = (uint3)((uint)pcVar1 >> 8);
  if ((pcVar1->layout_flags3c & 1) == 0) {
    return CONCAT31(uVar2,1);
  }
  if ((pcVar1->implicit_state41 & 8) != 0) {
    if (((tag->flags1 & 0x20) == 0x20) && ((pcVar1->implicit_state41 & 0x10) == 0)) {
      return CONCAT31(uVar2,1);
    }
    return (uint)uVar2 << 8;
  }
  return CONCAT31(uVar2,1);
}

