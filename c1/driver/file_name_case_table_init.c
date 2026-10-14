void __cdecl file_name_case_table_init(void)

{
  uint uVar1;
  ushort *puVar2;
  uint _Ch;
  
  _Ch = 0;
  puVar2 = g_file_name_case_table;
  do {
    if (g_char_class[_Ch & 0xff] == '#') {
      *puVar2 = 0xffff;
    }
    else {
      uVar1 = _mbctolower(_Ch);
      *puVar2 = (ushort)uVar1;
    }
    puVar2 = puVar2 + 1;
    _Ch = _Ch + 1;
  } while ((int)puVar2 < 0x1066a0d0);
  g_file_name_case_table[0x2f] = 0x5c;
  return;
}

