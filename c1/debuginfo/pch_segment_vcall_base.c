void * __fastcall pch_segment_vcall_base(c1_pch_segment *seg)

{
  void *pvVar1;
  
  pvVar1 = (*seg->vtbl->pch_segment_base)(seg);
  return pvVar1;
}

