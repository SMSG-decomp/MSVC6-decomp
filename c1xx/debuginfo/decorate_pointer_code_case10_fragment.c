byte * __cdecl decorate_pointer_code_case10_fragment(c1_type *type,byte *out)

{
  byte bVar1;
  
  bVar1 = 0x4e;
  *out = 0x5f;
  if ((type->code & 0x2000) != 0) {
    bVar1 = 0x4f;
  }
  out[1] = bVar1;
  return out + 2;
}

