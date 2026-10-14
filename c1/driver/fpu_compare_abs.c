int __cdecl fpu_compare_abs(void)

{
  bool bVar1;
  float10 in_ST0;
  float10 in_ST1;
  
  bVar1 = in_ST1 < (float10)0;
  if (bVar1) {
    in_ST1 = -in_ST1;
  }
  g_fpu_scratch = (uint32_t)bVar1;
  g_fpu_status_word =
       (ushort)(in_ST0 < in_ST1) << 8 | (ushort)(NAN(in_ST0) || NAN(in_ST1)) << 10 |
       (ushort)(in_ST0 == in_ST1) << 0xe;
  return (uint)(in_ST0 < in_ST1);
}

