void __thiscall pool_construct(fe_pool *pool,int min_pages)

{
  pool->cur = (uchar *)0x0;
  pool->left = 0;
  pool->min_pages = min_pages;
  pool->arena = (fe_arena *)0x0;
  return;
}

