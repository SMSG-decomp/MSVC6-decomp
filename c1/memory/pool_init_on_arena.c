void __thiscall pool_init_on_arena(fe_pool *pool,int arena)

{
  pool->arena = g_arenas + arena;
  pool_reserve(pool,1);
  return;
}

