void __cdecl arenas_init_all_fragment(fe_arena *arena,void *descriptor)

{
  byte *pbVar1;
  byte bVar2;
  void *descriptor_00;
  
  do {
    do {
      descriptor_00 = (void *)((int)descriptor + 0x14);
      arena = arena + 1;
      if (0x10654063 < (int)descriptor_00) {
        pools_init_all();
        return;
      }
      pbVar1 = (byte *)((int)descriptor + 0x20);
      descriptor = descriptor_00;
    } while ((*pbVar1 & 1) != 0);
    bVar2 = arena_reserve(arena,descriptor_00,(void *)0x0);
  } while (bVar2 != 0);
  mem_alloc_or_fatal_6();
  return;
}

