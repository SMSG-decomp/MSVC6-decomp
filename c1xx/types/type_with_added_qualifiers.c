c1_type * __thiscall type_with_added_qualifiers(c1_type *type,ushort bits)

{
  byte bVar1;
  c1_type *replacement;
  c1_type *pcVar2;
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  pcVar2 = type;
  if ((type->code & 0x8f) == 0x83) {
    pcVar2 = type_skip_arrays(type->base);
  }
  bVar1 = (byte)pcVar2->code;
  if ((((-1 < (char)bVar1) || ((bVar1 & 0x8f) != 0x80)) && ((bVar1 & 0x83) != 0x81)) &&
     ((pcVar2->flags & bits) != bits)) {
    type_code = pcVar2->code;
    type_flags = pcVar2->flags;
    local_10.flags = type_flags | bits;
    local_10.code = type_code;
    local_10.base = pcVar2->base;
    local_10.extra = pcVar2->extra;
    local_10.debug_index = pcVar2->debug_index;
    replacement = type_intern(&local_10);
    if (replacement != pcVar2) {
      pcVar2 = type_replace_in_chain(type,pcVar2,replacement);
      return pcVar2;
    }
  }
  return type;
}

