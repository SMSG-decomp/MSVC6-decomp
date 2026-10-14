char __cdecl static_ctor_char_tables(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (g_type_category_basic_codes[0] != 0) {
    piVar2 = g_type_category_basic_codes;
    iVar3 = g_type_category_basic_codes[0];
    do {
      piVar1 = piVar2 + 1;
      piVar2 = piVar2 + 2;
      g_type_category_basic_table[iVar3 >> 5] = (c1_u8)*piVar1;
      iVar3 = *piVar2;
    } while (iVar3 != 0);
  }
  if (g_type_category_derived_codes[0] != 0) {
    piVar2 = g_type_category_derived_codes;
    iVar3 = g_type_category_derived_codes[0];
    do {
      piVar1 = piVar2 + 1;
      piVar2 = piVar2 + 2;
      g_type_category_derived_table[iVar3] = (c1_u8)*piVar1;
      iVar3 = *piVar2;
    } while (iVar3 != 0);
  }
  return '\x01';
}

