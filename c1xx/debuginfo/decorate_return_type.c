char * __cdecl decorate_return_type(char *out,c1_type *type,int mode)

{
  c1_type **ppcVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  
  bVar4 = (byte)type->code;
  pcVar2 = type;
  bVar6 = bVar4;
  if (mode == 1) {
    if ((char)bVar4 < '\0') goto LAB_10410f3e;
joined_r0x10410ead:
    while ((char)bVar6 < '\0') {
      ppcVar1 = &pcVar2->base;
      pcVar2 = *ppcVar1;
      bVar6 = (byte)(*ppcVar1)->code;
    }
    pcVar3 = type;
    bVar6 = bVar4;
    if ((pcVar2->code & 0x40) != 0) {
      *out = 'X';
      return out + 1;
    }
    while ((char)bVar6 < '\0') {
      ppcVar1 = &pcVar3->base;
      pcVar3 = *ppcVar1;
      bVar6 = (byte)(*ppcVar1)->code;
    }
    pcVar2 = type;
    bVar6 = bVar4;
    if ((pcVar3->code & 0x4f0) == 0) {
      *out = '?';
      out = decorate_type_into(out + 1,type,0);
    }
    else {
      while ((char)bVar6 < '\0') {
        ppcVar1 = &pcVar2->base;
        pcVar2 = *ppcVar1;
        bVar6 = (byte)(*ppcVar1)->code;
      }
      bVar6 = (pcVar2->flags & 0x20) != 0;
      pcVar2 = type;
      while ((char)bVar4 < '\0') {
        bVar4 = (byte)pcVar2->base->code;
        pcVar2 = pcVar2->base;
      }
      if ((pcVar2->flags & 0x40) != 0) {
        bVar6 = bVar6 | 2;
      }
      if (bVar6 != 0) {
        *out = '?';
        out[1] = bVar6 + 0x41;
        out = out + 2;
      }
    }
  }
  else if (((bVar4 & 0x83) == 0x81) && (-1 < (char)type->base->code)) goto joined_r0x10410ead;
  if ((mode != 1) && ((type->code & 0x83) == 0x81)) {
    type = type->base;
  }
LAB_10410f3e:
  pbVar5 = decorate_pointer_target(out,type,(uint)(mode == 2));
  return (char *)pbVar5;
}

