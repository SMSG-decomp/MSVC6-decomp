c1_type * __cdecl lex_scan_sized_int_suffix(char is_unsigned)

{
  byte bVar1;
  c1_type *pcVar2;
  
  bVar1 = lex_getc();
  if ((0 < g_integral_max_bytes) && (bVar1 == 0x38)) {
    if (is_unsigned != '\0') {
      return g_type_uint8;
    }
    return g_type_int8;
  }
  if ((g_integral_max_bytes < 4) || (bVar1 != 0x33)) {
    if ((g_integral_max_bytes < 8) || (bVar1 != 0x36)) {
      if ((g_integral_max_bytes < 2) || (bVar1 != 0x31)) {
        g_input_ptr = g_input_ptr + -2;
        goto LAB_1046339a;
      }
      bVar1 = lex_getc();
      if (bVar1 == 0x36) {
        if (is_unsigned != '\0') {
          return g_type_uint16;
        }
        return g_type_int16;
      }
    }
    else {
      bVar1 = lex_getc();
      if (bVar1 == 0x34) {
        if (is_unsigned != '\0') {
          return g_type_uint64;
        }
        return g_type_int64;
      }
    }
  }
  else {
    bVar1 = lex_getc();
    if (bVar1 == 0x32) {
      if (is_unsigned != '\0') {
        return g_type_uint32;
      }
      return g_type_int32;
    }
  }
  g_input_ptr = g_input_ptr + -3;
LAB_1046339a:
  pcVar2 = g_type_unsigned_int;
  if (is_unsigned == '\0') {
    pcVar2 = g_type_int;
  }
  return pcVar2;
}

