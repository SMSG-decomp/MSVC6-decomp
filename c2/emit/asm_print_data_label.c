void __fastcall asm_print_data_label(void *sym,int size,void *sec)

{
  uint8_t *puVar1;
  int iVar2;
  
  g_asm_current_segment = asm_switch_segment(sec,0);
  iVar2 = *(int *)((int)sym + 0xc);
  if (iVar2 != *(int *)((int)sec + 0x3a)) {
    asm_printf("\tORG $%+ld",iVar2 - *(int *)((int)sec + 0x3a));
    g_asm_column = 0;
    asm_printf(g_asm_newline);
    *(int *)((int)sec + 0x3a) = iVar2;
  }
  puVar1 = fe_symbol_external_name(sym);
  iVar2 = asm_printf("%s",puVar1);
  g_asm_column = g_asm_column + iVar2;
  if (size != 0) {
    asm_pad_to_column(8);
    iVar2 = asm_printf("DB");
    g_asm_column = g_asm_column + iVar2;
    asm_pad_to_column(0x10);
    asm_printf("0%xH DUP (?)",size);
    g_asm_column = 0;
    asm_printf(g_asm_newline);
    *(int *)((int)sec + 0x3a) = *(int *)((int)sec + 0x3a) + size;
  }
  return;
}

