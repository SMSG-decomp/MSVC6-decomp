char __cdecl intrinsic_is_enabled(int index)

{
  byte bVar1;
  
  bVar1 = (byte)g_intrinsic_table[index].attributes;
  if ((bVar1 & 0x80) == 0x80) {
    return '\x01';
  }
  if (((g_opt_Oi != '\0') && ((g_ms_extensions != '\0' || ((bVar1 & 0x40) != 0x40)))) &&
     ((g_opt_Op == '\0' || ((g_intrinsic_table[index].return_code & 0x20) == 0)))) {
    return '\x01';
  }
  return '\0';
}

