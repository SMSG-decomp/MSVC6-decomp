c1_type * __cdecl lex_unsigned_literal_type(uint *value)

{
  c1_type *pcVar1;
  
  if (value[1] == 0) {
    return g_type_unsigned_int;
  }
  if (g_opt_ZBe == '\0') {
    if (g_integral_max_bytes < 5) {
      return g_type_unsigned_long;
    }
    pcVar1 = lex_sized_unsigned_literal_type(value);
    return pcVar1;
  }
  pcVar1 = lex_sized_unsigned_literal_type(value);
  return pcVar1;
}

