void sym_emit_deferred(void)

{
  void *pvVar1;
  byte *pbVar2;
  byte bVar3;
  
  while( true ) {
    if (g_deferred_symbols == (void *)0x0) {
      return;
    }
    pvVar1 = *(void **)((int)g_deferred_symbols + 4);
    pbVar2 = *(byte **)g_deferred_symbols;
    if (pbVar2 == (byte *)0x0) break;
    bVar3 = *pbVar2 & 0x1f;
    g_deferred_symbols = pvVar1;
    if ((((bVar3 == 7) || (bVar3 == 8)) || (bVar3 == 6)) &&
       (*(fe_function_record **)(pbVar2 + 0x28) != (fe_function_record *)0x0)) {
      func_emit_definition_record(*(fe_function_record **)(pbVar2 + 0x28));
      tu_defer_symbols_in_list(*(c1_symbol_cell **)(*(int *)(pbVar2 + 0x28) + 0x14));
    }
    else {
      il_emit_global_symbol((int *)(pbVar2 + 8));
      if (((*pbVar2 & 0x1f) == 10) && (*(c1_symbol_cell **)(pbVar2 + 0x2c) != (c1_symbol_cell *)0x0)
         ) {
        tu_defer_symbols_in_list(*(c1_symbol_cell **)(pbVar2 + 0x2c));
      }
    }
  }
  g_deferred_symbols = pvVar1;
  return;
}

