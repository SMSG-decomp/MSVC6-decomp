c2_fe_symbol * __fastcall fe_scope_lookup_id(c2_scope_table *scope,uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  if (scope != (c2_scope_table *)0x0) {
    do {
      for (pcVar1 = scope->buckets[id & 0x3ff]; pcVar1 != (c2_fe_symbol *)0x0; pcVar1 = pcVar1->next
          ) {
        if (pcVar1->id == id) {
          return pcVar1;
        }
      }
      scope = scope->parent;
    } while (scope != (c2_scope_table *)0x0);
  }
  return (c2_fe_symbol *)0x0;
}

