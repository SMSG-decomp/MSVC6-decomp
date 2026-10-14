void reset_writer_lists(void)

{
  g_coff_pending_chunk = (void *)0x0;
  g_coff_string_table = (c2_coff_data *)0x0;
  g_coff_current_section_data = (c2_coff_data *)0x0;
  g_coff_chunk_free_list = (c2_coff_chunk *)0x0;
  g_coff_reloc_chunk_free_list = (c2_coff_reloc_chunk *)0x0;
  g_coff_lineno_chunk_free_list = (c2_coff_lineno_chunk *)0x0;
  return;
}

