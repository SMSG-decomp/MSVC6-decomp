int __fastcall type_alignment_scalar(c1_type *type,c1_u8 skip_layers)

{
  byte bVar1;
  int iVar2;
  c1_type *pcVar3;
  
  pcVar3 = type;
  if (skip_layers != '\0') {
    do {
      pcVar3 = pcVar3->base;
    } while ((char)pcVar3->code < '\0');
  }
  if (pcVar3->code == 0x26) {
    return 8;
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

