byte __cdecl pch_reload_arenas(char *file_name,uint offset)

{
  byte bVar1;
  
  arenas_free_flagged();
  pch_image_index_read(&g_pch_image,file_name,offset);
  bVar1 = pch_image_map_segments(&g_pch_image);
  arenas_init();
  return bVar1;
}

