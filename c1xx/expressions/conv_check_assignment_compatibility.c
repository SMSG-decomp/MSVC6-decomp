int __cdecl conv_check_assignment_compatibility(uint op,c1_type *target,c1_type *source)

{
  ushort flags;
  c1_type *pcVar1;
  c1_type *pcVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  ushort *type;
  c1_type *pcVar7;
  int iVar8;
  c1_symbol *pcVar9;
  byte bVar10;
  char cVar11;
  ushort *type2;
  ushort source_quals;
  ushort uVar12;
  ushort target_quals;
  c1_symbol *pcVar13;
  ushort *puVar14;
  int local_18;
  ushort local_14;
  ushort local_4;
  
  if (target == source) {
    return 1;
  }
  bVar5 = (byte)target->code;
  if (((target->code & 0x30) != 0) && ((source->code & 0x130) != 0)) {
    return 1;
  }
  local_18 = 1;
  pcVar1 = target;
  bVar3 = bVar5;
  while ((char)bVar3 < '\0') {
    pcVar1 = pcVar1->base;
    bVar3 = (byte)pcVar1->code;
  }
  bVar10 = (byte)source->code;
  pcVar2 = source;
  bVar3 = bVar10;
  while ((char)bVar3 < '\0') {
    pcVar2 = pcVar2->base;
    bVar3 = (byte)pcVar2->code;
  }
  if (((bVar5 & 0x8f) == 0x82) && (((byte)target->base->code >> 6 & 1) != 0)) {
    cVar4 = '\x01';
  }
  else {
    cVar4 = '\0';
  }
  if (((bVar10 & 0x8f) == 0x82) && (((byte)source->base->code >> 6 & 1) != 0)) {
    cVar11 = '\x01';
  }
  else {
    cVar11 = '\0';
  }
  if (cVar11 != cVar4) {
    pcVar7 = target;
    if (cVar4 != '\0') {
      pcVar7 = source;
    }
    uVar6 = pcVar7->code & 0x8f;
    if (((uVar6 == 0x83) || (uVar6 == 0x82)) || (uVar6 == 0x86)) {
      switch(op & 0xff) {
      case 0x34:
      case 0x70:
      case 0x74:
      case 0x7d:
        if (cVar11 != '\0') {
          diag_error(0x227);
          return 0;
        }
        iVar8 = conv_check_pointer_qualifiers(op,pcVar1->flags,pcVar2->flags,1);
        if (iVar8 == 0) {
          return 0;
        }
switchD_1048127c_caseD_3b:
        uVar6 = target->flags & 0x18;
        if (((uVar6 == 0x18) || (uVar6 == 8)) ||
           ((uVar6 = source->flags & 0x18, uVar6 == 0x18 || (uVar6 == 8)))) {
          conv_warn_different_bases(op,(byte *)target,(byte *)source);
        }
        return 1;
      default:
        return 1;
      case 0x3b:
      case 0x4c:
        goto switchD_1048127c_caseD_3b;
      case 0x3e:
      case 0x3f:
      case 0x44:
      case 0x45:
      case 0x46:
        diag_warning(3,0x85,op & 0xff,source,target);
        return 1;
      }
    }
  }
  bVar5 = type_derivations_equal(target,source);
  if (bVar5 == 0) {
    bVar5 = (byte)target->code;
    if (((char)bVar5 < '\0') && ((bVar5 & 0x8f) == 0x80)) {
      diag_error(0x73,op & 0xff);
      return 0;
    }
    if ((((char)op == 't') && (-1 < (char)bVar5)) && ((char)source->code < '\0')) {
      diag_error(0x1b8,0x74,target,source);
      return 0;
    }
    type = (ushort *)(-(uint)((char)bVar5 < '\0') & (uint)target);
    type2 = (ushort *)(-(uint)((source->code & 0x80) != 0) & (uint)source);
    bVar5 = (byte)local_14;
    do {
      puVar14 = type2;
      if (type == (ushort *)0x0) goto LAB_10417b24;
      bVar5 = (byte)local_14;
      puVar14 = (ushort *)0x0;
      if (type2 == (ushort *)0x0) goto LAB_10417b24;
      local_14 = *type2;
      local_4 = *type;
      uVar6 = type2[1];
      flags = type[1];
      pcVar7 = *(c1_type **)(type + 2);
      if (-1 < (char)pcVar7->code) {
        cVar4 = (char)target->code;
        pcVar7 = target;
        while (cVar4 < '\0') {
          pcVar7 = pcVar7->base;
          cVar4 = (char)pcVar7->code;
        }
      }
      target_quals = pcVar7->flags;
      pcVar7 = *(c1_type **)(type2 + 2);
      if (-1 < (char)pcVar7->code) {
        cVar4 = (char)source->code;
        pcVar7 = source;
        while (cVar4 < '\0') {
          pcVar7 = pcVar7->base;
          cVar4 = (char)pcVar7->code;
        }
      }
      source_quals = pcVar7->flags;
      if ((((byte)local_4 & 0x8f) == 0x83) &&
         (target_quals = target_quals | flags & 0x3e0, local_18 != 0)) {
        local_4 = 0x82;
      }
      if ((((byte)local_14 & 0x8f) == 0x83) &&
         (source_quals = source_quals | uVar6 & 0x3e0, local_18 != 0)) {
        local_14 = 0x82;
        local_14._0_1_ = 0x82;
      }
      bVar5 = (byte)local_14;
      if (((((byte)local_14 ^ (byte)local_4) & 0x8f) != 0) &&
         ((((local_18 == 0 || (((byte)local_4 & 0x8f) != 0x80)) || (((byte)local_14 & 0x8f) != 0x82)
           ) && ((((byte)local_4 & 0x8f) != 0x84 || (*type2 != 0x4086)))))) goto LAB_104814b0;
      uVar12 = local_4 & 0x8f;
      if ((uVar12 == 0x86) && (iVar8 = type_pointer_attributes_compatible(flags,uVar6), iVar8 == 0))
      {
        diag_error(0x98,op & 0xff);
        return 0;
      }
      if (((type[1] & 8) != 0) || ((type2[1] & 8) != 0)) {
        conv_warn_different_bases(op,(byte *)type,(byte *)type2);
      }
      cVar4 = (char)target->code;
      pcVar7 = target;
      while (cVar4 < '\0') {
        pcVar7 = pcVar7->base;
        cVar4 = (char)pcVar7->code;
      }
      iVar8 = conv_check_pointer_qualifiers(op,target_quals,source_quals,local_18);
      if (iVar8 == 0) {
        return 0;
      }
      if ((((iVar8 == 2) && (uVar12 != 0x86)) && ((uVar12 != 0x83 || ((bVar5 & 0x8f) != 0x83)))) &&
         (iVar8 = type_pointer_attributes_compatible(flags,uVar6), iVar8 == 0)) {
        diag_warning(1,0x2f,op & 0xff,target,source);
        return 0;
      }
      if (uVar12 == 0x83) {
        if (*(int *)(type + 4) != *(int *)(type2 + 4)) {
          diag_warning(1,0x30,target,source);
          return 0;
        }
      }
      else if (((*type & 0x83) == 0x81) &&
              (*(int *)(*(int *)(type + 4) + 0xc) != *(int *)(*(int *)(type2 + 4) + 0xc))) {
        diag_error(0x74);
      }
      local_18 = 0;
      type = (ushort *)(-(uint)((**(byte **)(type + 2) & 0x80) != 0) & (uint)*(byte **)(type + 2));
      type2 = (ushort *)
              (-(uint)((**(byte **)(type2 + 2) & 0x80) != 0) & (uint)*(byte **)(type2 + 2));
    } while (type != type2);
    puVar14 = (ushort *)0x0;
    type = (ushort *)0x0;
LAB_10417b24:
    if (type != puVar14) {
      if ((local_18 != 0) &&
         ((((pcVar2->code & 0x40) != 0 && (puVar14 == (ushort *)0x0)) ||
          (((pcVar1->code & 0x40) != 0 && (type == (ushort *)0x0)))))) {
        diag_error(0x78);
        return 0;
      }
      if ((((-1 < (char)target->code) && ((pcVar1->code & 0x10) == 0)) ||
          ((-1 < (char)source->code && ((pcVar2->code & 0x10) == 0)))) ||
         ((local_18 != 0 && ((((byte)local_4 & 0x8f) == 0x80 || ((bVar5 & 0x8f) == 0x82)))))) {
        diag_error(0x73,op & 0xff);
        return 0;
      }
LAB_104814b0:
      iVar8 = conv_report_indirection_levels(op,target,source);
      return iVar8;
    }
  }
  else {
    uVar6 = target->code;
    if (-1 < (char)uVar6) {
      if ((uVar6 & 0x300) == 0) {
        pcVar13 = (c1_symbol *)0x0;
      }
      else {
        pcVar13 = (target->extra).cls;
      }
      if ((source->code & 0x300) == 0) {
        pcVar9 = (c1_symbol *)0x0;
      }
      else {
        pcVar9 = (source->extra).cls;
      }
      if (pcVar13 == pcVar9) {
        return 1;
      }
      if ((((char)op == '6') && ((uVar6 & 0x100) != 0)) && ((source->code & 0x100) != 0)) {
        return 1;
      }
      diag_error(0x73,op & 0xff);
      return 0;
    }
    iVar8 = conv_check_pointer_qualifiers(op,pcVar1->flags,pcVar2->flags,1);
    if (iVar8 == 0) {
      return 0;
    }
  }
  if (pcVar1->code != pcVar2->code) {
    diag_error(0xe6,op & 0xff);
    return 0;
  }
  cVar4 = (char)target->code;
  while (cVar4 < '\0') {
    target = target->base;
    cVar4 = (char)target->code;
  }
  if ((target->code & 0x300) == 0) {
    pcVar13 = (c1_symbol *)0x0;
  }
  else {
    pcVar13 = (target->extra).cls;
  }
  cVar4 = (char)source->code;
  while (cVar4 < '\0') {
    source = source->base;
    cVar4 = (char)source->code;
  }
  if ((source->code & 0x300) == 0) {
    pcVar9 = (c1_symbol *)0x0;
  }
  else {
    pcVar9 = (source->extra).cls;
  }
  if (pcVar13 == pcVar9) {
    return 1;
  }
  iVar8 = conv_report_indirection_types(op);
  return iVar8;
}

