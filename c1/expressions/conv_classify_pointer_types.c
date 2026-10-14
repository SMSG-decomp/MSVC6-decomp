int __cdecl conv_classify_pointer_types(c1_type *to,c1_type *from,int mode)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  c1_type *pcVar6;
  c1_type *pcVar7;
  c1_type *pcVar8;
  c1_type *pcVar9;
  uint uVar10;
  
  cVar1 = (char)to->code;
  pcVar6 = (c1_type *)(-(uint)(cVar1 < '\0') & (uint)to);
  cVar2 = (char)from->code;
  pcVar9 = (c1_type *)(-(uint)(cVar2 < '\0') & (uint)from);
  pcVar7 = to;
  if ((pcVar6 == (c1_type *)0x0) && (pcVar9 == (c1_type *)0x0)) {
    return 0;
  }
  while (cVar1 < '\0') {
    cVar1 = (char)pcVar7->base->code;
    pcVar7 = pcVar7->base;
  }
  pcVar8 = from;
  while (cVar2 < '\0') {
    pcVar8 = pcVar8->base;
    cVar2 = (char)pcVar8->code;
  }
  uVar10 = 1;
  if (pcVar6 != (c1_type *)0x0) {
    uVar3 = pcVar6->code;
    if (((pcVar7->code & 0x40) != 0) && (((byte)uVar3 & 0x83) != 0x81)) {
      uVar10 = conv_rank_to_void_pointer(1,pcVar6,pcVar9);
    }
    if ((pcVar9 != (c1_type *)0x0) &&
       ((uVar4 = pcVar9->code, uVar10 == 0x100 ||
        ((-(uint)((pcVar6->base->code & 0x80) != 0) & (uint)pcVar6->base) ==
         ((uint)pcVar9->base & -(uint)((pcVar9->base->code & 0x80) != 0)))))) {
      if (((char)pcVar6->code < '\0') && (-1 < (char)pcVar6->base->code)) {
        if ((uVar10 == 0x100) && ((char)from->code < '\0')) {
          pcVar7 = from->base;
          pcVar8 = from;
          if ((-1 < (char)pcVar7->code) || (pcVar7 == (c1_type *)0x0)) {
            do {
              pcVar7 = pcVar8->base;
              pcVar8 = pcVar7;
            } while ((char)pcVar7->code < '\0');
          }
        }
        else {
          cVar1 = (char)from->code;
          pcVar7 = from;
          while (cVar1 < '\0') {
            pcVar7 = pcVar7->base;
            cVar1 = (char)pcVar7->code;
          }
        }
        cVar1 = (char)to->code;
        pcVar8 = to;
        while (cVar1 < '\0') {
          pcVar8 = pcVar8->base;
          cVar1 = (char)pcVar8->code;
        }
        uVar10 = conv_compare_pointee_qualifiers(mode,uVar10,pcVar8->flags,pcVar7->flags);
        if ((uVar10 & 0x2000) != 0) {
          if (((byte)g_compile_flags_c8 & 1) == 0) {
            return 0x2000;
          }
          if (((uVar10 & 0x1fff) != 5) && ((uVar10 & 0x1fff) != 6)) {
            return 0x2000;
          }
          uVar10 = 1;
        }
      }
      else {
        cVar1 = (char)to->code;
        pcVar7 = to;
        while (cVar1 < '\0') {
          pcVar7 = pcVar7->base;
          cVar1 = (char)pcVar7->code;
        }
        cVar1 = (char)from->code;
        pcVar8 = from;
        while (cVar1 < '\0') {
          pcVar8 = pcVar8->base;
          cVar1 = (char)pcVar8->code;
        }
        if (((pcVar8->flags ^ pcVar7->flags) & 0x3e0) != 0) {
          return 0x2000;
        }
      }
      uVar10 = conv_rank_based_pointers(uVar10,(c1_u8)pcVar6->flags,(c1_u8)pcVar9->flags);
      if ((uVar10 & 0x2000) == 0) {
        if ((((byte)uVar4 ^ (byte)uVar3) & 0x8f) == 0) {
          if ((((uVar3 & 0x8f) == 0x83) && ((pcVar6->extra).sym != (c1_symbol *)0x0)) &&
             ((pcVar6->extra).sym != (pcVar9->extra).sym)) {
            return 0x2000;
          }
        }
        else {
          uVar5 = uVar3 & 0x8f;
          if (((uVar5 == 0x82) && (((byte)uVar4 & 0x8f) == 0x83)) ||
             (((uVar4 & 0x8f) == 0x82 && (uVar5 == 0x83)))) {
            if (uVar10 == 1) {
              uVar10 = 2;
            }
            else {
              uVar10 = uVar10 | 2;
            }
          }
          else {
            if (((uVar5 == 0x82) && ((uVar4 & 0x8f) == 0x86)) && ((uVar10 & 0x100) != 0)) {
              return 0x2000;
            }
            if (uVar5 != 0x84) {
              return 0x2000;
            }
            if (from->code != 0x4086) {
              return 0x2000;
            }
          }
        }
        if ((((uVar3 & 0x8f) == 0x86) || ((to->code & 0x83) == 0x81)) &&
           (((uVar4 & 0x8f) == 0x86 || ((from->code & 0x83) == 0x81)))) {
          if ((uVar3 & 0x8f) == 0x86) {
            pcVar6 = pcVar6->base;
          }
          if ((uVar4 & 0x8f) == 0x86) {
            pcVar9 = pcVar9->base;
          }
          if (((pcVar6->extra).params)->types != ((pcVar9->extra).params)->types) {
            return 0x2000;
          }
          if (pcVar6->flags != pcVar9->flags) {
            return 0x2000;
          }
        }
        cVar1 = (char)to->code;
        pcVar6 = to;
        while (cVar1 < '\0') {
          pcVar6 = pcVar6->base;
          cVar1 = (char)pcVar6->code;
        }
        cVar1 = (char)from->code;
        pcVar9 = from;
        while (cVar1 < '\0') {
          pcVar9 = pcVar9->base;
          cVar1 = (char)pcVar9->code;
        }
        if ((pcVar6->code == pcVar9->code) && ((to->extra).sym == (from->extra).sym)) {
          return uVar10;
        }
        if ((uVar10 & 0x100) != 0) {
          return uVar10;
        }
      }
    }
  }
  return 0x2000;
}

