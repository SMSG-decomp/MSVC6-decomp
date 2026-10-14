int __fastcall asm_print_operand_separator(int first)

{
  int iVar1;
  
  if (first != 0) {
    asm_pad_to_column(0x38);
    iVar1 = asm_printf("%c ",(int)g_asm_comment_char);
    g_asm_column = g_asm_column + iVar1;
    return 0;
  }
  iVar1 = asm_printf(", ");
  g_asm_column = g_asm_column + iVar1;
  return 0;
}

