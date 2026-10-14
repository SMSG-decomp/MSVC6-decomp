void __thiscall ns_define_alias(c1_declarator *target,fe_name *alias)

{
  c1_symbol *pcVar1;
  byte bVar2;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar3;
  c1_symbol *pcVar4;
  
  if (target->qualifier == (c1_overload_set *)0x0) {
    g_current_scope->keep_aliases = '\x01';
    pcVar3 = lookup_name_in_context(g_current_scope,target->name,0x132);
    g_current_scope->keep_aliases = '\0';
    if (pcVar3 == (c1_lookup_entry *)0x0) {
      diag_error(0x36e,target->name);
      return;
    }
    pcVar4 = pcVar3->sym;
  }
  else {
    pcVar4 = target->qualifier->list->head->sym;
  }
  if ((pcVar4->kind & 0x1f) == 0x1a) {
    pcVar4 = *(c1_symbol **)pcVar4->type;
  }
  bVar2 = pcVar4->kind & 0x1f;
  if ((bVar2 != 4) && (bVar2 != 0x19)) {
    diag_error(0x36f,pcVar4);
    return;
  }
  g_current_scope->keep_aliases = '\x01';
  result = (*g_current_scope->current->vtbl->lookup)(g_current_scope->current,alias,1);
  if (result == (c1_lookup_result *)0x0) {
    pcVar3 = (c1_lookup_entry *)0x0;
  }
  else {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
  }
  g_current_scope->keep_aliases = '\0';
  if (pcVar3 != (c1_lookup_entry *)0x0) {
    if ((pcVar3->sym->kind & 0x1f) != 0x1a) {
      diag_error(0x370,alias);
      return;
    }
    pcVar1 = *(c1_symbol **)pcVar3->sym->type;
    if (pcVar1 != pcVar4) {
      diag_error(0x371,alias,pcVar1);
      return;
    }
  }
  pcVar4 = symtable_ice_2(alias,pcVar4,(c1_symbol *)0x0);
  (*g_current_scope->current->vtbl->insert)(pcVar4);
  return;
}

