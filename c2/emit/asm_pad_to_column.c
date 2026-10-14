void __fastcall asm_pad_to_column(int column)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (g_asm_column < column) {
    uVar3 = column - g_asm_column;
    uVar2 = g_asm_column & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    iVar1 = 8 - uVar2;
    if ((iVar1 <= (int)uVar3) && (iVar1 != 0)) {
      uVar3 = uVar3 - iVar1;
      asm_printf("\t");
      g_asm_column = g_asm_column + iVar1;
    }
    if (7 < (int)uVar3) {
      uVar2 = uVar3 >> 3;
      uVar3 = uVar3 + uVar2 * -8;
      do {
        asm_printf("\t");
        g_asm_column = g_asm_column + 8;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if (0 < (int)uVar3) {
      do {
        iVar1 = asm_printf(" ");
        g_asm_column = g_asm_column + iVar1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    return;
  }
  iVar1 = asm_printf(" ");
  g_asm_column = g_asm_column + iVar1;
  return;
}

