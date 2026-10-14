void __cdecl arenas_free_flagged(void)

{
  byte *pbVar1;
  c1_arena *a;
  
  a = g_arenas;
  pbVar1 = &g_arena_pch_flags;
  do {
    if ((*pbVar1 & 1) != 0) {
      arena_release(a);
    }
    pbVar1 = pbVar1 + 0x14;
    a = a + 1;
  } while ((int)pbVar1 < 0x104c4d24);
  if (g_pch_mapping_handle != (HANDLE)0x0) {
    CloseHandle(g_pch_mapping_handle);
    g_pch_mapping_handle = (HANDLE)0x0;
  }
  return;
}

