c1_type * __cdecl lex_decimal_literal_type(uint *value)

{
  c1_type *pcVar1;
  
  if ((*value & 0x80000000) == 0 && value[1] == 0) {
    return g_type_int;
  }
  if (g_opt_ZBe == '\0') {
    if ((value[1] != 0) && (4 < g_integral_max_bytes)) {
      pcVar1 = lex_sized_literal_type(value);
      return pcVar1;
    }
    return g_type_unsigned_long;
  }
  pcVar1 = lex_sized_literal_type(value);
  return pcVar1;
}

