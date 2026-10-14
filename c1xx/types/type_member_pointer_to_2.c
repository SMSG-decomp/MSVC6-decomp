c1_type * __thiscall type_member_pointer_to_2(c1_type *type,char variant)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.code = 0x86;
  if (variant != '\0') {
    local_10.code = 0x4086;
  }
  local_10.flags = (byte)type->flags & 0x1f;
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = type;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

