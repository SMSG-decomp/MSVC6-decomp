void __cdecl pragma_intrinsic_name(int name)

{
  int index;
  c1_scope_lookup *entry;
  c1_symbol *sym;
  byte bVar1;
  
  index = intrinsic_name_lookup((void *)name);
  if (index == -1) {
    diag_warning(1,0xa3);
    return;
  }
  entry = scope_stack_lookup(g_current_scope,name);
  if (entry == (c1_scope_lookup *)0x0) {
    sym = (c1_symbol *)0x0;
  }
  else {
    sym = entry->sym;
  }
  if (sym != (c1_symbol *)0x0) {
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
      diag_error(0xaa,name);
      return;
    }
    intrinsic_mark_function(sym,index);
    return;
  }
  diag_warning(1,0xa4,name);
  return;
}

