uint __thiscall class_member_natural_alignment(c1_type *type,uint pack)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  
  bVar1 = (byte)type->code;
  while ((bVar1 & 0x8f) == 0x83) {
    type = type->base;
    bVar1 = (byte)type->code;
  }
  uVar2 = type->code;
  if (-1 < (char)uVar2) {
    if (((uVar2 & 0x130) != 0) && ((uint)(int)(char)(&g_type_rank_table)[uVar2 & 0xf] < pack)) {
      return (int)(char)(&g_type_rank_table)[uVar2 & 0xf];
    }
    if ((uVar2 & 0x200) != 0) {
      return (uint)(byte)((type->extra).sym)->tag_alignment;
    }
  }
  uVar3 = type_size(type);
  return uVar3;
}

