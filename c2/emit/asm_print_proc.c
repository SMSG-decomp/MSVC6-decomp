void __fastcall asm_print_proc(c2_function *fn)

{
  c2_fe_symbol *s;
  c2_fe_symbol *sec;
  int iVar1;
  int first;
  
  s = fn->fsym;
  first = 1;
  sec = fe_symbol_lookup_id(s->section_id);
  g_asm_current_segment = asm_switch_segment(sec,0);
  scope_for_each(1,asm_print_equate);
  asm_print_symbol_name(s);
  asm_pad_to_column(8);
  iVar1 = asm_printf("PROC NEAR");
  g_asm_column = g_asm_column + iVar1;
  if (*s->name == '?') {
    first = asm_print_symbol_operand(s,1);
  }
  if ((s->attrs & 0x20) != 0) {
    asm_print_operand_separator(first);
    asm_printf("COMDAT");
  }
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  return;
}

