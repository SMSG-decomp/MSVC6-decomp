void __cdecl class_build_placement_delete_closure_body(c1_symbol *closure)

{
  int iVar1;
  int *piVar2;
  c1_symtab *tab;
  c1_symbol *sym;
  void *name;
  c1_node *n;
  c1_node *pcVar3;
  int n_00;
  int *piVar4;
  
  tab = symtab_ensure_1704();
  sym = symtab_lookup(tab,closure);
  pcVar3 = (c1_node *)0x0;
  iVar1 = *(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
  piVar2 = *(int **)(iVar1 + 0xc);
  piVar4 = piVar2 + 2;
  for (n_00 = *piVar2; n_00 != 0; n_00 = n_00 + -1) {
    name = name_intern_numbered(n_00);
    n = expr_lookup_name_expression(name);
    if ((*(ushort *)*piVar4 & 0x200) != 0) {
      n = tree_new_rvalue(n);
      n->type = (c1_type *)*piVar4;
    }
    pcVar3 = tree_append_list_item(pcVar3,n,0);
    piVar4 = piVar4 + 1;
  }
  pcVar3 = expr_build_call_node(sym,(c1_node *)0x0,(int)pcVar3,0,**(int **)(iVar1 + 0xc),0);
  stmt_emit_expression(pcVar3);
  return;
}

