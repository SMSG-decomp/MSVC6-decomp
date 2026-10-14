uint32_t __fastcall expr_table_dispatch_by_kind(uint8_t cond)

{
  switch(cond) {
  case '\x01':
    return 0x17e;
  case '\x02':
    return 0x17f;
  case '\x03':
    return 0x180;
  case '\x04':
    return 0x181;
  case '\x05':
    return 0x182;
  case '\x06':
    return 0x183;
  }
}

