c1_type * __thiscall type_with_qualifier_bits(c1_type *type,ushort bits)

{
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  if (((byte)type->flags & 7) != bits) {
    type_code = type->code;
    type_flags = type->flags;
    local_10.base._0_2_ = SUB42(type->base,0);
    local_10.base._2_2_ = (undefined2)((uint)type->base >> 0x10);
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    local_10.flags = type_flags & 0xfff8 | bits;
    local_10.code = type_code;
    type = type_intern(&local_10);
  }
  return type;
}

