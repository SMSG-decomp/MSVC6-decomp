bool __fastcall type_is_plain_char_unsigned(c1_type *type)

{
  if (g_ms_extensions != '\0') {
    return false;
  }
  if ((type->code & 0xfff) != 0x11) {
    return false;
  }
  if ((type->code & 0x1000) != 0) {
    return false;
  }
  return g_opt_J_unsigned_char != '\0';
}

