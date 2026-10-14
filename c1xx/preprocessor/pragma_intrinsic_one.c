void __cdecl pragma_intrinsic_one(fe_name *name)

{
  int index;
  c1_lookup_entry *pcVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  
  index = intrinsic_lookup_by_name(name);
  if (index == -1) {
    diag_warning(1,0xa3,name);
    return;
  }
  pcVar1 = lookup_name_in_context(g_current_scope,name,0x132);
  if (pcVar1 == (c1_lookup_entry *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = pcVar1->sym;
  }
  if (pcVar2 == (c1_symbol *)0x0) {
    diag_warning(1,0xa4,name);
    return;
  }
  pcVar2 = sym_find_c_linkage_function(pcVar2);
  if (pcVar2 == (c1_symbol *)0x0) {
    diag_warning(1,0xa2,name);
    return;
  }
  bVar3 = pcVar2->kind & 0x1f;
  if (((bVar3 != 7) && (bVar3 != 8)) && (bVar3 != 6)) {
    diag_error(0xaa,name);
    return;
  }
  intrinsic_mark_function(pcVar2,index);
  return;
}

