void __thiscall pool_reserve(c1xx_pool *pool,uint n)

{
  uint npages;
  c1_u8 *pcVar1;
  
  npages = (n - 1) / g_system_info.dwPageSize + 1;
  if (npages < pool->min_pages) {
    npages = pool->min_pages;
  }
  pcVar1 = pool_commit_pages(pool->arena,npages,&pool->left);
  pool->cur = pcVar1;
  return;
}

