void __cdecl eh_except_filter_end(void)

{
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfdffffff;
  return;
}

