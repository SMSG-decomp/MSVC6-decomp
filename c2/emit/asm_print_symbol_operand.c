int __fastcall asm_print_symbol_operand(c2_fe_symbol *s,int first)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = undecorate_name(s->name,0);
  if (*pcVar1 != '\0') {
    first = asm_print_operand_separator(first);
    iVar2 = asm_printf("%s",pcVar1);
    g_asm_column = g_asm_column + iVar2;
  }
  return first;
}

