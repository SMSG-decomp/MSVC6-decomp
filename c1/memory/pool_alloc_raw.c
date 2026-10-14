c1_u8 * __thiscall pool_alloc_raw(fe_pool *pool,uint n)

{
  c1_u8 *pcVar1;
  
  if (pool->left < n) {
    pool_reserve(pool,n);
  }
  pcVar1 = pool->cur;
  pool->cur = pcVar1 + n;
  pool->left = pool->left - n;
  return pcVar1;
}

