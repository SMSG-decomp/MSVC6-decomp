void * __cdecl mem_xrealloc(void *p,uint n)

{
  void *pvVar1;
  
  pvVar1 = realloc(p,n);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
  diag_fatal_simple(0x3c);
}

