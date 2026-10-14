void __cdecl opt_unpack_optimize_flags(int flags)

{
  char **ppcVar1;
  
  ppcVar1 = g_option_flag_pointers;
  do {
    if (*ppcVar1 != (char *)0x0) {
      **ppcVar1 = flags < 0;
    }
    ppcVar1 = ppcVar1 + 1;
    flags = flags << 1;
  } while ((int)ppcVar1 < 0x1065e510);
  return;
}

