float10 __cdecl fpu_round_st0(float10 value)

{
  ushort in_FPUControlWord;
  
  g_fpu_saved_control_word = in_FPUControlWord;
  g_fpu_chop_control_word = in_FPUControlWord | 0xc01;
  return ROUND(value);
}

