uint * __cdecl pair_init_zero_value(uint *out,int value)

{
  *out = 0;
  out[1] = value;
  return out;
}

