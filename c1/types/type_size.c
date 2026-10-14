int __fastcall type_size(c1_type *type)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = (byte)type->code;
  if (-1 < (char)bVar1) {
    iVar2 = type_size_scalar(type);
    return iVar2;
  }
  if ((bVar1 & 0x8f) != 0x83) {
    return 4;
  }
  iVar2 = type_size_derived(type);
  return (type->extra).count * iVar2;
}

