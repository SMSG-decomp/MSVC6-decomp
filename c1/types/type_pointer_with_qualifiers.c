c1_type * __thiscall type_pointer_with_qualifiers(c1_type *type,ushort flags)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  if ((type->code & 0x83) == 0x81) {
    flags = flags | (byte)type->flags & 7;
    local_10.code = 0x86;
  }
  else {
    local_10.code = 0x82;
  }
  local_10.debug_index = 0;
  local_10.flags = flags;
  local_10.extra.sym = (c1_symbol *)0x0;
  local_10.base = type;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

