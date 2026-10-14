c1_u8 __thiscall type_derivations_equal(c1_type *type,c1_type *type2)

{
  c1_u8 cVar1;
  
  if (type == type2) {
    return '\x01';
  }
  while( true ) {
    if (-1 < (char)type->code) {
      return (byte)~(byte)type2->code >> 7;
    }
    if ((((-1 < (char)type2->code) || (type->code != type2->code)) || (type->flags != type2->flags))
       || ((type->extra).sym != (type2->extra).sym)) break;
    type2 = type2->base;
    type = type->base;
    if (type == type2) {
      cVar1 = type_derivations_equal_fragment();
      return cVar1;
    }
  }
  return '\0';
}

