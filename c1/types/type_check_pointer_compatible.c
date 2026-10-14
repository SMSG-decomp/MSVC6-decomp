int __cdecl type_check_pointer_compatible(c1_type *type,c1_type *type2)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  c1_u8 cVar5;
  ushort uVar6;
  c1_type *type2_00;
  c1_type *pcVar7;
  int iVar8;
  c1_type *pcVar9;
  c1_type *type_00;
  int iVar10;
  
  type_00 = (c1_type *)(-(uint)((type->code & 0x80) != 0) & (uint)type);
  type2_00 = (c1_type *)(-(uint)((type2->code & 0x80) != 0) & (uint)type2);
  if (type == type2) {
    return 0;
  }
  cVar5 = type_derivations_equal(type,type2);
  if (cVar5 != '\0') {
    cVar1 = (char)type->code;
    pcVar9 = type;
    while (cVar1 < '\0') {
      pcVar9 = pcVar9->base;
      cVar1 = (char)pcVar9->code;
    }
    pcVar7 = type_innermost_base(type2);
    if ((pcVar9->code == pcVar7->code) && ((pcVar9->extra).sym == (pcVar7->extra).sym)) {
      iVar10 = 0;
      goto LAB_1063c106;
    }
  }
  if (((type->code & 0x8f) == 0x82) && (((byte)type->base->code >> 6 & 1) != 0)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (((type2->code & 0x8f) == 0x82) && (((byte)type2->base->code >> 6 & 1) != 0)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (bVar3) {
    pcVar9 = type2;
    if (!bVar4) goto LAB_1063c1f9;
    iVar10 = 0;
  }
  else {
    pcVar9 = type;
    if (!bVar4) {
      return 1;
    }
LAB_1063c1f9:
    if (-1 < (char)pcVar9->code) {
      return 1;
    }
    uVar6 = pcVar9->code & 0x8f;
    iVar10 = 2;
    if ((uVar6 != 0x82) && (uVar6 != 0x83)) {
      if (uVar6 != 0x86) {
        return 1;
      }
      conv_warn_function_data_pointer();
    }
  }
  if ((((byte)type2_00->flags ^ (byte)type_00->flags) & 0x18) != 0) {
    return 1;
  }
LAB_1063c106:
  cVar2 = (char)type->code;
  pcVar9 = type;
  cVar1 = cVar2;
  while (cVar1 < '\0') {
    pcVar9 = pcVar9->base;
    cVar1 = (char)pcVar9->code;
  }
  while (cVar2 < '\0') {
    type = type->base;
    cVar2 = (char)type->code;
  }
  cVar1 = (char)type2->code;
  while (cVar1 < '\0') {
    type2 = type2->base;
    cVar1 = (char)type2->code;
  }
  iVar8 = conv_warn_different_qualifiers
                    ('p',type2->flags,type->flags,1,(uint)((pcVar9->code & 0xfff) == 0x11));
  if (iVar8 == 0) {
    return 1;
  }
  if ((type_00 != (c1_type *)0x0) && (type2_00 != (c1_type *)0x0)) {
    conv_warn_different_bases('p',type_00,type2_00);
  }
  return iVar10;
}

