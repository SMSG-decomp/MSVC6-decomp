int __fastcall reader_type_is_simple_scalar(int size,uint16_t type,uint32_t n)

{
  if (type >> 0xc == 4) {
    return (uint)(size == 8);
  }
  if ((type >> 0xc == 5) && (((n == 0 || (8 < n)) || ((n & n - 1) != 0)))) {
    return 1;
  }
  return 0;
}

