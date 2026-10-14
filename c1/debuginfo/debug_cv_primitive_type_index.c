int __cdecl debug_cv_primitive_type_index(ushort code)

{
  char cVar1;
  
  if ((code & 0x40) != 0) {
    return 3;
  }
  if ((code & 0x30) == 0) {
    return 0;
  }
  if ((code & 0x20) != 0) {
    return g_cv_real_type_by_size[(char)(&g_type_rank_table)[code & 0xf]];
  }
  if ((((byte)code & 0x1f) != 0x13) &&
     ((cVar1 = (&g_type_rank_table)[code & 0xf], cVar1 != '\x01' || ((code & 0x3000) != 0)))) {
    if ((code & 0x2000) != 0) {
      return g_cv_unsigned_type_by_size[cVar1];
    }
    return g_cv_signed_type_by_size[cVar1];
  }
  if ((code & 0x2000) == 0) {
    return g_cv_int_type_by_size[(char)(&g_type_rank_table)[code & 0xf]];
  }
  return g_cv_uint_type_by_size[(char)(&g_type_rank_table)[code & 0xf]];
}

