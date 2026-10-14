int __fastcall type_category(c1_type *type)

{
  ushort uVar1;
  
  uVar1 = type->code;
  if (((uVar1 != 0x80d) && (uVar1 != 0x80c)) && (uVar1 != 0x80e)) {
    if (-1 < (char)uVar1) {
      return (uint)g_type_category_basic_table[(uVar1 & 0xf60) >> 5];
    }
    return (uint)g_type_category_derived_table[uVar1 & 0x8f];
  }
  return 0;
}

