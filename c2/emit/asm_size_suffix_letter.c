char * __fastcall asm_size_suffix_letter(int size)

{
  if (size == 1) {
    return "b";
  }
  if (size != 2) {
    if (size != 4) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\mdlist.c",0x255);
    }
    return "d";
  }
  return "w";
}

