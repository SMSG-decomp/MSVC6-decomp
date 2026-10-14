int __fastcall type_size(c1_type *t)

{
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  
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

