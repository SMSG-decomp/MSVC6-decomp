void __cdecl func_record_alloc(c1_symbol *sym)

{
  fe_function_record *pfVar1;
  byte *pbVar2;
  fe_function_record_block *pfVar3;
  fe_function_record_block *pfVar4;
  byte *pbVar5;
  
  if (((g_opt_E_preprocess == 0) && (g_opt_Zg == '\0')) && (sym != (c1_symbol *)0x0)) {
    g_function_record_index = (g_function_record_index + 1U) % 0x14;
    pfVar3 = g_function_record_first_block;
    pfVar4 = g_function_record_block;
    pbVar5 = g_function_record_pool;
    if (g_function_record_index == 0) {
      if ((uint)g_function_record_pool_left < 0x2d4) {
        pool_reserve((fe_pool *)&g_function_record_pool,0x2d4);
      }
      pbVar2 = g_function_record_pool;
      g_function_record_pool_left = g_function_record_pool_left + -0x2d4;
      pfVar3 = (fe_function_record_block *)g_function_record_pool;
      pfVar4 = (fe_function_record_block *)g_function_record_pool;
      pbVar5 = g_function_record_pool + 0x2d4;
      if (g_function_record_first_block != (fe_function_record_block *)0x0) {
        g_function_record_block->next = (fe_function_record_block *)g_function_record_pool;
        g_function_record_pool = pbVar5;
        g_function_record_block = (fe_function_record_block *)pbVar2;
        pfVar3 = g_function_record_first_block;
        pfVar4 = g_function_record_block;
        pbVar5 = g_function_record_pool;
      }
    }
    g_function_record_pool = pbVar5;
    g_function_record_block = pfVar4;
    g_function_record_first_block = pfVar3;
    pfVar1 = g_function_record_block->records + g_function_record_index;
    (sym->x28).function = pfVar1;
    pfVar1->references = (void *)0x0;
  }
  return;
}

