c1_u8 * __thiscall pool_alloc_raw(void *pool,uint n)

{
  c1_u8 *pcVar1;
  
  if (*(uint *)((int)pool + 4) < n) {
    pool_reserve(pool,n);
  }
  pcVar1 = *(c1_u8 **)pool;
  *(c1_u8 **)pool = pcVar1 + n;
  *(uint *)((int)pool + 4) = *(int *)((int)pool + 4) - n;
  return pcVar1;
}

