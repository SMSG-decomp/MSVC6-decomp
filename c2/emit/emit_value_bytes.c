void __fastcall emit_value_bytes(uint32_t value,int nbytes)

{
  switch(nbytes) {
  case 1:
    *g_encode_cursor = (uint8_t)value;
    g_encode_cursor = g_encode_cursor + nbytes;
    return;
  case 2:
    *(short *)g_encode_cursor = (short)value;
    g_encode_cursor = g_encode_cursor + nbytes;
    return;
  case 4:
    *(uint32_t *)g_encode_cursor = value;
    g_encode_cursor = g_encode_cursor + nbytes;
  }
  return;
}

