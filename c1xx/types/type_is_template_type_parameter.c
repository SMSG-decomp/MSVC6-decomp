int __fastcall type_is_template_type_parameter(c1_type *type)

{
  if ((-1 < (char)type->code) && ((type->code & 0xfff) == 0x801)) {
    return 1;
  }
  return 0;
}

