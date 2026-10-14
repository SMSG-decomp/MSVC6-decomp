void __cdecl il_emitter_select(char keep)

{
  char cVar1;
  
  g_il_emitter = il_emitter_get_preferred();
  if (((keep == '\0') && (g_auto_pch_using == 0)) &&
     (cVar1 = (*g_il_emitter->vtbl->reopen)(g_il_emitter), cVar1 != '\0')) {
    g_il_emitter = il_emitter_get_default();
  }
  else {
    (*g_il_emitter->vtbl->open)(g_il_emitter);
    if ((g_pch_header.browse_size != 0) && ((g_pch_automatic != '\0' || (g_auto_pch_using != 0)))) {
      if (g_file_copy_buffer == (void *)0x0) {
        g_file_copy_buffer = mem_xmalloc(0x8000);
      }
      file_copy_contents(g_pch_file,g_browse_sbr_file,g_pch_header.browse_size);
    }
  }
  if (g_file_copy_buffer != (void *)0x0) {
    mem_free(g_file_copy_buffer);
  }
  return;
}

