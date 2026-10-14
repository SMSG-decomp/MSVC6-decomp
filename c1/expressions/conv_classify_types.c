int __cdecl conv_classify_types(c1_type *to,c1_type *from,int mode)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  byte bVar6;
  int iVar7;
  byte bVar8;
  
  if (to == from) {
    return 1;
  }
  iVar7 = conv_classify_pointer_types(to,from,mode);
  if (iVar7 != 0) {
    return iVar7;
  }
  uVar2 = to->code;
  uVar3 = from->code;
  bVar6 = (byte)uVar2;
  bVar8 = (byte)uVar3;
  if (((uVar2 & 0x4f0) == 0) || ((uVar3 & 0x4f0) == 0)) {
    pcVar4 = to;
    if ((uVar3 & 0x100) != 0) {
      if ((uVar2 & 0x100) != 0) {
        return (-(uint)((to->extra).sym != (from->extra).sym) & 0x1fff) + 1;
      }
      if ((bVar6 & 0x1f) == 0x13) {
        return 0x10;
      }
      if ((uVar2 & 0x30) != 0) {
        return 0x20;
      }
    }
    while (pcVar5 = from, (char)bVar6 < '\0') {
      bVar6 = (byte)pcVar4->base->code;
      pcVar4 = pcVar4->base;
    }
    while ((char)bVar8 < '\0') {
      bVar8 = (byte)pcVar5->base->code;
      pcVar5 = pcVar5->base;
    }
    if ((pcVar4->code == pcVar5->code) && ((to->extra).sym == (from->extra).sym)) {
      return 1;
    }
  }
  else {
    if (uVar3 == uVar2) {
      return 1;
    }
    if ((bVar8 >> 6 & 1) == 0) {
      if (((bVar8 >> 4 & 1) == 0) || ((bVar6 >> 4 & 1) == 0)) {
        if (((bVar8 >> 5 & 1) != 0) && ((bVar6 >> 5 & 1) != 0)) {
          cVar1 = (&g_type_rank_table)[uVar2 & 0xf];
          if (((&g_type_rank_table)[uVar3 & 0xf] == cVar1) &&
             (((bVar8 & 0x28) == 0x28) == ((bVar6 & 0x28) == 0x28))) {
            return 1;
          }
          if (((char)(&g_type_rank_table)[uVar3 & 0xf] < cVar1) && (cVar1 < '\t')) {
            return 0x10;
          }
        }
      }
      else if (((bVar6 & 0x1f) == 0x13) && ((uVar2 & 0x2000) == 0)) {
        if (((&g_type_rank_table)[uVar3 & 0xf] == (&g_type_rank_table)[uVar2 & 0xf]) &&
           (((uVar3 ^ uVar2) & 0x3000) == 0)) {
          return 0x10;
        }
        if ((char)(&g_type_rank_table)[uVar3 & 0xf] < '\x04') {
          return 0x10;
        }
      }
      return 0x20;
    }
  }
  iVar7 = conv_classify_types_fragment(0x2000);
  return iVar7;
}

