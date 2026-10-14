bool __cdecl type_is_not_array(c1_type *type)

{
  return (type->code & 0x8f) != 0x83;
}

