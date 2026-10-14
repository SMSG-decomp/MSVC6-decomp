char __cdecl
ovl_type_matches_builtin_pattern
          (c1_type *type,c1_type *pattern,char need_lvalue,char via_conversion)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  c1_type *pcVar4;
  byte bVar5;
  ushort uVar6;
  byte bVar7;
  ushort uVar8;
  c1_type *pcVar9;
  
  if (type == (c1_type *)0x0) {
    return '\0';
  }
  uVar6 = type->code;
  bVar7 = (byte)uVar6;
  pcVar9 = type;
  bVar5 = bVar7;
  while ((char)bVar5 < '\0') {
    pcVar9 = pcVar9->base;
    bVar5 = (byte)pcVar9->code;
  }
  uVar3 = pcVar9->code;
  if (((need_lvalue != '\0') && (via_conversion != '\0')) &&
     ((-1 < (char)bVar7 || ((bVar7 & 0x8f) != 0x80)))) {
    return '\0';
  }
  pcVar9 = type;
  if (((char)bVar7 < '\0') && ((bVar7 & 0x8f) == 0x80)) {
    pcVar9 = type->base;
  }
  cVar2 = (char)pattern->code;
  pcVar4 = pattern;
  cVar1 = cVar2;
  while (cVar1 < '\0') {
    pcVar4 = pcVar4->base;
    cVar1 = (char)pcVar4->code;
  }
  uVar8 = pcVar4->code & 0xfff;
  if (0x807 < uVar8) {
    if (uVar8 == 0x80a) {
      if ((((char)bVar7 < '\0') && (((uVar6 & 0x8f) == 0x86 || ((uVar6 & 0x8f) == 0x82)))) &&
         ((type->base->code >> 9 & 1) != 0)) {
        return '\x01';
      }
    }
    else {
      if (uVar8 != 0x80b) {
        return '\0';
      }
      if ((uVar6 & 0x8f) == 0x8a) {
        return '\x01';
      }
      if ((uVar6 & 0x8f) == 0x8e) {
        return '\x01';
      }
    }
    return '\0';
  }
  if (uVar8 < 0x806) {
    if (uVar8 != 0x10) {
      if (uVar8 != 0x803) {
        if (uVar8 != 0x805) {
          return '\0';
        }
        if (((uVar3 & 0x30) == 0) && ((uVar3 & 0x400) == 0)) {
          if (need_lvalue != '\0') {
            return '\0';
          }
          if ((uVar3 & 0x100) == 0) {
            return '\0';
          }
        }
        if ((char)pcVar9->code < '\0') {
          return '\0';
        }
        return '\x01';
      }
      if (((uVar3 & 0x10) == 0) && ((uVar3 & 0x400) == 0)) {
        if (need_lvalue != '\0') {
          return '\0';
        }
        if ((uVar3 & 0x100) == 0) {
          return '\0';
        }
      }
      if ((char)pcVar9->code < '\0') {
        return '\0';
      }
      return '\x01';
    }
    if ((((((uVar6 & 0x130) == 0) && (uVar6 = uVar6 & 0x8f, uVar6 != 0x83)) && (uVar6 != 0x82)) &&
        ((uVar6 != 0x86 && (uVar6 != 0x8a)))) && (uVar6 != 0x8e)) {
      return '\0';
    }
  }
  else {
    uVar6 = pcVar9->code & 0x8f;
    if (((uVar6 != 0x83) && (uVar6 != 0x82)) && (uVar6 != 0x86)) {
      return '\0';
    }
    while (cVar2 < '\0') {
      pattern = pattern->base;
      cVar2 = (char)pattern->code;
    }
    if ((((pattern->code & 0xfff) == 0x806) && ((bVar7 & 0x8f) == 0x82)) &&
       (((byte)type->base->code >> 6 & 1) != 0)) {
      return '\0';
    }
  }
  return '\x01';
}

