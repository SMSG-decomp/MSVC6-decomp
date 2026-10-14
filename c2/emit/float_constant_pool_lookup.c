c2_float_const * __fastcall float_constant_pool_lookup(c2_fe_symbol *sym)

{
  c2_float_const_pool_entry *pcVar1;
  
  pcVar1 = g_float_const_pool;
  while( true ) {
    if (pcVar1 == (c2_float_const_pool_entry *)0x0) {
      return (c2_float_const *)0x0;
    }
    if (sym == pcVar1->sym) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1->value;
}

