c1_type * __thiscall type_with_added_qualifiers(c1_type *type,ushort bits)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  c1_type *replacement;
  c1_type *pcVar4;
  c1_type local_10;
  
  pcVar4 = type;
  if ((type->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(type->base);
  }
  bVar3 = (byte)pcVar4->code;
  if ((((-1 < (char)bVar3) || ((bVar3 & 0x8f) != 0x80)) && ((bVar3 & 0x83) != 0x81)) &&
     ((pcVar4->flags & bits) != bits)) {
    uVar1 = pcVar4->code;
    uVar2 = pcVar4->flags;
    local_10.flags = uVar2 | bits;
    local_10.code = uVar1;
    local_10.base = pcVar4->base;
    local_10.extra = pcVar4->extra;
    local_10.debug_index = pcVar4->debug_index;
    replacement = type_intern(&local_10);
    if (replacement != pcVar4) {
      pcVar4 = type_replace_in_chain(type,pcVar4,replacement);
      return pcVar4;
    }
  }
  return type;
}

