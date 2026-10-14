c1_type * __cdecl type_pointer_to(c1_u16 pointer_flags)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.code = 0x82;
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = pointer_flags;
  local_10.base = g_type_void;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

