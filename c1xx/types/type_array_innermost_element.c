c1_type * __fastcall type_array_innermost_element(c1_type *array_type)

{
  do {
    array_type = type_base(array_type);
  } while ((array_type->code & 0x8f) == 0x83);
  return array_type;
}

