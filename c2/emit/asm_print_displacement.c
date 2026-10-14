void __fastcall asm_print_displacement(int32_t disp,uint32_t width)

{
  int iVar1;
  char *fmt;
  
  if ((disp != 0) || (width != 0)) {
    switch(width) {
    case 0:
      fmt = "%-+ld";
      break;
    case 1:
      fmt = "%-+.2ld";
      break;
    case 3:
      fmt = "%-+.4ld";
    }
    iVar1 = asm_printf(fmt,disp);
    g_asm_column = g_asm_column + iVar1;
  }
  return;
}

