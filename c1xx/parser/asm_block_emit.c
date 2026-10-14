void __cdecl asm_block_emit(void)

{
  g_compile_flags_c4 = g_compile_flags_c4 | 0x200000;
  g_current_function->flags5 = g_current_function->flags5 | 0x10;
  il_emit_pragma_or_segment_record(0x19);
  asm_instruction_reset();
  g_asm_at_block_start = 1;
  yyparse_asm();
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffdfffff;
  il_emit_pragma_or_segment_record(0x1a);
  return;
}

