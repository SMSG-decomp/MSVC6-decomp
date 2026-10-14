int __cdecl debug_cv_primitive_pointer_index(c1_type *type)

{
  ushort code;
  uint uVar1;
  
  if ((type->code & 0x8f) == 0x82) {
    code = type->base->code;
    if (((-1 < (char)code) && ((type->flags & 0x1e8) == 0)) && ((type->base->flags & 0x3e0) == 0)) {
      uVar1 = debug_cv_primitive_type_index(code);
      if (uVar1 != 0) {
        return uVar1 & 0xfffffcff | 0x400;
      }
    }
  }
  return 0;
}

