void * __fastcall pch_segment_vcall_loaded_address(c1xx_pch_stream_reader *seg)

{
  void *pvVar1;
  
  pvVar1 = (*seg->vtbl->qualname_resolved_symbol)((c1_declarator *)seg);
  return pvVar1;
}

