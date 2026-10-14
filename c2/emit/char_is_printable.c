int __fastcall char_is_printable(int c)

{
  if ((0x60 < c) && (c < 0x7b)) {
    return 1;
  }
  if ((0x40 < c) && (c < 0x5b)) {
    return 1;
  }
  if ((0x2f < c) && (c < 0x3a)) {
    return 1;
  }
  if ((0x20 < c) && (c < 0x30)) {
    return 1;
  }
  if ((0x39 < c) && (c < 0x41)) {
    return 1;
  }
  if ((0x5a < c) && (c < 0x61)) {
    return 1;
  }
  if ((0x7a < c) && (c < 0x7f)) {
    return 1;
  }
  return (uint)(c == 0x20);
}

