byte __thiscall
tmpl_deduce_from_argument_type(c1_tmpl_deduction *deduction,c1_type *type,c1_node *arg)

{
  byte bVar1;
  c1_type *type2;
  
  type2 = tmpl_normalize_argument_type(arg->type);
  deduction->param_type = type;
  deduction->arg_type = type2;
  bVar1 = tmpl_unify_types(deduction,type,type2,'\x01');
  return bVar1;
}

