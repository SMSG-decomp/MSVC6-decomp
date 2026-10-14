void __cdecl opt_unpack_optimize_flags(int flags)

{
  char **flag_ptr;
  
  flag_ptr = &g_option_flag_pointers;
  do {
    if (*flag_ptr != (char *)0x0) {
      **flag_ptr = flags < 0;
    }
    flag_ptr = flag_ptr + 1;
    flags = flags << 1;
  } while ((int)flag_ptr < 0x104d27c0);
  return;
}

