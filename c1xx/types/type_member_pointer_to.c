c1_type * __cdecl type_member_pointer_to(c1_type *type)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.debug_index = 0;
  local_10.code = 0x86;
  local_10.base = type->base;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = (byte)(local_10.base)->flags & 0x1f;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

