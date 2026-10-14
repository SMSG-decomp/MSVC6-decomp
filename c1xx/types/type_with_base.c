c1_type * __thiscall type_with_base(c1_type *type,c1_type *base)

{
  c1_type local_10;
  
  if (type->base != base) {
    local_10.code = type->code;
    local_10.flags = type->flags;
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    local_10.base = base;
    type = type_intern(&local_10);
  }
  return type;
}

