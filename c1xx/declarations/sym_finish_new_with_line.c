c1_symbol * __thiscall
sym_finish_new_with_line(void *qualifier,c1_symbol *new_sym,c1_symbol *sym,c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  new_sym->scope_index = *(c1_u16 *)(*(int *)((int)qualifier + 0x14) + 4);
  pcVar1 = sym_finish_new(sym,d);
  return pcVar1;
}

