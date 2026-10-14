ushort __thiscall decl_check_varargs_calling_convention(void *rec,c1_type *type,ushort flags)

{
  ushort uVar1;
  
  if ((type->flags & 0x8000) == 0) {
    return flags;
  }
  uVar1 = flags & 7;
  if ((uVar1 != 5) && (uVar1 != 3)) {
    if (uVar1 == 4) {
      return flags;
    }
    if (uVar1 == 1) {
      return flags;
    }
    diag_error(0xd9,0x25,0x6a);
  }
  return 1;
}

