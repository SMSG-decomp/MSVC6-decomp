c1_type * __fastcall type_strip_cv_qualifiers(c1_type *type)

{
  uint uVar1;
  c1_type local_10;
  
  if ((type->flags & 0x1e0) != 0) {
    uVar1._0_2_ = type->code;
    uVar1._2_2_ = type->flags;
    local_10.base = type->base;
    local_10.extra = type->extra;
    local_10._0_4_ = uVar1 & 0xfe1fffff;
    local_10.debug_index = type->debug_index;
    type = type_intern(&local_10);
  }
  return type;
}

