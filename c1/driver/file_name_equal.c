char __cdecl file_name_equal(byte *a,byte *b)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = *a;
  if (bVar1 != 0) {
    while (*b != 0) {
      uVar2 = _mbctoupper((uint)bVar1);
      uVar3 = _mbctoupper((uint)*b);
      if ((uVar2 != uVar3) && (((*a != 0x2f && (*a != 0x5c)) || ((*b != 0x2f && (*b != 0x5c)))))) {
        return '\0';
      }
      if (((byte)_mbctype_exref[*a + 1] & 4) != 0) {
        a = a + 1;
        b = b + 1;
      }
      bVar1 = a[1];
      a = a + 1;
      b = b + 1;
      if (bVar1 == 0) {
        return *b == 0;
      }
    }
  }
  return *a == *b;
}

