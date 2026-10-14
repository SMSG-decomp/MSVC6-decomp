c1_type * __cdecl tmpl_normalize_argument_type(c1_type *type)

{
  c1_type *pcVar1;
  byte bVar2;
  bool bVar3;
  c1_type local_20;
  c1_type local_10;
  
  if (type == (c1_type *)0x0) {
    return (c1_type *)0x0;
  }
  bVar2 = (byte)type->code;
  if ((char)bVar2 < '\0') {
    bVar3 = (bVar2 & 0x8f) == 0x86;
    if (bVar3) {
      type = type->base;
    }
    bVar2 = (byte)type->code;
    if ((bVar2 & 0x83) == 0x81) {
      if ((bVar2 & 0x8f) == 0x85) {
        if ((((type->extra).cls)->flags5 & 1) != 0) {
          pcVar1 = type_function_map_parameters(type,type_params_drop_this);
          local_20.flags = pcVar1->flags;
          local_20.code = pcVar1->code & 0xfffb;
          local_20.extra = pcVar1->extra;
          local_20.base = pcVar1->base;
          local_20.debug_index = 0;
          type = type_intern(&local_20);
        }
      }
      else if (!bVar3) {
        return type;
      }
    }
    if (bVar3) {
      local_10.flags = (byte)type->flags & 0x1f;
      local_10.debug_index = 0;
      local_10.code = 0x86;
      local_10.extra.cls = (c1_symbol *)0x0;
      local_10.base = type;
      type = type_intern(&local_10);
    }
  }
  return type;
}

