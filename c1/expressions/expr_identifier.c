c1_node * __cdecl expr_identifier(int name)

{
  c1_scope_lookup *pcVar1;
  c1_node *pcVar2;
  c1_symbol *sym;
  
  pcVar1 = scope_stack_lookup(g_current_scope,name);
  if (pcVar1 == (c1_scope_lookup *)0x0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = pcVar1->sym;
  }
  if (sym == (c1_symbol *)0x0) {
    sym = expr_report_undeclared_identifier(name);
    if (sym == (c1_symbol *)0x0) {
      sym = sym_new_object((void *)name,'\0');
      sym->flags2 = sym->flags2 | 1;
    }
  }
  pcVar2 = expr_reference_identifier(sym);
  return pcVar2;
}

