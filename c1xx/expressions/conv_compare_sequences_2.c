int __thiscall
conv_compare_sequences_2(c1_conversion *conv_a,c1_conversion *conv_b,char source_side)

{
  ushort uVar1;
  c1_vector *pcVar2;
  c1_vector *pcVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  ushort uVar7;
  c1_type *type;
  c1_type *type_00;
  int iVar8;
  int iVar9;
  short sVar10;
  short sVar11;
  
  if (source_side == '\0') {
    type = conv_a->target;
    bVar4 = (byte)type->code;
    if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x80)) {
      type = type_base(type);
    }
    type_00 = conv_b->target;
    bVar4 = (byte)type_00->code;
    if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x80)) {
      type_00 = type_base(type_00);
    }
    cVar5 = type_compare(type,type_00,2);
  }
  else {
    cVar5 = type_compare(conv_a->source,conv_b->source,2);
  }
  if (cVar5 != '\0') {
    bVar4 = conv_a->flags4e;
    if (((conv_b->flags4e ^ bVar4) & 2) != 0) {
      return (-(uint)((bVar4 & 2) != 0) & 0xfffffffe) + 1;
    }
    if ((bVar4 & 2) != 0) {
      uVar1 = conv_b->cv_added;
      uVar6 = conv_a->cv_added & uVar1;
      if (conv_a->cv_added != uVar6) {
        return (uVar1 != uVar6) - 1;
      }
      if (uVar1 == uVar6) {
        if ((conv_a->flags4f & 1) == 0) {
          return 0;
        }
        pcVar2 = (conv_b->via).cv_levels;
        pcVar3 = (conv_a->via).cv_levels;
        sVar10 = 0;
        sVar11 = 0;
        do {
          if (pcVar3 == (c1_vector *)0x0) {
            return 0;
          }
          iVar8 = (int)sVar10;
          if ((int)(uint)pcVar3->count <= iVar8) {
            return 0;
          }
          sVar10 = sVar10 + 1;
          if (pcVar2 == (c1_vector *)0x0) {
            return 0;
          }
          iVar9 = (int)sVar11;
          if ((int)(uint)pcVar2->count <= iVar9) {
            return 0;
          }
          sVar11 = sVar11 + 1;
          uVar1 = (ushort)pcVar2->data[iVar9];
          uVar6 = (ushort)pcVar3->data[iVar8];
          uVar7 = uVar1 & uVar6;
          if (uVar6 != uVar7) {
            return (uVar1 != uVar7) - 1;
          }
        } while (uVar1 == uVar7);
      }
      return 1;
    }
  }
  return 0;
}

