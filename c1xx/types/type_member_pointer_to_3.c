c1_type * __cdecl type_member_pointer_to_3(c1_type *type,int plain)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.debug_index = 0;
  local_10.code = (-(ushort)(plain != 1) & 0x4000) + 0x4086;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = type->flags;
  local_10.base = type->base;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

