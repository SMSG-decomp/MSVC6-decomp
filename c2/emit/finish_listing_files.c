void finish_listing_files(void)

{
  int iVar1;
  c2_listing_source_file **ppcVar2;
  
  if (g_listing_on != 0) {
    asm_print_listing_end();
    if ((g_opt_listing_source != 0) && (iVar1 = 0, 0 < g_listing_open_source_count)) {
      ppcVar2 = g_listing_open_sources;
      do {
        fclose((*ppcVar2)->fp);
        iVar1 = iVar1 + 1;
        ppcVar2 = ppcVar2 + 1;
      } while (iVar1 < g_listing_open_source_count);
    }
    g_listing_unfinished = 0;
  }
  return;
}

