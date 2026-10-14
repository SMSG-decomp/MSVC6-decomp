c1_type * __thiscall type_without_flags(c1_type *type,ushort clear_bits)

{
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  if ((type->flags & clear_bits) != 0) {
    type_code = type->code;
    type_flags = type->flags;
    local_10.base = type->base;
    local_10.flags = type_flags & ~clear_bits;
    local_10.code = type_code;
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    type = type_intern(&local_10);
  }
  return type;
}

