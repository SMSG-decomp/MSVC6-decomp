uint32_t __fastcall map_iv_update_opcode(int op)

{
  switch(*(undefined1 *)(op + 0x10763295)) {
  case 0:
    return 0x17c;
  case 1:
    return 0x179;
  case 2:
    return 0x17a;
  case 3:
    return 0x17b;
  case 4:
    return 0x16d;
  case 5:
    return 0x16e;
  case 6:
    return 0x16f;
  case 7:
    return 0x15f;
  }
}

