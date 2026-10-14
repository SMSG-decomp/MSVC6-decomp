byte * __cdecl decorate_pointer_code(byte *out,c1_type *type)

{
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  ushort uVar6;
  char *pcVar7;
  
  bVar5 = 0;
  uVar1 = type->code;
  if ((char)(byte)uVar1 < '\0') {
    bVar5 = 0x50;
    pcVar2 = type;
    if (((byte)uVar1 & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(type->base);
    }
    if ((((byte)pcVar2->flags >> 5 & 1) != 0) || (type->code == 0x4082)) {
      bVar5 = 0x51;
    }
    pcVar2 = type;
    if ((type->code & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(type->base);
    }
    if (((byte)pcVar2->flags >> 6 & 1) != 0) {
      bVar5 = bVar5 | 2;
    }
    *out = bVar5;
    pbVar4 = (byte *)decorate_type_by_kind((char *)(out + 1),type);
    return pbVar4;
  }
  if ((uVar1 & 0x4f0) == 0) {
    uVar6 = uVar1 & 0x20f;
    if ((uVar6 == 0x201) || ((uVar1 & 0x800) != 0)) {
      *out = 0x56;
    }
    else if (uVar6 == 0x202) {
      *out = 0x55;
    }
    else {
      if (uVar6 != 0x203) {
        if (uVar1 == 0x80d) {
          return out;
        }
        *out = 0x57;
        pbVar4 = (byte *)decorate_put_4((char *)(out + 1));
        goto LAB_1041117c;
      }
      *out = 0x54;
    }
    pbVar4 = out + 1;
LAB_1041117c:
    uVar1 = type->code;
    if ((uVar1 & 0x800) == 0) {
      pbVar4 = (byte *)decorate_scope_prefix((char *)pbVar4,(type->extra).cls);
      return pbVar4;
    }
    if (((char)uVar1 < '\0') || ((uVar1 & 0xfff) != 0x801)) {
      pcVar7 = "generic-type-";
    }
    else {
      pcVar7 = "template-parameter-";
    }
    iVar3 = format_snprintf((char *)pbVar4,"%s",0x1800,pcVar7);
    pbVar4 = (byte *)decorate_signed_number((char *)(pbVar4 + iVar3),(int)*(short *)&type->extra);
    return pbVar4;
  }
  uVar6 = uVar1 & 0xfff;
  if (0x402 < uVar6) goto code_r0x10411112;
  if (uVar6 == 0x402) {
    pbVar4 = decorate_pointer_code_unsigned_letter(0x4c,type,out);
    return pbVar4;
  }
  switch(uVar6) {
  case 0x10:
    bVar5 = 0x4e;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x11:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x44 - ((uVar1 & 0x1000) != 0),type,out);
    return pbVar4;
  case 0x12:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x46,type,out);
    return pbVar4;
  case 0x13:
    bVar5 = 0x48;
  default:
code_r0x10411112:
    break;
  case 0x14:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x4a,type,out);
    return pbVar4;
  case 0x19:
    bVar5 = 0x44;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x1a:
    bVar5 = 0x46;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x1b:
    bVar5 = 0x48;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x1c:
    bVar5 = 0x4a;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x1d:
    bVar5 = 0x4c;
    *out = 0x5f;
    out = out + 1;
    break;
  case 0x26:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x4d,type,out);
    return pbVar4;
  case 0x27:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x4e,type,out);
    return pbVar4;
  case 0x28:
    pbVar4 = decorate_pointer_code_unsigned_letter(0x4f,type,out);
    return pbVar4;
  }
  if ((type->code & 0x2000) != 0) {
    bVar5 = bVar5 | 1;
  }
  *out = bVar5;
  return out + 1;
}

