c1_symbol * __cdecl tmpl_match_explicit_arguments(c1_symbol *sym,c1_arg_list *args)

{
  char cVar1;
  c1_tmpl_deduction local_30;
  
  tmpl_deduction_begin(&local_30,sym,args,0,'\x01');
  if ((local_30.flags & 0xc) != 0) {
    return (c1_symbol *)0x0;
  }
  cVar1 = tmpl_check_explicit_argument_kinds(&local_30);
  if (cVar1 == '\0') {
    return (c1_symbol *)0x0;
  }
  tmpl_specialize_function(&local_30);
  return local_30.specialization;
}

