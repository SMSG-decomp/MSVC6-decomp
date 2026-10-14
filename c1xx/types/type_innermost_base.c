c1_type * __fastcall type_innermost_base(c1_type *type)

{
  char cVar1;
  
  cVar1 = (char)type->code;
  while (cVar1 < '\0') {
    type = type->base;
    cVar1 = (char)type->code;
  }
  return type;
}

