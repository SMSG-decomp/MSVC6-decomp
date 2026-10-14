void arenas_free_all(void)

{
  fe_arena *a;
  
  pch_image_close(&g_pch_image);
  a = g_arenas;
  do {
    arena_release(a);
    a = a + 1;
  } while ((int)a < 0x1066daf4);
  return;
}

