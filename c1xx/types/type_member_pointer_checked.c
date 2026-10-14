c1_type * __cdecl type_member_pointer_checked(c1_type *type)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.debug_index = 0;
  local_10.code = 0x4086;
  local_10.flags = decl_apply_default_calling_convention(0x4086,(byte)type->flags & 0x1f);
  local_10.base = type;
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

