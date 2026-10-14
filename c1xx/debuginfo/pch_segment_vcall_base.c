void * __fastcall pch_segment_vcall_base(c1xx_pch_stream_reader *seg)

{
  void *pvVar1;
  
  pvVar1 = (*seg->vtbl->pch_segment_base)(seg);
  return pvVar1;
}

