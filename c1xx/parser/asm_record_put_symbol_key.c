c1_u16 * __cdecl asm_record_put_symbol_key(c1_u16 *out,c1_u32 key)

{
  if (key < 0x8000) {
    *out = (ushort)key;
    return out + 1;
  }
  *out = (ushort)key | 0x8000;
  out[1] = (c1_u16)(key >> 0xf);
  return out + 2;
}

