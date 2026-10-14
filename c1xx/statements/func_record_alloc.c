void __cdecl func_record_alloc(c1_symbol *sym)

{
  c1xx_function_record *pcVar1;
  byte *pbVar2;
  c1_function_record_block *pcVar3;
  
  if (((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) && (sym != (c1_symbol *)0x0)) {
    g_function_record_index = (g_function_record_index + 1U) % 0x14;
    if (g_function_record_index == 0) {
      if (g_function_record_pool_left < 0x2d4) {
        pool_reserve((c1xx_pool *)&g_function_record_pool,0x2d4);
      }
      pcVar3 = (c1_function_record_block *)g_function_record_pool;
      g_function_record_pool_left = g_function_record_pool_left - 0x2d4;
      if (g_function_record_first_block == (c1_function_record_block *)0x0) {
        g_function_record_block = (c1_function_record_block *)g_function_record_pool;
        g_function_record_first_block = pcVar3;
        g_function_record_pool = g_function_record_pool + 0x2d4;
      }
      else {
        pbVar2 = g_function_record_pool + 0x2d4;
        g_function_record_block->next = (c1_function_record_block *)g_function_record_pool;
        g_function_record_pool = pbVar2;
        g_function_record_block = pcVar3;
      }
    }
    pcVar1 = g_function_record_block->records + g_function_record_index;
    (sym->tail).fn.record = pcVar1;
    pcVar1->unk14 = 0;
  }
  return;
}

