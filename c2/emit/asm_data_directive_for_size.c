char * __fastcall asm_data_directive_for_size(int size)

{
  switch(size) {
  case 1:
    return "DB";
  case 2:
    return "DW";
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\mdlist.c",0xf6);
  case 4:
    return "DD";
  case 6:
    return "DF";
  case 8:
    return "DQ";
  case 10:
    return "DT";
  }
}

