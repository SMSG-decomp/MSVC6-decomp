int __fastcall type_size_derived(c1_type *type)

{
  c1_u32 cVar1;
  c1_type *pcVar2;
  ushort uVar3;
  int iVar4;
  
  if (-1 < (char)type->code) {
    iVar4 = type_size_scalar(type);
    return iVar4;
  }
  switch(type->code & 0x8f) {
  case 0x81:
  case 0x85:
  case 0x86:
    break;
  case 0x82:
    pcVar2 = type->base;
    if (-1 < (char)pcVar2->code) {
      iVar4 = type_size_scalar(pcVar2);
      return iVar4;
    }
    uVar3 = pcVar2->code & 0x8f;
    if (uVar3 != 0x82) {
      if (uVar3 == 0x83) {
        cVar1 = (pcVar2->extra).count;
        iVar4 = type_size_derived(pcVar2);
        return iVar4 * cVar1;
      }
      if (uVar3 != 0x86) {
        return 0;
      }
    }
    break;
  case 0x83:
    pcVar2 = type->base;
    if ((-1 < (char)pcVar2->code) ||
       ((uVar3 = pcVar2->code & 0x8f, uVar3 != 0x86 && (uVar3 != 0x82)))) {
      iVar4 = type_size_derived(pcVar2);
      if ((pcVar2->code & 0x8f) == 0x83) {
        return (pcVar2->extra).count * iVar4;
      }
      return iVar4;
    }
    break;
  default:
    return 0;
  }
  return 4;
}

