void __fastcall asm_print_float_data(uint32_t type,uint8_t *value,int count)

{
  int iVar1;
  char *fmt;
  double dVar2;
  
  if (type == 0x1004) {
    asm_pad_to_column(8);
    iVar1 = asm_printf("DD");
    g_asm_column = g_asm_column + iVar1;
    asm_pad_to_column(0x10);
    if (count != 1) {
      iVar1 = asm_printf("%ld DUP(");
      g_asm_column = g_asm_column + iVar1;
    }
    iVar1 = asm_printf("0%.8lxr");
    g_asm_column = g_asm_column + iVar1;
    if (count != 1) {
      iVar1 = asm_printf(")");
      g_asm_column = g_asm_column + iVar1;
    }
    asm_pad_to_column(0x30);
    dVar2 = (double)*(float *)value;
  }
  else {
    if (type != 0x1008) {
      asm_pad_to_column(8);
      iVar1 = asm_printf("DT");
      g_asm_column = g_asm_column + iVar1;
      asm_pad_to_column(0x10);
      if (count != 1) {
        iVar1 = asm_printf("%ld DUP(");
        g_asm_column = g_asm_column + iVar1;
      }
      iVar1 = asm_printf("0%.8lx%.8lx%.4xr",*(undefined4 *)(value + 6),*(undefined4 *)(value + 2));
      g_asm_column = g_asm_column + iVar1;
      if (count != 1) {
        iVar1 = asm_printf(")");
        g_asm_column = g_asm_column + iVar1;
      }
      asm_pad_to_column(0x30);
      dVar2 = *(double *)value;
      fmt = "; %Lg";
      goto LAB_1078d4bd;
    }
    asm_pad_to_column(8);
    iVar1 = asm_printf("DQ");
    g_asm_column = g_asm_column + iVar1;
    asm_pad_to_column(0x10);
    if (count != 1) {
      iVar1 = asm_printf("%ld DUP(");
      g_asm_column = g_asm_column + iVar1;
    }
    iVar1 = asm_printf("0%.8lx%.8lxr",*(undefined4 *)(value + 4));
    g_asm_column = g_asm_column + iVar1;
    if (count != 1) {
      iVar1 = asm_printf(")");
      g_asm_column = g_asm_column + iVar1;
    }
    asm_pad_to_column(0x30);
    dVar2 = *(double *)value;
  }
  fmt = "; %g";
LAB_1078d4bd:
  iVar1 = asm_printf(fmt,dVar2);
  g_asm_column = g_asm_column + iVar1;
  return;
}

