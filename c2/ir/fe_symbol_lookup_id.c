c2_fe_symbol * __fastcall fe_symbol_lookup_id(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  if (id != 0) {
    for (pcVar1 = g_global_scope.buckets[id & 0x3ff]; pcVar1 != (c2_fe_symbol *)0x0;
        pcVar1 = pcVar1->next) {
      if (pcVar1->id == id) {
        return pcVar1;
      }
    }
    if (g_cur_scope != (c2_scope_table *)0x0) {
      for (pcVar1 = g_cur_scope->buckets[id & 0x3ff]; pcVar1 != (c2_fe_symbol *)0x0;
          pcVar1 = pcVar1->next) {
        if (pcVar1->id == id) {
          return pcVar1;
        }
      }
    }
  }
  return (c2_fe_symbol *)0x0;
}

