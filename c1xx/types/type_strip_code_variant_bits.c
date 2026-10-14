c1_type * __fastcall type_strip_code_variant_bits(c1_type *type)

{
  uint uVar1;
  c1_type local_10;
  
  if ((type->code & 0xe000) != 0) {
    uVar1._0_2_ = type->code;
    uVar1._2_2_ = type->flags;
    local_10.base = type->base;
    local_10.extra = type->extra;
    local_10._0_4_ = uVar1 & 0xffff008f;
    local_10.debug_index = type->debug_index;
    type = type_intern(&local_10);
  }
  return type;
}

