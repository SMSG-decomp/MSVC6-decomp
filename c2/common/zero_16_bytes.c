void __fastcall zero_16_bytes(uint32_t *p)

{
  *p = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
  return;
}

