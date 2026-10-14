uint * __cdecl type_strip_modifier_bits(uint *type)

{
  c1_type local_10;
  
  if ((*type & 0x3e00000) != 0) {
    local_10.base = (c1_type *)type[1];
    local_10.extra = *(c1_type_extra *)(type + 2);
    local_10._0_4_ = *type & 0xfc1fffff;
    local_10.debug_index = type[3];
    type = (uint *)type_intern(&local_10);
  }
  return type;
}

