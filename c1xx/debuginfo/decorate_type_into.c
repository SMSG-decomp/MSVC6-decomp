char * __cdecl decorate_type_into(char *out,c1_type *type,int innermost)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  c1_symbol *sym;
  char *pcVar5;
  ushort uVar6;
  c1_type *pcVar7;
  byte *pbVar8;
  
  bVar3 = (byte)type->code;
  pcVar7 = type;
  if (((bVar3 & 0x83) == 0x81) && (-1 < (char)type->base->code)) {
    bVar2 = true;
joined_r0x10410bfd:
    while ((char)bVar3 < '\0') {
      bVar3 = (byte)pcVar7->base->code;
      pcVar7 = pcVar7->base;
    }
    uVar6 = pcVar7->flags;
  }
  else {
    bVar2 = false;
    if (((bVar3 & 0x8f) == 0x83) || (-1 < (char)bVar3)) goto joined_r0x10410bfd;
    uVar6 = type->flags;
  }
  if ((uVar6 & 0x100) != 0) {
    *out = 'I';
    out = out + 1;
  }
  bVar3 = -((uVar6 & 8) != 0) & 0xc;
  if (!bVar2) {
    pcVar7 = type;
    if (innermost == 0) {
      bVar4 = (byte)type->code;
      if ((char)bVar4 < '\0') {
        if ((bVar4 & 0x83) == 0x81) goto LAB_10410b95;
        bVar4 = (byte)type->base->code;
        if (-1 < (char)bVar4) {
          do {
            pcVar7 = pcVar7->base;
          } while ((char)pcVar7->code < '\0');
          goto LAB_10410b88;
        }
        if ((bVar4 & 0x83) == 0x81) goto LAB_10410b95;
        uVar6 = type->base->flags;
      }
    }
    else {
      cVar1 = (char)type->code;
      while (cVar1 < '\0') {
        pcVar7 = pcVar7->base;
        cVar1 = (char)pcVar7->code;
      }
LAB_10410b88:
      uVar6 = pcVar7->flags;
    }
  }
  if (uVar6 != 0) {
    if ((uVar6 & 0x20) != 0) {
      bVar3 = bVar3 | 1;
    }
    if ((uVar6 & 0x40) != 0) {
      bVar3 = bVar3 | 2;
    }
  }
LAB_10410b95:
  uVar6 = type->code & 0x8f;
  if ((uVar6 == 0x8a) || (uVar6 == 0x8e)) {
    bVar3 = bVar3 | 0x10;
  }
  if (bVar3 < 0x19) {
    *out = bVar3 + 0x41;
  }
  else {
    *out = bVar3 + 0x17;
  }
  pbVar8 = (byte *)(out + 1);
  if ((bVar3 & 0x10) != 0) {
    uVar6 = type->code & 0x8f;
    if ((uVar6 == 0x8a) || (uVar6 == 0x8e)) {
      sym = (type->extra).cls;
    }
    else {
      sym = (c1_symbol *)0x0;
    }
    pcVar5 = decorate_scope_chain((char *)pbVar8,&sym->kind);
    *pcVar5 = '@';
    pbVar8 = (byte *)(pcVar5 + 1);
  }
  if ((bVar3 & 0xc) == 0xc) {
    pbVar8 = decorate_type_text(pbVar8,type);
    return (char *)pbVar8;
  }
  return (char *)pbVar8;
}

