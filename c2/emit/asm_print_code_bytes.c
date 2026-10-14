void __fastcall asm_print_code_bytes(uint32_t offset,int n,uint8_t *bytes)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  asm_pad_to_column(2);
  iVar1 = asm_printf("%05lx",offset);
  g_asm_column = g_asm_column + iVar1;
  asm_pad_by(1);
  iVar1 = g_asm_column;
  iVar3 = 1;
  if (0 < n) {
    do {
      iVar2 = asm_printf("%02x",(uint)bytes[iVar3 + -1]);
      g_asm_column = g_asm_column + iVar2;
      if (iVar3 != n) {
        if (iVar3 % 5 == 0) {
          g_asm_column = 0;
          asm_printf(g_asm_newline);
          asm_pad_by(iVar1);
        }
        else {
          iVar2 = asm_printf(" ");
          g_asm_column = g_asm_column + iVar2;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= n);
  }
  return;
}

