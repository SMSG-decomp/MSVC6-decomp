int __cdecl type_argument_size(c1_type *t,char promote)

{
  char derived;
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  byte bVar4;
  
  bVar4 = (byte)t->code;
  derived = -((char)bVar4 >> 7);
  if ((derived == '\0') || (t == (c1_type *)0x0)) {
    if (promote != '\0') {
      iVar3 = type_argument_size_promoted(t,derived);
      return iVar3;
    }
  }
  else if ((bVar4 & 0x8f) == 0x83) {
    return 4;
  }
  if (-1 < (char)t->code) {
    iVar3 = type_size_scalar(t);
    return iVar3;
  }
  uVar1 = t->code & 0x8f;
  pcVar2 = t;
  if (uVar1 == 0x83) {
    do {
      pcVar2 = pcVar2->base;
    } while ((char)pcVar2->code < '\0');
    if ((pcVar2->code & 0xfff) == 0x802) {
      iVar3 = type_size_scalar(g_type_int);
      return (t->extra).count * iVar3;
    }
    iVar3 = type_size_derived(t);
    return (t->extra).count * iVar3;
  }
  if (uVar1 == 0x8a) {
    iVar3 = type_data_member_pointer_size(t);
    return iVar3;
  }
  if (uVar1 == 0x8e) {
    iVar3 = type_member_pointer_size_kind(t);
    return iVar3;
  }
  return 4;
}

