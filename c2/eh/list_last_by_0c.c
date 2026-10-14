void * __fastcall list_last_by_0c(void *p)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  for (; p != (void *)0x0; p = *(void **)((int)p + 0xc)) {
    pvVar1 = p;
  }
  return pvVar1;
}

