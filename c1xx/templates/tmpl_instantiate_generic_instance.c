c1_symbol * __cdecl tmpl_instantiate_generic_instance(c1_symbol *tmpl)

{
  c1_symbol *instance;
  
  instance = tmpl_parse_arguments(tmpl,(c1_arg_list *)0x0,'\x01');
  tmpl_instantiate(tmpl,instance);
  return instance;
}

