void __fastcall asm_print_db_bytes(uint8_t *p,int n)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  char *fmt;
  byte *local_c;
  int local_4;
  
  bVar2 = true;
  bVar3 = false;
  asm_pad_to_column(8);
  iVar4 = asm_printf("DB");
  g_asm_column = g_asm_column + iVar4;
  asm_pad_to_column(0x10);
  if (0x48 < g_asm_column) {
    g_asm_column = 0x47;
  }
  local_c = p;
  local_4 = n;
  if (n != 0) {
    do {
      if (0x48 < g_asm_column) {
        if (bVar3) {
          asm_printf(g_asm_char_format,0x27);
          bVar3 = false;
        }
        g_asm_column = 0;
        asm_printf(g_asm_newline);
        asm_pad_to_column(8);
        iVar4 = asm_printf("DB\t");
        g_asm_column = g_asm_column + iVar4;
        bVar2 = true;
      }
      bVar1 = *local_c;
      local_c = local_c + 1;
      iVar4 = char_is_printable((uint)bVar1);
      if (iVar4 == 0) {
        if (bVar3) {
          iVar4 = asm_printf(g_asm_char_format,0x27);
          g_asm_column = g_asm_column + iVar4;
          bVar3 = false;
        }
        if (!bVar2) {
          iVar4 = asm_printf(", ");
          g_asm_column = g_asm_column + iVar4;
        }
        fmt = "0%xH";
      }
      else {
        if (!bVar3) {
          if (!bVar2) {
            iVar4 = asm_printf(", ");
            g_asm_column = g_asm_column + iVar4;
          }
          iVar4 = asm_printf(g_asm_char_format,0x27);
          g_asm_column = g_asm_column + iVar4;
          bVar3 = true;
        }
        if (bVar1 == 0x27) {
          iVar4 = asm_printf(g_asm_char_format,0x27);
          g_asm_column = g_asm_column + iVar4;
        }
        fmt = g_asm_char_format;
      }
      iVar4 = asm_printf(fmt,(uint)bVar1);
      g_asm_column = g_asm_column + iVar4;
      bVar2 = false;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    if (bVar3) {
      iVar4 = asm_printf(g_asm_char_format,0x27);
      g_asm_column = g_asm_column + iVar4;
    }
  }
  return;
}

