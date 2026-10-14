void __fastcall type_check_declarator_kind(c1_declarator *d)

{
  byte bVar1;
  
  bVar1 = (byte)d->type->code;
  if ((bVar1 & 0x83) == 0x81) {
    type_check_function_cast_and_bitfield(d);
    return;
  }
  if ((bVar1 & 0x8f) != 0x83) {
    bVar1 = (byte)d->type->code;
    if (((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x80)) {
      type_check_reference_to_bitfield(d);
    }
    return;
  }
  type_check_array_bound_constant(d);
  return;
}

