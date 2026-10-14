byte __cdecl tmpl_check_argument_list(c1_symbol *tmpl,c1_sym_list *params,c1_arg_list **args)

{
  byte bVar1;
  uint local_4;
  
  local_4 = 0;
  bVar1 = tmpl_complete_argument_list(tmpl,params,args,&local_4);
  if (bVar1 != 0) {
    bVar1 = tmpl_check_arguments(tmpl,params,args,local_4);
    return bVar1;
  }
  return 0;
}

