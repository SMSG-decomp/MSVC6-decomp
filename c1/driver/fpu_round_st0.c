longdouble __cdecl fpu_round_st0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  g_fpu_saved_control_word = in_FPUControlWord;
  g_fpu_chop_control_word = in_FPUControlWord | 0xc01;
  return (longdouble)(double)ROUND(in_ST0);
}

