c1_type * __cdecl lex_sized_unsigned_literal_type(uint *value)

{
  if (value[1] != 0) {
    return g_type_uint64;
  }
  return g_type_uint32;
}

