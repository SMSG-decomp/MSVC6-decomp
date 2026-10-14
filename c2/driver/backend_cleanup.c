void __cdecl backend_cleanup(int exit_code)

{
  if (g_backend_cleanup_done == 0) {
    g_backend_cleanup_done = 1;
    if ((g_object_file_open != 0) || (g_error_count != 0)) {
      if (g_object_file != (FILE *)0x0) {
        fclose(g_object_file);
      }
      if (g_opt_object_path != (char *)0x0) {
        remove(g_opt_object_path);
      }
    }
    if (g_listing_unfinished != 0) {
      fclose(g_listing_file);
      remove(g_opt_listing_path);
      arena_free_all();
      return;
    }
    if (g_listing_file != (FILE *)0x0) {
      fclose(g_listing_file);
    }
    arena_free_all();
  }
  return;
}

