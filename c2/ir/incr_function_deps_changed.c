int __fastcall incr_function_deps_changed(c2_fe_symbol *fs)

{
  c2_incr_id_cell *pcVar1;
  c2_fe_symbol *pcVar2;
  
  pcVar1 = fs->incr->callees;
  while( true ) {
    if (pcVar1 == (c2_incr_id_cell *)0x0) {
      return 0;
    }
    pcVar2 = fe_symbol_lookup_id(pcVar1->sym_id);
    if (((pcVar2->storage & 0x4000) == 0) || ((pcVar2->fn_flags & 0x800) != 0)) break;
    pcVar1 = pcVar1->next;
  }
  fs->fn_flags = fs->fn_flags | 0x800;
  return 1;
}

