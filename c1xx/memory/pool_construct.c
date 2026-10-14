void __thiscall pool_construct(c1xx_pool *pool,c1_u32 min_pages)

{
  pool->cur = (c1_u8 *)0x0;
  pool->left = 0;
  pool->min_pages = min_pages;
  pool->arena = (c1_arena *)0x0;
  return;
}

