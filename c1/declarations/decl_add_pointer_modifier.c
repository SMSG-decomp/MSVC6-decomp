void __thiscall decl_add_pointer_modifier(c1_type_declarator *declarator,ushort *mods,ushort *extra)

{
  ushort uVar1;
  ushort uVar2;
  c1_type *pcVar3;
  
  uVar1 = *extra;
  uVar2 = *mods;
  if ((uVar2 & 7) != 0) {
    declarator->flags14 = declarator->flags14 | 1;
  }
  pcVar3 = (c1_type *)record_pos_new(0x82,uVar2 | uVar1,(int *)(mods + 2));
  if (declarator->last == (c1_type *)0x0) {
    declarator->last = pcVar3;
    declarator->first = pcVar3;
    return;
  }
  declarator->last->base = pcVar3;
  declarator->last = pcVar3;
  return;
}

