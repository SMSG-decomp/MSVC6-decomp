c1_u8 __fastcall type_is_void(c1_type *type)

{
  return (c1_u8)(((byte)type->code & 0x40) >> 6);
}

