c1_type * __fastcall type_skip_arrays_and_functions(c1_type *type)

{
  byte bVar1;
  
  while ((bVar1 = (byte)type->code, (bVar1 & 0x8f) == 0x83 || ((bVar1 & 0x83) == 0x81))) {
    type = type->base;
  }
  return type;
}

