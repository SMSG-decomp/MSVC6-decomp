void __cdecl asm_warn_ptr_operator(short size_keyword)

{
  g_asm_operand->size_class = (&g_asm_size_class_by_keyword)[size_keyword];
  g_asm_operand->flags = g_asm_operand->flags | 1;
  if ((bool)g_asm_ptr_form == (size_keyword == 0x3c)) {
    if (g_asm_ptr_form != 0) {
      diag_warning(1,0x192);
      return;
    }
    diag_warning(1,0x193);
  }
  return;
}

