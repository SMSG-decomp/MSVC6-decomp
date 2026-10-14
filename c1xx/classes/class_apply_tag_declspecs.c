void __cdecl class_apply_tag_declspecs(c1_symbol *cls,c1_u8 *spec)

{
  c1_u8 *pcVar1;
  byte bVar2;
  
  if ((spec[2] & 0xc) != 0) {
    bVar2 = (cls->flags22 ^ spec[2]) & 4 ^ cls->flags22;
    cls->flags22 = bVar2;
    cls->flags22 = (bVar2 ^ spec[2]) & 8 ^ bVar2;
  }
  if ((spec[0x14] & 2) != 0) {
    pcVar1 = &((cls->detail).cls)->layout_flags3c;
    *pcVar1 = *pcVar1 | 0x80;
  }
  return;
}

