c1_type * __thiscall type_add_flags(c1_type *type,ushort bits)

{
  undefined2 uVar1;
  undefined2 uVar2;
  c1_type local_10;
  
  if ((type->flags & bits) != bits) {
    uVar1 = type->code;
    uVar2 = type->flags;
    local_10.base = type->base;
    local_10.flags = uVar2 | bits;
    local_10.code = uVar1;
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    type = type_intern(&local_10);
  }
  return type;
}

