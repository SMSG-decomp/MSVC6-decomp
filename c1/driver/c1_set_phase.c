void __cdecl c1_set_phase(int phase)

{
  int iVar1;
  
  iVar1 = g_set_phase_count;
  g_set_phase_count = g_set_phase_count + 1;
  if (0 < iVar1) {
    diag_write_fatal_C1063('\x01');
    g_compile_phase = phase;
    return;
  }
  g_compile_phase = phase;
  return;
}

