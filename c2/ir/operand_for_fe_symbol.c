c2_operand * __fastcall operand_for_fe_symbol(c2_fe_symbol *fs)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = fe_symbol_get_storage(fs);
  pcVar1 = operand_new_sym(g_symclass_operand_op[sym->cls],sym->type,sym);
  return pcVar1;
}

