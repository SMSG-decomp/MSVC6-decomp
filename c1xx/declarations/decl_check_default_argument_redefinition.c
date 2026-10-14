void __cdecl
decl_check_default_argument_redefinition
          (c1_function_params *newp,c1_function_params *oldp,c1_symbol *sym,int mode)

{
  c1_node *new_last;
  c1_node *pcVar1;
  c1_node *new_defaults;
  int iVar2;
  
  pcVar1 = oldp->defaults;
  new_defaults = newp->defaults;
  if (((g_compile_flags_c8 & 0x2000) == 0) && (newp->default_count != '\0')) {
    if (mode != 0) {
      if (pcVar1 == (c1_node *)0x0) {
        decl_function_type_add_default_arguments(sym,new_defaults,oldp,newp,(c1_node *)0x0);
        decl_check_default_parameters_of(sym);
        return;
      }
      new_last = new_defaults->link;
      iVar2 = newp->list->count;
      while( true ) {
        if (new_defaults->left != (void *)0x0) {
          diag_error(0x23c,sym,iVar2);
          new_defaults->left = (void *)0x0;
        }
        new_defaults = new_defaults->right;
        if (new_defaults == (c1_node *)0x0) goto LAB_104718cf;
        pcVar1 = pcVar1->right;
        if (pcVar1 == (c1_node *)0x0) break;
        iVar2 = iVar2 + -1;
      }
      decl_function_type_add_default_arguments(sym,new_defaults,oldp,newp,new_last);
LAB_104718cf:
      decl_check_default_parameters_of(sym);
    }
    decl_check_default_parameters_of(sym);
  }
  return;
}

