void __thiscall pool_init_on_arena(void *pool,int arena)

{
  *(c1_arena **)((int)pool + 0xc) = g_arenas + arena;
  pool_reserve(pool,1);
  return;
}

