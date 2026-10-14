c2_fe_symbol * __fastcall find_float_constant_pool_entry(c2_float_const *value,uint32_t size)

{
  c2_float_const_pool_entry *pcVar1;
  int iVar2;
  
  pcVar1 = g_float_const_pool;
  while( true ) {
    if (pcVar1 == (c2_float_const_pool_entry *)0x0) {
      return (c2_fe_symbol *)0x0;
    }
    if ((size == pcVar1->size) &&
       (iVar2 = float_const_compare_mask(1,value,pcVar1->value), iVar2 != 0)) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1->sym;
}

