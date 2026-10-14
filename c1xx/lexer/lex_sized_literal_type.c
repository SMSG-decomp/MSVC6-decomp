c1_type * __cdecl lex_sized_literal_type(uint *value)

{
  c1_type *pcVar1;
  
  pcVar1 = g_type_int64;
  if (value[1] == 0) {
    if ((*value & 0x80000000) == 0) {
      return g_type_int32;
    }
    if (g_integral_max_bytes < 5) {
      pcVar1 = g_type_uint32;
    }
  }
  else {
    if ((value[1] & 0x80000000) == 0) {
      return g_type_int64;
    }
    if (g_integral_max_bytes < 9) {
      return g_type_uint64;
    }
  }
  return pcVar1;
}

