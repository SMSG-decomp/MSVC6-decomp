void __fastcall pool_clear(fe_pool *pool)

{
  pool->arena = (fe_arena *)0x0;
  pool->left = 0;
  pool->cur = (uchar *)0x0;
  return;
}

