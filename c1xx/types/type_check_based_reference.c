ushort __thiscall type_check_based_reference(c1_decl_record *decl,ushort modifiers)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (modifiers != 0) {
    uVar1 = modifiers;
    if ((modifiers & 8) != 0) {
      diag_error(0x280,decl->sym);
      uVar1 = modifiers & 0xffe7;
      decl->flags = decl->flags | 1;
    }
    if ((uVar1 & 7) != 0) {
      decl->layer_flags = decl->layer_flags | 1;
    }
  }
  return uVar1;
}

