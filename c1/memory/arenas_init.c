void __cdecl arenas_init(void)

{
  byte bVar1;
  undefined *descriptor;
  fe_arena *a;
  
  a = g_arenas;
  descriptor = &g_arena_descriptors;
  do {
    if ((descriptor[0xc] & 1) != 0) {
      bVar1 = arena_reserve(a,descriptor,(void *)0x0);
      if (bVar1 == 0) {
        arenas_init_fatal_fragment(a,descriptor);
        return;
      }
    }
    descriptor = descriptor + 0x14;
    a = a + 1;
  } while ((int)descriptor < 0x10654064);
  return;
}

