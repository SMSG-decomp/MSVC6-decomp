int __fastcall scope_contains_id(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  pcVar1 = g_cur_scope->buckets[id & 0x3ff];
  while( true ) {
    if (pcVar1 == (c2_fe_symbol *)0x0) {
      return 0;
    }
    if (pcVar1->id == id) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

