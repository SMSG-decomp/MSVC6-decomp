int fpu_compare_abs(float10 limit,float10 value)

{
  bool bVar1;
  
  bVar1 = value < (float10)0;
  if (bVar1) {
    value = -value;
  }
  g_fpu_scratch = (uint32_t)bVar1;
  g_fpu_status_word =
       (ushort)(limit < value) << 8 | (ushort)(NAN(limit) || NAN(value)) << 10 |
       (ushort)(limit == value) << 0xe;
  return (uint)(limit < value);
}

