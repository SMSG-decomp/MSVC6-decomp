c1_type * __thiscall type_with_qualifier_bits(c1_type *type,ushort bits)

{
  undefined2 uVar1;
  undefined2 uVar2;
  c1_type local_10;
  
  if (((byte)type->flags & 7) != bits) {
    uVar1 = type->code;
    uVar2 = type->flags;
    local_10.base._0_2_ = SUB42(type->base,0);
    local_10.base._2_2_ = (undefined2)((uint)type->base >> 0x10);
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    local_10.flags = uVar2 & 0xfff8 | bits;
    local_10.code = uVar1;
    type = type_intern(&local_10);
  }
  return type;
}

