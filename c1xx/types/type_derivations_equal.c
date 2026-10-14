byte __thiscall type_derivations_equal(c1_type *type,c1_type *type2)

{
  byte bVar1;
  
  if (type == type2) {
    return 1;
  }
  while( true ) {
    if (-1 < (char)type->code) {
      return (byte)~(byte)type2->code >> 7;
    }
    if ((((-1 < (char)type2->code) || (type->code != type2->code)) || (type->flags != type2->flags))
       || ((type->extra).cls != (type2->extra).cls)) break;
    type2 = type2->base;
    type = type->base;
    if (type == type2) {
      bVar1 = type_derivations_equal_tail(type);
      return bVar1;
    }
  }
  return 0;
}

