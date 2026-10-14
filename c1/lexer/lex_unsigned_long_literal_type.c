c1_type * __cdecl lex_unsigned_long_literal_type(uint *value)

{
  c1_type *pcVar1;
  
  if ((value[1] != 0) && (4 < g_integral_max_bytes)) {
    pcVar1 = lex_sized_unsigned_literal_type(value);
    return pcVar1;
  }
  return g_type_unsigned_long;
}

