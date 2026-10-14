void __cdecl arenas_init(void)

{
  byte bVar1;
  byte *descriptor;
  c1_arena *a;
  
  a = g_arenas;
  descriptor = &g_arena_descriptors;
  do {
    if ((((c1_arena_desc *)descriptor)->flags & 1) != 0) {
      bVar1 = arena_reserve(a,(c1_arena_desc *)descriptor,(void *)0x0);
      if (bVar1 == 0) {
        arenas_init_fatal_fragment(a,descriptor);
        return;
      }
    }
    descriptor = (byte *)((int)descriptor + 0x14);
    a = a + 1;
  } while ((int)descriptor < 0x104c4d18);
  return;
}

