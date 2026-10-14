char * __fastcall asm_size_keyword(int size)

{
  switch(size) {
  case 1:
    return "BYTE";
  case 2:
    return "WORD";
  default:
    return (char *)0x0;
  case 4:
    return "DWORD";
  case 6:
    return "FWORD";
  case 8:
    return "QWORD";
  case 10:
    return "TBYTE";
  }
}

