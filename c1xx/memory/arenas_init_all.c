void __cdecl arenas_init_all(void)

{
  byte bVar1;
  byte *descriptor;
  c1_arena *a;
  
  arenas_init();
  a = g_arenas;
  descriptor = &g_arena_descriptors;
  do {
    if ((((c1_arena_desc *)descriptor)->flags & 1) == 0) {
      bVar1 = arena_reserve(a,(c1_arena_desc *)descriptor,(void *)0x0);
      if (bVar1 == 0) {
        mem_alloc_or_fatal_6();
        return;
      }
    }
    descriptor = (byte *)((int)descriptor + 0x14);
    a = a + 1;
  } while ((int)descriptor < 0x104c4d18);
  pools_init_all();
  return;
}

