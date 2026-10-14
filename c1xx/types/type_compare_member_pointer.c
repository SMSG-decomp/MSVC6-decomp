char __thiscall type_compare_member_pointer(c1_type *a,c1_type *b,uint flags)

{
  char cVar1;
  c1_type *type;
  c1_type *type_00;
  
  if (a == b) {
    return '\x01';
  }
  if (a->code == 0x4083) {
    if (b->code != 0x4083) {
      return '\0';
    }
  }
  else {
    if (b->code == 0x4083) {
      return '\0';
    }
    if ((a->extra).cls != (b->extra).cls) {
      return '\0';
    }
  }
  type = type_base(a);
  type_00 = type_base(b);
  if ((flags & 2) != 0) {
    type = type_strip_cv_qualifiers(type);
    type_00 = type_strip_cv_qualifiers(type_00);
  }
  cVar1 = type_compare(type,type_00,flags & 0xfffffffd);
  return cVar1;
}

