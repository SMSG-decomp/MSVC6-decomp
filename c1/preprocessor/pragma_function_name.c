void __cdecl pragma_function_name(int name)

{
  c1_symbol *sym;
  byte bVar1;
  int iVar2;
  c1_scope_lookup *entry;
  
  iVar2 = intrinsic_name_lookup((void *)name);
  if (iVar2 == -1) {
    diag_warning(1,0xa3);
    return;
  }
  entry = scope_stack_lookup(g_current_scope,name);
  if (entry != (c1_scope_lookup *)0x0) {
    sym = entry->sym;
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) {
      diag_error(0xaa,name);
      return;
    }
    if (((uint)sym->detail & 0x800000) != 0x800000) {
      intrinsic_unmark_function(sym);
      return;
    }
    diag_warning(1,0xa7,name);
    return;
  }
  diag_warning(1,0xa4,name);
  return;
}

