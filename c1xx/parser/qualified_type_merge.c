void __thiscall qualified_type_merge(c1_decl_modifier *mods,c1_decl_modifier *other,c1_u32 eax_high)

{
  uint uVar1;
  
  uVar1 = type_merge_qualifiers
                    (CONCAT22((short)((uint)mods >> 0x10),(short)mods->bits),
                     CONCAT22((short)(eax_high >> 0x10),(short)other->bits));
  *(short *)&mods->bits = (short)uVar1;
  if (mods->based == (void *)0x0) {
    mods->based = other->based;
  }
  return;
}

