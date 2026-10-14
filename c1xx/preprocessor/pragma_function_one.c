void __cdecl pragma_function_one(fe_name *name)

{
  int iVar1;
  c1_lookup_entry *pcVar2;
  c1_symbol *sym;
  byte bVar3;
  
  iVar1 = intrinsic_lookup_by_name(name);
  if (iVar1 == -1) {
    diag_warning(1,0xa3,name);
    return;
  }
  pcVar2 = lookup_name_in_context(g_current_scope,name,0x132);
  if (pcVar2 == (c1_lookup_entry *)0x0) {
    diag_warning(1,0xa4,name);
    return;
  }
  sym = sym_find_c_linkage_function(pcVar2->sym);
  if (sym == (c1_symbol *)0x0) {
    diag_warning(1,0xa2,name);
    return;
  }
  bVar3 = sym->kind & 0x1f;
  if (((bVar3 != 7) && (bVar3 != 8)) && (bVar3 != 6)) {
    diag_error(0xaa,name);
    return;
  }
  if ((*(byte *)((int)&sym->detail + 2) & 0x80) == 0x80) {
    diag_warning(1,0xa7,name);
    return;
  }
  intrinsic_unmark_function(sym);
  return;
}

