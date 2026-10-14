c1_symbol * __cdecl expr_lookup_pseudo_destructor_name(fe_name *name,c1_symbol *cls)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_scope_stack *pcVar4;
  c1_u8 *pcVar5;
  c1_lookup_entry *pcVar6;
  c1_symbol *pcVar7;
  
  pcVar5 = expr_build_member_access_implicit(g_current_scope,name);
  if (pcVar5 != (c1_u8 *)0x0) {
    pcVar6 = lookup_name_in_context(g_current_scope,name,0x132);
    pcVar7 = pcVar6->sym;
    if ((pcVar7->kind & 0x1f) == 0x12) {
      pcVar7 = *(c1_symbol **)(*(int *)pcVar7->type + 8);
    }
    if (((pcVar7->type->code & 0x200) != 0) && ((pcVar7->type->extra).cls == cls)) {
      return pcVar7;
    }
  }
  pcVar4 = g_current_scope;
  cVar1 = g_current_scope->reported;
  pcVar7 = g_current_scope->qual_class;
  cVar2 = g_current_scope->access_op;
  cVar3 = g_current_scope->qualified;
  g_current_scope->reported = '\0';
  pcVar4->qual_class = (c1_symbol *)0x0;
  pcVar4->access_op = '\x01';
  pcVar4->qualified = '\0';
  pcVar6 = lookup_name_in_context(g_current_scope,name,0x132);
  if (cVar3 == '\0') {
    g_current_scope->qual_class = (c1_symbol *)0x0;
    g_current_scope->access_op = '\x01';
    g_current_scope->qualified = '\0';
    g_current_scope->reported = '\0';
  }
  else {
    g_current_scope->qual_class = pcVar7;
    g_current_scope->access_op = cVar2;
    g_current_scope->qualified = '\x01';
    g_current_scope->reported = cVar1;
  }
  if (pcVar6 == (c1_lookup_entry *)0x0) {
    return (c1_symbol *)0x0;
  }
  return pcVar6->sym;
}

