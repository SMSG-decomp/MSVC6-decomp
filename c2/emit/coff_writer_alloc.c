void * __fastcall coff_writer_alloc(uint32_t size)

{
  void *pvVar1;
  
  pvVar1 = arena_alloc(7,size);
  return pvVar1;
}

