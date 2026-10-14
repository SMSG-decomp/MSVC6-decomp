int __cdecl lex_hex_digit_value(uint c)

{
  if (g_char_class[c & 0xff] == '\x1d') {
    return c - 0x30;
  }
  return (c & 0xdf) - 0x37;
}

