int __fastcall type_is_class_or_enum(c1_type *type)

{
  if ((type->code & 0x300) == 0) {
    return 0;
  }
  return 1;
}

