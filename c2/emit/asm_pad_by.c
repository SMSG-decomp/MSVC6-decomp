void __fastcall asm_pad_by(int n)

{
  int iVar1;
  uint uVar2;
  
  if (0 < n) {
    uVar2 = g_asm_column;
    if ((8 < g_asm_column) && (uVar2 = g_asm_column & 0x80000007, (int)uVar2 < 0)) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    iVar1 = 8 - uVar2;
    if (iVar1 <= n) {
      n = n - iVar1;
      asm_printf("\t");
      g_asm_column = g_asm_column + iVar1;
      if (7 < n) {
        uVar2 = (uint)n >> 3;
        n = n + uVar2 * -8;
        do {
          asm_printf("\t");
          g_asm_column = g_asm_column + 8;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
    }
    if (0 < n) {
      do {
        asm_printf(" ");
        n = n - 1;
      } while (n != 0);
    }
    return;
  }
  iVar1 = asm_printf(" ");
  g_asm_column = g_asm_column + iVar1;
  return;
}

