void class_check_union_virtual(c1_declarator *d)

{
  c1_symbol *pcVar1;
  
  pcVar1 = d->sym;
  if (pcVar1 == (c1_symbol *)0x0) {
    pcVar1 = sym_new_from_declarator(d,5);
  }
  diag_error(0x23b,g_class_def_stack[g_class_depth].cls,pcVar1);
  return;
}

