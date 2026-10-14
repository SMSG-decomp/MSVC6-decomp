void __cdecl diag_error(short n,...)

{
  if ((g_compile_flags_c8 & 0x20000) != 0) {
    g_trial_error_count = g_trial_error_count + 1;
    return;
  }
  diag_error_emit(n,&stack0x00000008);
  return;
}

