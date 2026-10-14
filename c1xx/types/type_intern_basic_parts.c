c1_type * __cdecl type_intern_basic_parts(c1_u16 code,c1_u16 flags,c1_u32 extra)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.flags = flags;
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.extra.count = extra;
  local_10.code = code;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

