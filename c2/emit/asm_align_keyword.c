char * __fastcall asm_align_keyword(int align)

{
  switch(asm_align_keyword_index_table[align]) {
  case 0:
    return "BYTE";
  case 1:
    return "WORD";
  case 2:
    return "DWORD";
  case 3:
    return "PARA";
  }
}

