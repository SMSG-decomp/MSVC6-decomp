c1_type * __thiscall type_strip_qualifiers_unless_all(c1_type *type,c1_u16 bits)

{
  uint uVar1;
  byte bVar2;
  c1_type *replacement;
  c1_type *pcVar3;
  c1_type local_10;
  
  pcVar3 = type;
  if ((type->code & 0x8f) == 0x83) {
    pcVar3 = type_skip_arrays(type->base);
  }
  bVar2 = (byte)pcVar3->code;
  if ((((-1 < (char)bVar2) || ((bVar2 & 0x8f) != 0x80)) && ((bVar2 & 0x83) != 0x81)) &&
     ((((pcVar3->flags & 0x3e0) != 0 && (bits != 0)) && ((pcVar3->flags & bits) != bits)))) {
    uVar1._0_2_ = pcVar3->code;
    uVar1._2_2_ = pcVar3->flags;
    local_10._0_4_ = uVar1 & 0xfc1fffff;
    local_10.base = pcVar3->base;
    local_10.extra = pcVar3->extra;
    local_10.debug_index = pcVar3->debug_index;
    replacement = type_intern(&local_10);
    if (replacement != pcVar3) {
      pcVar3 = type_replace_in_chain(type,pcVar3,replacement);
      return pcVar3;
    }
  }
  return type;
}

