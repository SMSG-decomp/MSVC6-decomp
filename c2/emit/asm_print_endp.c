void __fastcall asm_print_endp(c2_function *fn)

{
  c2_fe_symbol *s;
  int iVar1;
  
  s = fn->fsym;
  asm_print_symbol_name(s);
  asm_pad_to_column(8);
  iVar1 = asm_printf("ENDP");
  g_asm_column = g_asm_column + iVar1;
  if (*s->name == '?') {
    asm_print_symbol_operand(s,1);
  }
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  return;
}

