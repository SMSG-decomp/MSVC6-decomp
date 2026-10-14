int __fastcall incr_global_needs_record(uint32_t id)

{
  c2_incr_id_cell *pcVar1;
  c2_fe_symbol *pcVar2;
  
  pcVar2 = fe_scope_lookup_id(&g_global_scope,id);
  pcVar1 = g_incr_unknown_symbol_ids;
  if (pcVar2 != (c2_fe_symbol *)0x0) {
    return (byte)~pcVar2->flags31 >> 2 & 1;
  }
  while( true ) {
    if (pcVar1 == (c2_incr_id_cell *)0x0) {
      return 1;
    }
    if (pcVar1->sym_id == id) break;
    pcVar1 = pcVar1->next;
  }
  return 0;
}

