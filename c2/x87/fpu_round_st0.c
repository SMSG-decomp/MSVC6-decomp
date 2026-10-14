float10 fpu_round_st0(float10 x)

{
  ushort in_FPUControlWord;
  
  g_fpu_saved_control_word = in_FPUControlWord;
  g_fpu_chop_control_word = in_FPUControlWord | 0xc01;
  return ROUND(x);
}

