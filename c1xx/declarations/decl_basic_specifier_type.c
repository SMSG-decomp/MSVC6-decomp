c1_type * __cdecl decl_basic_specifier_type(ushort basic_type,c1_u16 cv)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.code = basic_type;
  if (((basic_type & 0xfff) != 0x11) && ((basic_type & 0xfff) == 0)) {
    local_10.code = basic_type | 0x13;
  }
  if (((local_10.code & 0x3000) != 0) && ((local_10.code & 0xfff) != 0x11)) {
    local_10.code = local_10.code & 0xefff;
  }
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = cv;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

