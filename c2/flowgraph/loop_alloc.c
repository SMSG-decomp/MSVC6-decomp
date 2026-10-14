void * loop_alloc(void)

{
  void *pvVar1;
  
  pvVar1 = arena_alloc(0xc,0x40);
  return pvVar1;
}

