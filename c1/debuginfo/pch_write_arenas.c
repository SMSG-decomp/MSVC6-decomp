void __cdecl pch_write_arenas(char *file,int offset)

{
  byte *pbVar1;
  int n;
  fe_arena *a;
  c1_pch_image local_44;
  
  pch_arena_writer_clear(&local_44);
  n = 0;
  pbVar1 = &g_arena_pch_flags;
  do {
    if ((*pbVar1 & 1) != 0) {
      n = n + 1;
    }
    pbVar1 = pbVar1 + 0x14;
  } while ((int)pbVar1 < 0x10654070);
  if (g_pch_image.file_name == (char *)0x0) {
    pch_image_init(&local_44,n);
  }
  else {
    pch_image_init_from_loaded(&local_44,&g_pch_image,n);
  }
  a = g_arenas;
  pbVar1 = &g_arena_pch_flags;
  do {
    if ((*pbVar1 & 1) != 0) {
      pch_arena_record_append(&local_44,a);
    }
    pbVar1 = pbVar1 + 0x14;
    a = a + 1;
  } while ((int)pbVar1 < 0x10654070);
  pch_heap_write_parts(&local_44,file,offset);
  return;
}

