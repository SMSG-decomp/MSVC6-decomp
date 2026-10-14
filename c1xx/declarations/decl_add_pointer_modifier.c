void __thiscall decl_add_pointer_modifier(void *decl,ushort *mods,ushort *extra)

{
  ushort uVar1;
  ushort uVar2;
  c1_u8 *pcVar3;
  
  uVar1 = *extra;
  uVar2 = *mods;
  if ((uVar2 & 7) != 0) {
    *(byte *)((int)decl + 0x14) = *(byte *)((int)decl + 0x14) | 1;
  }
  pcVar3 = record_pos_new(0x82,uVar2 | uVar1,(int *)(mods + 2));
  if (*(int *)((int)decl + 8) != 0) {
    *(c1_u8 **)(*(int *)((int)decl + 8) + 4) = pcVar3;
    *(c1_u8 **)((int)decl + 8) = pcVar3;
    return;
  }
  *(c1_u8 **)((int)decl + 8) = pcVar3;
  *(c1_u8 **)((int)decl + 4) = pcVar3;
  return;
}

