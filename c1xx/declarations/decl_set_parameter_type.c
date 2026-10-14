void __thiscall decl_set_parameter_type(c1_type *fn,int params,c1_node *defaults,c1_type *this_type)

{
  c1_symbol *pcVar1;
  
  pcVar1 = (c1_symbol *)
           decl_intern_parameter_list(params,(int)&fn->flags,(int)defaults,(int)this_type);
  (fn->extra).cls = pcVar1;
  return;
}

