void __cdecl pch_write_arenas(char *file_name,int offset)

{
  byte *pbVar1;
  int extra;
  c1_arena *a;
  int writer [17];
  
  pch_arena_writer_clear(writer);
  extra = 0;
  pbVar1 = &g_arena_pch_flags;
  do {
    if ((*pbVar1 & 1) != 0) {
      extra = extra + 1;
    }
    pbVar1 = pbVar1 + 0x14;
  } while ((int)pbVar1 < 0x104c4d24);
  if (g_pch_image.file_name == (char *)0x0) {
    pch_image_init((c1xx_pch_image *)writer,extra);
  }
  else {
    pch_image_init_from_loaded((c1xx_pch_image *)writer,&g_pch_image,extra);
  }
  a = g_arenas;
  pbVar1 = &g_arena_pch_flags;
  do {
    if ((*pbVar1 & 1) != 0) {
      pch_arena_record_append(writer,a);
    }
    pbVar1 = pbVar1 + 0x14;
    a = a + 1;
  } while ((int)pbVar1 < 0x104c4d24);
  pch_heap_write_parts((c1xx_pch_image *)writer,file_name,offset);
  return;
}

