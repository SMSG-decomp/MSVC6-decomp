int __cdecl diag_fatal_file(int err,int n)

{
  if ((g_compile_phase != 7) && (g_compile_phase != 6)) {
    diag_fatal(n);
  }
  return 0;
}

