c1_type * __cdecl decl_basic_type_from_specifiers(c1_u16 code,c1_u16 flags)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.code = code;
  if ((code & 0xfff) == 0x11) {
    if ((g_ms_extensions != '\0') && (g_opt_J_unsigned_char != '\0')) {
      pcVar1 = decl_basic_type_from_specifiers_fragment(code);
      return pcVar1;
    }
  }
  else if ((code & 0xfff) == 0) {
    local_10.code = code | 0x13;
  }
  if (((local_10.code & 0x3000) != 0) &&
     ((g_ms_extensions != '\0' || ((local_10.code & 0xfff) != 0x11)))) {
    local_10.code = local_10.code & 0xefff;
  }
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.flags = flags;
  local_10.extra.sym = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

