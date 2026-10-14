int __cdecl intrinsic_is_enabled(int index)

{
  uint3 uVar1;
  byte bVar2;
  
  bVar2 = (byte)g_intrinsic_table[index].attributes;
  uVar1 = (uint3)((uint)(index * 0xc) >> 8);
  if ((bVar2 & 0x80) == 0x80) {
    return CONCAT31(uVar1,1);
  }
  if (((g_opt_Oi != '\0') && ((g_ms_extensions != '\0' || ((bVar2 & 0x40) != 0x40)))) &&
     ((g_opt_Op == '\0' || ((g_intrinsic_table[index].return_code & 0x20) == 0)))) {
    return CONCAT31(uVar1,1);
  }
  return (uint)uVar1 << 8;
}

