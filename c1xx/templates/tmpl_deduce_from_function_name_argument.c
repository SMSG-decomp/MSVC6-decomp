c1_tmpl_deduction *
tmpl_deduce_from_function_name_argument(c1_tmpl_deduction *deduction,c1_type *type,c1_node *arg)

{
  c1_u8 cVar1;
  c1_arg_list *explicit_args;
  c1_symbol *sym;
  c1_tmpl_deduction *pcVar2;
  c1_node *pcVar3;
  
  cVar1 = arg->op;
  pcVar3 = arg;
  if (cVar1 != '\x06') {
    if (cVar1 == '1') {
      pcVar3 = arg->left;
    }
    else if (cVar1 == 'S') {
      pcVar3 = arg->right;
    }
  }
  sym = pcVar3->left;
  explicit_args = pcVar3->right;
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  arg = (c1_node *)0x0;
  pcVar2 = tmpl_deduce_from_overloaded_argument(deduction,sym,explicit_args,type,(c1_symbol **)&arg)
  ;
  if ((pcVar2 != (c1_tmpl_deduction *)0x0) && (arg != (c1_node *)0x0)) {
    if (explicit_args == (c1_arg_list *)0x0) {
      diag_fatal(1,"..\\Cxx\\dymto.c",0x9ce);
    }
    pcVar3->right = (void *)0x0;
    pcVar3->left = arg;
  }
  return pcVar2;
}

