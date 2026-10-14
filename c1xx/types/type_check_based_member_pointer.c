c1_u16 __thiscall type_check_based_member_pointer(c1_decl_record *rec,c1_u16 modifiers,c1_u16 cv)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (modifiers != 0) {
    uVar1 = modifiers;
    if ((modifiers & 8) != 0) {
      diag_error(0x27e,rec->sym);
      uVar1 = modifiers & 0xffe7;
      rec->flags = rec->flags | 1;
    }
    if ((uVar1 & 7) != 0) {
      rec->layer_flags = rec->layer_flags | 1;
    }
  }
  return uVar1 | cv;
}

