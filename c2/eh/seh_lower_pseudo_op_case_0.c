c2_tuple * seh_lower_pseudo_op_case_0(c2_tuple *t)

{
  c2_fe_symbol *sym;
  c2_operand *fn;
  c2_tuple *pcVar1;
  
  sym = fe_symbol_lookup_name("__abnormal_termination");
  fn = operand_new_codeaddr(0x153,sym);
  pcVar1 = build_helper_call((c2_node *)t,0xe,fn,'\0');
  return pcVar1;
}

