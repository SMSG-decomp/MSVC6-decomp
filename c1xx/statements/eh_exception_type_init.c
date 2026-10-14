c1_catch_handler * __thiscall eh_exception_type_init(c1_catch_handler *rec,c1_type *type)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  ushort uVar6;
  c1_type *type_00;
  c1_type *pcVar7;
  c1_type *pcVar8;
  c1_type local_20;
  c1_type local_10;
  
  if (type->code == 0x80d) {
    rec->type = (c1_type *)0x0;
    rec->match_type = (c1_type *)0x0;
    rec->object_type = (c1_type *)0x0;
    rec->cv = 0;
    rec->flags = rec->flags & 0xfffffffe;
    return rec;
  }
  rec->type = type;
  bVar5 = (byte)type->code;
  if ((char)bVar5 < '\0') {
    if ((bVar5 & 0x8f) == 0x80) {
      rec->flags = rec->flags | 1;
    }
    else {
      rec->flags = rec->flags & 0xfffffffe;
      if (((byte)type->code & 0x8f) == 0x83) {
        type = type_array_to_pointer(type);
      }
      else if (type->code == 0x4082) {
        type = type_strip_code_variant_bits(type);
      }
    }
    if ((type->flags & 0x3e0) != 0) {
      uVar2._0_2_ = type->code;
      uVar2._2_2_ = type->flags;
      local_20._0_4_ = uVar2 & 0xfc1fffff;
      local_20.base = type->base;
      local_20.extra = type->extra;
      local_20.debug_index = type->debug_index;
      type = type_intern(&local_20);
    }
    type_00 = type->base;
    pcVar8 = type_00;
    while ((bVar5 = (byte)pcVar8->code, (bVar5 & 0x8f) == 0x83 || ((bVar5 & 0x83) == 0x81))) {
      pcVar8 = pcVar8->base;
    }
    pcVar7 = pcVar8;
    if ((pcVar8->code & 0x8f) == 0x83) {
      pcVar7 = type_skip_arrays(pcVar8->base);
    }
    uVar6 = pcVar7->flags & 0x3e0;
    rec->cv = uVar6;
    if (uVar6 != 0) {
      if (pcVar8 == type_00) {
        if (type_00->flags != 0) {
          uVar3._0_2_ = type_00->code;
          uVar3._2_2_ = type_00->flags;
          local_10._0_4_ = uVar3 & 0xffff;
          local_10.base = type_00->base;
          local_10.extra = type_00->extra;
          local_10.debug_index = type_00->debug_index;
          type_00 = type_intern(&local_10);
        }
      }
      else {
        type_00 = type_chain_rebuild(type_00,type_is_not_array,type_strip_cv,0);
      }
      if (type->base != type_00) {
        local_10.code = type->code;
        local_10.flags = type->flags;
        local_10.extra = type->extra;
        local_10.debug_index = type->debug_index;
        local_10.base = type_00;
        type = type_intern(&local_10);
      }
    }
    rec->match_type = type;
    if ((((rec->flags & 1) != 0) && (type = type->base, -1 < (char)type->code)) &&
       (type->flags != 0)) {
      uVar4._0_2_ = type->code;
      uVar4._2_2_ = type->flags;
      local_10._0_4_ = uVar4 & 0xffff;
      local_10.base = type->base;
      local_10.extra = type->extra;
      local_10.debug_index = type->debug_index;
      type_intern(&local_10);
    }
    rec->object_type = type;
    return rec;
  }
  rec->flags = rec->flags & 0xfffffffe;
  if (type->flags != 0) {
    uVar1._0_2_ = type->code;
    uVar1._2_2_ = type->flags;
    local_20._0_4_ = uVar1 & 0xffff;
    local_20.base = type->base;
    local_20.extra = type->extra;
    local_20.debug_index = type->debug_index;
    type = type_intern(&local_20);
  }
  rec->cv = 0;
  rec->match_type = type;
  rec->object_type = type;
  return rec;
}

