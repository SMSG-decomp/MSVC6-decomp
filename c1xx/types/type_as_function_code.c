c1_type * __fastcall type_as_function_code(c1_type *type)

{
  c1_type local_10;
  undefined4 code_flags;
  
  if (type->code != 0x81) {
    code_flags._0_2_ = type->code;
    code_flags._2_2_ = type->flags;
    local_10.base = type->base;
    local_10.extra = type->extra;
    local_10.debug_index = type->debug_index;
    local_10.flags = code_flags._2_2_;
    local_10.code = (c1_u16)CONCAT31((uint3)((uint)code_flags >> 8) & 0xc0,0x81);
    type = type_intern(&local_10);
  }
  return type;
}

