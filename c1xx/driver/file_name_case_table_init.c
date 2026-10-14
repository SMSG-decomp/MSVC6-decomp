void __cdecl file_name_case_table_init(void)

{
  uint uVar1;
  c1_u16 *case_entry;
  uint _Ch;
  
  _Ch = 0;
  case_entry = g_file_name_case_table;
  do {
    if (g_char_class[_Ch & 0xff] == '#') {
      *case_entry = 0xffff;
    }
    else {
      uVar1 = _mbctolower(_Ch);
      *case_entry = (c1_u16)uVar1;
    }
    case_entry = case_entry + 1;
    _Ch = _Ch + 1;
  } while ((int)case_entry < 0x104df1a4);
  g_file_name_case_table[0x2f] = 0x5c;
  return;
}

