c1_type * __cdecl type_promoted_integral(c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code;
  if (((byte)uVar1 >> 4 & 1) != 0) {
    return (c1_type *)((uint)g_type_int & ('\x03' < (char)(&g_type_rank_table)[uVar1 & 0xf]) - 1);
  }
  return (c1_type *)((uint)g_type_int & -(uint)((uVar1 & 0x100) != 0));
}

