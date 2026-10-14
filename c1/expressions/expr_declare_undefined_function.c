c1_node * __cdecl expr_declare_undefined_function(int name)

{
  byte bVar1;
  c1_scope_lookup *pcVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_symbol *sym;
  c1_type local_10;
  
  pcVar2 = scope_stack_lookup(g_current_scope,name);
  if (pcVar2 == (c1_scope_lookup *)0x0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = pcVar2->sym;
  }
  if (sym == (c1_symbol *)0x0) {
    diag_warning(3,0xd,name);
    sym = sym_new_implicit_function(name);
    sym->flags4 = sym->flags4 | 8;
    if (g_browse_file == (char *)0x0) goto LAB_1061d9ff;
    if ((g_symbol_scope_level == '\0') || (g_opt_FR_browse != 0)) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
    }
  }
  if ((g_browse_file != (char *)0x0) && ((g_symbol_scope_level == '\0' || (g_opt_FR_browse != 0))))
  {
    (*g_il_emitter->vtbl->reference_symbol)(sym);
  }
LAB_1061d9ff:
  pcVar4 = sym->type;
  bVar1 = (byte)pcVar4->code;
  if (((bVar1 & 0x83) != 0x81) && ((bVar1 & 0x8f) != 0x86)) {
    pcVar3 = expr_report_not_a_function();
    return pcVar3;
  }
  pcVar3 = tree_new_symbol_ref(sym);
  if ((sym->flags4 & 0x20) != 0) {
    diag_warning(4,0xd9);
  }
  if ((pcVar4->code & 0x8f) == 0x86) {
    pcVar3 = tree_new_rvalue(pcVar3);
    pcVar3 = expr_call_begin(pcVar3);
    return pcVar3;
  }
  local_10.base = pcVar3->type;
  local_10.flags = (byte)pcVar4->flags & 0x1f;
  local_10.debug_index = 0;
  local_10.code = 0x86;
  local_10.extra.sym = (c1_symbol *)0x0;
  pcVar4 = type_intern(&local_10);
  pcVar3->type = pcVar4;
  pcVar3 = expr_call_begin(pcVar3);
  return pcVar3;
}

