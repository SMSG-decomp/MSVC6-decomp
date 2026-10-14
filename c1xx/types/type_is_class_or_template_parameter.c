char __fastcall type_is_class_or_template_parameter(c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code;
  if ((uVar1 & 0x300) != 0) {
    return '\x01';
  }
  if ((-1 < (char)uVar1) && ((uVar1 & 0xfff) == 0x801)) {
    return '\x01';
  }
  return (uVar1 & 0xfff) == 0x802;
}

