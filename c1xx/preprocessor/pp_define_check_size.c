void __cdecl pp_define_check_size(uint cursor,int base,int *limit)

{
  LPVOID pvVar1;
  uint dwSize;
  int n;
  uint limit_value;
  char *what;
  
  while( true ) {
    dwSize = *limit - base;
    if (0x4fffff < dwSize) {
      if (g_macro_expansion_depth == 0) {
        limit_value = 0x500000;
        what = (char *)g_number_digit_buffer;
        n = 0xb;
      }
      else {
        limit_value = (uint)(g_macro_expansion_frames[1].macro)->name;
        what = (char *)0x500000;
        n = 0x38;
      }
      diag_fatal(n,what,limit_value);
    }
    pvVar1 = VirtualAlloc((LPVOID)(dwSize + 5 + base),dwSize,0x1000,4);
    if (pvVar1 == (LPVOID)0x0) break;
    *limit = base + 5 + dwSize * 2;
    if (cursor < *limit - 5U) {
      return;
    }
  }
  diag_fatal_simple(0x3c);
}

