void __cdecl init_emit_placement_construct(c1_symbol *sym)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  uint mode;
  int bound;
  
  pcVar1 = sym->type;
  tmpl_prune_instance_list(sym);
  bound = 0;
  mode = 4;
  pcVar2 = expr_reference_named_entity(sym,0);
  pcVar2 = expr_build_address_of(pcVar2,mode);
  pcVar2 = expr_build_new('\0',0,sym,0,pcVar2,bound);
  pcVar2 = expr_full_expression_guarded(pcVar2,2);
  stmt_emit_expression(pcVar2);
  sym->type = pcVar1;
  return;
}

