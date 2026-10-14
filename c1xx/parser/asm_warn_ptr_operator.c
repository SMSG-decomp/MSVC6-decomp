void __cdecl asm_warn_ptr_operator(short size_keyword)

{
  g_asm_current_operand->size_class = *(c1_u8 *)((int)g_asm_yy_def + size_keyword + 0xde);
  g_asm_current_operand->size_given = g_asm_current_operand->size_given | 1;
  if ((bool)g_asm_ptr_written == (size_keyword == 0x3c)) {
    if (g_asm_ptr_written != '\0') {
      diag_warning(1,0x192);
      return;
    }
    diag_warning(1,0x193);
  }
  return;
}

