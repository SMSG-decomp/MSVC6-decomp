void stmt_report_jump_into_try(c1_symbol *sym)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x24) == 0x13) {
    cVar1 = 'c';
  }
  else if (*(int *)(unaff_ESI + 0x24) == 0x14) {
    cVar1 = 'g';
  }
  else {
    cVar1 = '\x06';
  }
  if ((g_compile_flags_c8 & 0x10000) == 0) {
    if (cVar1 == '\x06') {
      diag_error(0x2c1,0x53);
    }
    else {
      diag_error(0x2c1,0x4c,cVar1);
    }
  }
  if ((*(byte *)(unaff_ESI + 1) & 1) != 0) {
    *(byte *)(unaff_ESI + 4) = *(byte *)(unaff_ESI + 4) | 4;
  }
  return;
}

