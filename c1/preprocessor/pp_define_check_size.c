void __cdecl pp_define_check_size(uint cursor,int base,int *limit)

{
  LPVOID pvVar1;
  uint dwSize;
  int n;
  char *pcVar2;
  fe_name *pfVar3;
  
  while( true ) {
    dwSize = *limit - base;
    if (0x4fffff < dwSize) {
      if (g_macro_expansion_depth == 0) {
        pfVar3 = (fe_name *)0x500000;
        pcVar2 = g_number_digit_buffer;
        n = 0xb;
      }
      else {
        pfVar3 = (g_macro_expansion_frames[1].macro)->name;
        pcVar2 = (char *)0x500000;
        n = 0x38;
      }
      diag_fatal(n,pcVar2,pfVar3);
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

