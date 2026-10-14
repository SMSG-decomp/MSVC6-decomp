int __cdecl type_argument_size(c1_type *type,char promote_float)

{
  c1_u8 skip_layers;
  byte bVar1;
  int iVar2;
  
  bVar1 = (byte)type->code;
  skip_layers = -((char)bVar1 >> 7);
  if ((skip_layers == '\0') || (type == (c1_type *)0x0)) {
    if (promote_float != '\0') {
      iVar2 = type_alignment_scalar(type,skip_layers);
      return iVar2;
    }
  }
  else if ((bVar1 & 0x8f) == 0x83) {
    return 4;
  }
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

