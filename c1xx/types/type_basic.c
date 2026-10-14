c1_type * __cdecl type_basic(ushort code)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.code = code;
  local_10.flags = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  if ((code & 0x40) == 0) {
    return pcVar1;
  }
  local_10.debug_index = 0;
  local_10.code = 0x82;
  local_10.flags = decl_apply_default_calling_convention(0x82,0);
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = pcVar1;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

