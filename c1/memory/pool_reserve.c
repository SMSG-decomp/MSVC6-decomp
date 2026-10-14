void __thiscall pool_reserve(fe_pool *pool,int bytes)

{
  uint pages;
  c1_u8 *pcVar1;
  
  pages = (bytes - 1U) / g_system_info.dwPageSize + 1;
  if (pages < pool->min_pages) {
    pages = pool->min_pages;
  }
  pcVar1 = pool_commit_pages(pool->arena,pages,(int *)&pool->left);
  pool->cur = pcVar1;
  return;
}

