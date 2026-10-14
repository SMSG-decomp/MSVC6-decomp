c1_type * __cdecl type_strip_cv(c1_type *type)

{
  uint uVar1;
  c1_type cStack_10;
  
  if ((type->flags & 0x3e0) != 0) {
    uVar1._0_2_ = type->code;
    uVar1._2_2_ = type->flags;
    cStack_10.base = type->base;
    cStack_10.extra = type->extra;
    cStack_10._0_4_ = uVar1 & 0xfc1fffff;
    cStack_10.debug_index = type->debug_index;
    type = type_intern(&cStack_10);
  }
  return type;
}

