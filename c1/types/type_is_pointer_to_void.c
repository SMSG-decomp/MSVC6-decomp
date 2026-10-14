int __cdecl type_is_pointer_to_void(c1_type *type)

{
  c1_u16 cVar1;
  
  cVar1 = type->code;
  if ((char)cVar1 < '\0') {
    while( true ) {
      type = type->base;
      if ((((byte)cVar1 & 0x83) == 0x81) && (-1 < (char)type->code)) break;
      cVar1 = type->code;
      if (-1 < (char)(byte)cVar1) {
        return (byte)((byte)cVar1 >> 6) & 1;
      }
    }
  }
  return 0;
}

