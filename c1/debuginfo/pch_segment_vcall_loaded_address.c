void * __fastcall pch_segment_vcall_loaded_address(c1_pch_segment *seg)

{
  void *pvVar1;
  
  pvVar1 = (*seg->vtbl->pch_segment_loaded_address)(seg);
  return pvVar1;
}

