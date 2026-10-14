void * __fastcall seh_hash_lookup(void **table,uint32_t key)

{
  int *piVar1;
  
  piVar1 = table[key & 0xf];
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (void *)0x0;
    }
    if (*(uint32_t *)(*piVar1 + 0x1c) == key) break;
    piVar1 = (int *)piVar1[1];
  }
  return (void *)*piVar1;
}

