void arenas_init_all_fragment(c1_arena *a,c1_arena_desc *esi)

{
  c1_arena_desc *pcVar1;
  byte bVar2;
  c1_arena_desc *descriptor;
  
  do {
    do {
      descriptor = esi + 1;
      a = a + 1;
      if (0x104c4d17 < (int)descriptor) {
        pools_init_all();
        return;
      }
      pcVar1 = esi + 1;
      esi = descriptor;
    } while ((pcVar1->flags & 1) != 0);
    bVar2 = arena_reserve(a,descriptor,(void *)0x0);
  } while (bVar2 != 0);
  mem_alloc_or_fatal_6();
  return;
}

