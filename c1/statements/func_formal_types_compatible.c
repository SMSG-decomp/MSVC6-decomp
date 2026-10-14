int __cdecl func_formal_types_compatible(c1_type *declared,c1_type *defined)

{
  char cVar1;
  int iVar2;
  
  if (declared->code == 0x80d) {
    if (defined->code == 0x80d) {
      return 1;
    }
    if (g_ms_extensions != '\0') {
      diag_warning(4,0xd4);
      return 1;
    }
  }
  else if ((((defined->code != 0x80d) && ((char)declared->code < '\0')) &&
           (iVar2 = type_is_pointer_to_void(declared), iVar2 != 0)) &&
          (iVar2 = type_modifier_depth_at_most(declared,defined), iVar2 != 0)) {
    cVar1 = (char)declared->code;
    while (cVar1 < '\0') {
      declared = declared->base;
      cVar1 = (char)declared->code;
    }
    cVar1 = (char)defined->code;
    while (cVar1 < '\0') {
      defined = defined->base;
      cVar1 = (char)defined->code;
    }
    if (((declared->flags & 0x1f) == 0) && ((defined->flags & 0x1f) == 0)) {
      return 1;
    }
    iVar2 = type_modifier_bits_match(declared->flags,defined->flags);
    return iVar2;
  }
  return 0;
}

