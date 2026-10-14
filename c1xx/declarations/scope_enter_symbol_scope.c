void scope_enter_symbol_scope(c1_symbol *sym)

{
  byte bVar1;
  
  bVar1 = sym->kind & 0x1f;
  if (bVar1 != 0xf) {
    if (bVar1 == 4) {
      scope_enter_class(g_current_scope,sym);
      return;
    }
    if (bVar1 == 0x19) {
      ns_enter_enclosing_namespaces(g_current_scope,sym);
    }
  }
  return;
}

