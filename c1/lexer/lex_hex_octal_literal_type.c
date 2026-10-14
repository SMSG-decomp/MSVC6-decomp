c1_type * __cdecl lex_hex_octal_literal_type(uint *value)

{
  c1_type *pcVar1;
  
  if ((*value & 0x80000000) == 0 && value[1] == 0) {
    return g_type_int;
  }
  if (value[1] == 0) {
    return g_type_unsigned_int;
  }
  if (((g_opt_ZBe != '\0') || (pcVar1 = g_type_unsigned_long, 4 < g_integral_max_bytes)) &&
     (pcVar1 = g_type_uint64, (value[1] & 0x80000000) == 0)) {
    return g_type_int64;
  }
  return pcVar1;
}

