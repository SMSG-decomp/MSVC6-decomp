void __cdecl arenas_init_all(void)

{
  byte bVar1;
  undefined *descriptor;
  fe_arena *a;
  
  arenas_init();
  a = g_arenas;
  descriptor = &g_arena_descriptors;
  do {
    if ((descriptor[0xc] & 1) == 0) {
      bVar1 = arena_reserve(a,descriptor,(void *)0x0);
      if (bVar1 == 0) {
        mem_alloc_or_fatal_6();
        return;
      }
    }
    descriptor = descriptor + 0x14;
    a = a + 1;
  } while ((int)descriptor < 0x10654064);
  pools_init_all();
  return;
}

